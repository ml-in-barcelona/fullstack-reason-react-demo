[@warning "-32"] [@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@warning "-32"] [@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";

type error = {.};

[@deriving abstract]
type options = {
  [@bs.optional]
  bootstrapScriptContent: string,
  [@bs.optional]
  bootstrapScripts: array(string),
  [@bs.optional]
  bootstrapModules: array(string),
  [@bs.optional]
  identifierPrefix: string,
  [@bs.optional]
  namespaceURI: string,
  [@bs.optional]
  nonce: string,
  [@bs.optional]
  onAllReady: unit => unit,
  [@bs.optional]
  onError: error => unit,
  [@bs.optional]
  onShellReady: unit => unit,
  [@bs.optional]
  onShellError: error => unit,
  [@bs.optional]
  progressiveChunkSize: int,
};

type pipeableStream = {
  /* Using empty object instead of Node.stream since Melange don't provide a binding to node's Stream (https://nodejs.org/api/stream.html) */
  pipe: {.} => unit,
  abort: unit => unit,
};

[@bs.module "react-dom/server"]
external renderToPipeableStream: (React.element, options) => pipeableStream =
  "renderToPipeableStream";

let renderToPipeableStream =
    (
      ~bootstrapScriptContent=?,
      ~bootstrapScripts=?,
      ~bootstrapModules=?,
      ~identifierPrefix=?,
      ~namespaceURI=?,
      ~nonce=?,
      ~onAllReady=?,
      ~onError=?,
      ~onShellReady=?,
      ~onShellError=?,
      ~progressiveChunkSize=?,
      element,
    ) =>
  renderToPipeableStream(
    element,
    options(
      ~bootstrapScriptContent?,
      ~bootstrapScripts?,
      ~bootstrapModules?,
      ~identifierPrefix?,
      ~namespaceURI?,
      ~nonce?,
      ~onAllReady?,
      ~onError?,
      ~onShellReady?,
      ~onShellError?,
      ~progressiveChunkSize?,
      (),
    ),
  );
[@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";
