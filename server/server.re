let asdf = React.createElement("html", [||], [
  React.createElement("head", [||], []),
  React.createElement("body", [||], [
    React.createElement("p", [||], [React.string(Shared.greet(`Server))]),
    React.createElement("script", [|React.Attribute.String(("src", "/static/client.js"))|], []),
  ]),
]);

let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([
    Dream.get("/", (_ => Dream.html(ReactDOM.renderToStaticMarkup(asdf)))),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
