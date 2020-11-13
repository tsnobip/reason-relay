/* @generated */

module Types = {
  type enum_OnlineStatus = pri [> | `Idle | `Offline | `Online];

  [@ocaml.warning "-30"];
  type response_setOnlineStatus = {
    user: option(response_setOnlineStatus_user),
  }
  and response_setOnlineStatus_user = ReasonRelay.allFieldsMasked
  and rawResponse_setOnlineStatus = {
    user: option(rawResponse_setOnlineStatus_user),
  }
  and rawResponse_setOnlineStatus_user = {
    id: string,
    firstName: string,
    lastName: string,
    onlineStatus: option(enum_OnlineStatus),
  };

  type response = {setOnlineStatus: option(response_setOnlineStatus)};
  type rawResponse = {setOnlineStatus: option(rawResponse_setOnlineStatus)};
  type variables;
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"setOnlineStatus":{"n":""},"setOnlineStatus_user":{"n":"","f":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay.convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"setOnlineStatus":{"n":""},"setOnlineStatus_user":{"n":"","f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay.convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type wrapRawResponseRaw;
  let wrapRawResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"setOnlineStatus":{"n":""},"setOnlineStatus_user":{"n":""},"setOnlineStatus_user_onlineStatus":{"n":""}}} |json}
  ];
  let wrapRawResponseConverterMap = ();
  let convertWrapRawResponse = v =>
    v
    ->ReasonRelay.convertObj(
        wrapRawResponseConverter,
        wrapRawResponseConverterMap,
        Js.null,
      );

  type rawResponseRaw;
  let rawResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"setOnlineStatus":{"n":""},"setOnlineStatus_user":{"n":""},"setOnlineStatus_user_onlineStatus":{"n":""}}} |json}
  ];
  let rawResponseConverterMap = ();
  let convertRawResponse = v =>
    v
    ->ReasonRelay.convertObj(
        rawResponseConverter,
        rawResponseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay.convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

module Utils = {
  external onlineStatus_toString: Types.enum_OnlineStatus => string =
    "%identity";
  open Types;
  [@bs.obj]
  external makeVariables: (~onlineStatus: enum_OnlineStatus) => variables = "";

  let make_rawResponse_setOnlineStatus_user =
      (~id, ~firstName, ~lastName, ~onlineStatus=?, ())
      : rawResponse_setOnlineStatus_user => {
    id,
    firstName,
    lastName,
    onlineStatus,
  };

  let make_rawResponse_setOnlineStatus =
      (~user=?, ()): rawResponse_setOnlineStatus => {
    user: user,
  };

  let make_response_setOnlineStatus_user = () => [@ocaml.warning "-27"] {};

  let make_response_setOnlineStatus = (~user=?, ()): response_setOnlineStatus => {
    user: user,
  };

  let makeOptimisticResponse = (~setOnlineStatus=?, ()): rawResponse => {
    setOnlineStatus: setOnlineStatus,
  };
};

type relayOperationNode;

type operationType = ReasonRelay.mutationNode(relayOperationNode);

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "onlineStatus"
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "onlineStatus",
    "variableName": "onlineStatus"
  }
];
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "TestMutationWithOnlyFragmentSetOnlineStatusMutation",
    "selections": [
      {
        "alias": null,
        "args": (v1/*: any*/),
        "concreteType": "SetOnlineStatusPayload",
        "kind": "LinkedField",
        "name": "setOnlineStatus",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "User",
            "kind": "LinkedField",
            "name": "user",
            "plural": false,
            "selections": [
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "TestMutation_user"
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ],
    "type": "Mutation",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Operation",
    "name": "TestMutationWithOnlyFragmentSetOnlineStatusMutation",
    "selections": [
      {
        "alias": null,
        "args": (v1/*: any*/),
        "concreteType": "SetOnlineStatusPayload",
        "kind": "LinkedField",
        "name": "setOnlineStatus",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "User",
            "kind": "LinkedField",
            "name": "user",
            "plural": false,
            "selections": [
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "id",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "firstName",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "lastName",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "onlineStatus",
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "b6a21c829becb6c4d26cd0efc3bba80d",
    "id": null,
    "metadata": {},
    "name": "TestMutationWithOnlyFragmentSetOnlineStatusMutation",
    "operationKind": "mutation",
    "text": "mutation TestMutationWithOnlyFragmentSetOnlineStatusMutation(\n  $onlineStatus: OnlineStatus!\n) {\n  setOnlineStatus(onlineStatus: $onlineStatus) {\n    user {\n      ...TestMutation_user\n      id\n    }\n  }\n}\n\nfragment TestMutation_user on User {\n  id\n  firstName\n  lastName\n  onlineStatus\n}\n"
  }
};
})() |json}
];
