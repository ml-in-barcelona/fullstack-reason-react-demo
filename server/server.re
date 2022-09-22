module Page = {
  [@react.component]
  let make = () => {
    <html>
      <head>
        <title>{React.string("SSR React")}</title>
      </head>
      <body>
        <div id="root">
          <Shared.App><h2>{React.string("server")}</h2></Shared.App>
        </div>
        <script src="/static/client.js" />
      </body>
    </html>
  }
};

let home = ReactDOM.renderToStaticMarkup(<Page />);

let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([
    Dream.get("/", (_ => Dream.html(home))),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
