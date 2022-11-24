module Page = {
  [@react.component]
  let make = () => {
    <html>
      <head>
        <title> {React.string("SSR React")} </title>
        <style> {Css.render_style_tag() |> React.string} </style>
      </head>
      <body>
        <div id="root"> <Shared_native.App /> </div>
        <script src="/static/main.js" />
      </body>
    </html>;
  };
};

let home: string = ReactDOM.renderToString(<Page />);

let () =
  Dream.run(~port=4444) @@
  Dream.router([
    Dream.get("/", _request => Dream.html(home)),
    Dream.get("/static/**", Dream.static("./static")),
  ]);
