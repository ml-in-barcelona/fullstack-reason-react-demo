module Page = {
  [@react.component]
  let make = () => {
    <html>
      <head> <title> {React.string("SSR React")} </title>
      <style>{Emotion.render_style_tag() |> React.string}</style></head>
      <body>
        <div id="root">
          <Shared.App />
        </div>
        <script src="/static/client.js" />
      </body>
    </html>;
  };
};

let home = ReactDOM.renderToStaticMarkup(<Page />);

let () =
  Dream.run(~port=4444) @@
  Dream.router([
    Dream.get("/", _ => Dream.html(home)),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
