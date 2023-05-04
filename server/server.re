let globalStyles = {js|
  html, body, #root {
    margin: 0;
    padding: 0;
    width: 100vw;
    height: 100vh;
  }

  * {
    font-family: -apple-system, BlinkMacSystemFont, Roboto, Helvetica, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }
|js};

module Page = {
  [@react.component]
  let make = (~children, ~src) => {
    <html>
      <head>
        <meta charSet="UTF-8" />
        <meta
          name="viewport"
          content="width=device-width, initial-scale=1.0"
        />
        <title> {React.string("Server Reason React demo")} </title>
        <link
          rel="shortcut icon"
          href="https://reasonml.github.io/img/icon_50.png"
        />
        <style
          type_="text/css"
          dangerouslySetInnerHTML={"__html": globalStyles}
        />
        <style
          type_="text/css"
          dangerouslySetInnerHTML={"__html": Css.render_style_tag()}
        />
      </head>
      <body> <div id="root"> children </div> <script src /> </body>
    </html>;
  };
};

let handler =
  Dream.router([
    Dream.get("/", _request =>
      Dream.html(
        ReactDOM.renderToString(
          <Page src="/static/app.js"> <Shared_native.App /> </Page>,
        ),
      )
    ),
    Dream.get("/header", _request =>
      Dream.html(
        ReactDOM.renderToString(
          <Page src="/static/header.js"> <Shared_native.Ahrefs /> </Page>,
        ),
      )
    ),
    Dream.get("/static/**", Dream.static("./static")),
  ]);

let interface =
  switch (Sys.getenv_opt("SERVER_INTERFACE")) {
  | Some(env) => env
  | None => "localhost"
  };

Dream.run(~port=8080, ~interface, handler);
