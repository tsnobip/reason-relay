/* @generated */

type enum_OnlineStatus = [
  | `Idle
  | `Offline
  | `Online
  | `FutureAddedValue(string)
];

let unwrap_enum_OnlineStatus: string => enum_OnlineStatus =
  fun
  | "Idle" => `Idle
  | "Offline" => `Offline
  | "Online" => `Online
  | v => `FutureAddedValue(v);

let wrap_enum_OnlineStatus: enum_OnlineStatus => string =
  fun
  | `Idle => "Idle"
  | `Offline => "Offline"
  | `Online => "Online"
  | `FutureAddedValue(v) => v;

module Types = {
  type response_node = {
    getFragmentRef_TestRefetchingInNode_user:
      unit => TestRefetchingInNode_user_graphql.t,
  };

  type response = {node: option(response_node)};
  type refetchVariables = {
    showOnlineStatus: option(bool),
    friendsOnlineStatuses:
      option(
        array([ | `Idle | `Offline | `Online | `FutureAddedValue(string)]),
      ),
    id: option(string),
  };
  let makeRefetchVariables =
      (~showOnlineStatus=?, ~friendsOnlineStatuses=?, ~id=?, ())
      : refetchVariables => {
    showOnlineStatus,
    friendsOnlineStatuses,
    id,
  };
  type variables = {
    showOnlineStatus: bool,
    friendsOnlineStatuses:
      array([ | `Idle | `Offline | `Online | `FutureAddedValue(string)]),
    id: string,
  };
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"node":{"n":"","f":"TestRefetchingInNode_user"}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"friendsOnlineStatuses":{"e":"enum_OnlineStatus"}}} |json}
  ];
  let variablesConverterMap = {"enum_OnlineStatus": wrap_enum_OnlineStatus};
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type preloadToken;

module Utils = {
  open Types;
  let makeVariables =
      (~showOnlineStatus, ~friendsOnlineStatuses, ~id): variables => {
    showOnlineStatus,
    friendsOnlineStatuses,
    id,
  };
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": false,
    "kind": "LocalArgument",
    "name": "showOnlineStatus",
    "type": "Boolean!"
  },
  {
    "defaultValue": [
      "Online",
      "Offline"
    ],
    "kind": "LocalArgument",
    "name": "friendsOnlineStatuses",
    "type": "[OnlineStatus!]!"
  },
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "id",
    "type": "ID!"
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "id",
    "variableName": "id"
  }
];
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "TestRefetchingInNodeRefetchQuery",
    "selections": [
      {
        "alias": null,
        "args": (v1/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          {
            "args": [
              {
                "kind": "Variable",
                "name": "friendsOnlineStatuses",
                "variableName": "friendsOnlineStatuses"
              },
              {
                "kind": "Variable",
                "name": "showOnlineStatus",
                "variableName": "showOnlineStatus"
              }
            ],
            "kind": "FragmentSpread",
            "name": "TestRefetchingInNode_user"
          }
        ],
        "storageKey": null
      }
    ],
    "type": "Query"
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Operation",
    "name": "TestRefetchingInNodeRefetchQuery",
    "selections": [
      {
        "alias": null,
        "args": (v1/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "__typename",
            "storageKey": null
          },
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "id",
            "storageKey": null
          },
          {
            "kind": "InlineFragment",
            "selections": [
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "firstName",
                "storageKey": null
              },
              {
                "alias": null,
                "args": [
                  {
                    "kind": "Variable",
                    "name": "statuses",
                    "variableName": "friendsOnlineStatuses"
                  }
                ],
                "concreteType": "UserConnection",
                "kind": "LinkedField",
                "name": "friendsConnection",
                "plural": false,
                "selections": [
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "totalCount",
                    "storageKey": null
                  }
                ],
                "storageKey": null
              },
              {
                "condition": "showOnlineStatus",
                "kind": "Condition",
                "passingValue": true,
                "selections": [
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "onlineStatus",
                    "storageKey": null
                  }
                ]
              }
            ],
            "type": "User"
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "id": null,
    "metadata": {
      "derivedFrom": "TestRefetchingInNode_user",
      "isRefetchableQuery": true
    },
    "name": "TestRefetchingInNodeRefetchQuery",
    "operationKind": "query",
    "text": "query TestRefetchingInNodeRefetchQuery(\n  $showOnlineStatus: Boolean! = false\n  $friendsOnlineStatuses: [OnlineStatus!]! = [Online, Offline]\n  $id: ID!\n) {\n  node(id: $id) {\n    __typename\n    ...TestRefetchingInNode_user_lLXHd\n    id\n  }\n}\n\nfragment TestRefetchingInNode_user_lLXHd on User {\n  firstName\n  onlineStatus @include(if: $showOnlineStatus)\n  friendsConnection(statuses: $friendsOnlineStatuses) {\n    totalCount\n  }\n  id\n}\n"
  }
};
})() |json}
];

include ReasonRelay.MakePreloadQuery({
  type variables = Types.variables;
  type queryPreloadToken = preloadToken;
  type response = Types.response;
  let query = node;
  let convertVariables = Internal.convertVariables;
});
