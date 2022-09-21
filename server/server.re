module App = {
  [@react.component]
  let make = () => {
    <html>
      <head>
        <title>{React.string("SSR React")}</title>
      </head>
      <body>
        <div>
          <h1> {React.string(Shared.greet(`Server))} </h1>
        </div>
        <script src="/static/client.js" />
      </body>
    </html>
  }
};

let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([
    Dream.get("/", (_ => Dream.html(ReactDOM.renderToStaticMarkup(<App />)))),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
