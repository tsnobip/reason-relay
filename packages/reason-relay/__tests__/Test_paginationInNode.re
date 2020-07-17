module Query = [%relay.query
  {|
    query TestPaginationInNodeQuery($userId: ID!) {
      node(id: $userId) {
        id
        __typename
        ... on User {
          ...TestPaginationInNode_query
        }
      }
    }
|}
];

// This is just to ensure that fragments on unions work
module UserFragment = [%relay.fragment
  {|
  fragment TestPaginationInNode_user on User {
    id
    firstName
    friendsConnection(first: 1) {
      totalCount
    }
  }
|}
];

module Fragment = [%relay.fragment
  {|
    fragment TestPaginationInNode_query on User
      @refetchable(queryName: "TestPaginationInNodeRefetchQuery")
      @argumentDefinitions(
        onlineStatuses: { type: "[OnlineStatus!]" }
        count: { type: "Int", defaultValue: 2 }
        cursor: { type: "String", defaultValue: "" }
      ) {
      friendsConnection(
        statuses: $onlineStatuses
        first: $count
        after: $cursor
      ) @connection(key: "TestPaginationInNode_friendsConnection") {
        edges {
          node {
            id
            ...TestPaginationInNode_user
          }
        }
      }
    }
|}
];

module UserDisplayer = {
  [@react.component]
  let make = (~user) => {
    let data = UserFragment.use(user);

    React.string(
      "User "
      ++ data.firstName
      ++ " has "
      ++ data.friendsConnection.totalCount->string_of_int
      ++ " friends",
    );
  };
};

module UserNodeDisplayer = {
  [@react.component]
  let make = (~queryRef) => {
    let (startTransition, _) =
      React.useTransition(~config={timeoutMs: 5000}, ());

    let ReasonRelay.{data, hasNext, loadNext, isLoadingNext, refetch} =
      Fragment.usePagination(queryRef);

    <div>
      {data.friendsConnection
       ->Fragment.getConnectionNodes_friendsConnection
       ->Belt.Array.map(user =>
           <div key={user.id}>
             <UserDisplayer
               user={user.getFragmentRef_TestPaginationInNode_user()}
             />
           </div>
         )
       ->React.array}
      {hasNext
         ? <button
             onClick={_ => {
               startTransition(() =>
                 loadNext(
                   ~count=2,
                   ~onComplete=
                     fun
                     | Some(e) => Js.Console.error(e)
                     | None => (),
                   (),
                 )
                 |> ignore
               )
             }}>
             {React.string(isLoadingNext ? "Loading..." : "Load more")}
           </button>
         : React.null}
      <button
        onClick={_ =>
          startTransition(() =>
            refetch(
              ~variables=
                Fragment.makeRefetchVariables(
                  ~onlineStatuses=[|`Online, `Idle|],
                  (),
                ),
              (),
            )
          )
        }>
        {React.string("Refetch connection")}
      </button>
    </div>;
  };
};

module Test = {
  [@react.component]
  let make = () => {
    let userId = "123";
    let query = Query.use(~variables={userId: userId}, ());
    switch (query.node) {
    | Some(node) =>
      <UserNodeDisplayer
        queryRef={node.getFragmentRef_TestPaginationInNode_query()}
      />
    | None => React.string("-")
    };
  };
};

let test_pagination = () => {
  let network =
    ReasonRelay.Network.makePromiseBased(
      ~fetchFunction=RelayEnv.fetchQuery,
      (),
    );

  let environment =
    ReasonRelay.Environment.make(
      ~network,
      ~store=
        ReasonRelay.Store.make(~source=ReasonRelay.RecordSource.make(), ()),
      (),
    );
  ();

  <TestProviders.Wrapper environment> <Test /> </TestProviders.Wrapper>;
};
