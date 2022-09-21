let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([
    Dream.get("/", (_ => Dream.html(ReactDOM.renderToStaticMarkup(<Shared.App />)))),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
