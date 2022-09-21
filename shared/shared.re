module App = {
  [@react.component]
  let make = () => {
    <html>
      <head>
        <title>{React.string("SSR React")}</title>
      </head>
      <body>
        <div>
          <h1> {React.string("HW")} </h1>
        </div>
        <script src="/static/client.js" />
      </body>
    </html>
  }
};
