let globalStyles = {j|
  html, body, #root {
    margin: 0;
    padding: 0;
    width: 100vw;
    height: 100vh;
    background-color: #292a2d;
  }

  * {
    font-family: -apple-system, BlinkMacSystemFont, Roboto, Helvetica, Arial, sans-serif;
  }
|j};

module Page = {
  [@react.component]
  let make = () => {
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
      <body>
        <div id="root"> <Shared_native.App /> </div>
        <script src="/static/main.js" />
      </body>
    </html>;
  };
};

let home = ReactDOM.renderToString(<Page />);

let handler =
  Dream.router([
    Dream.get("/", _request => Dream.html(home)),
    Dream.get("/static/**", Dream.static("./static")),
  ]);

Dream.run(~port=8080, handler);
