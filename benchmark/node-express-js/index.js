const React = require("react");
const ReactDOMServer = require("react-dom/server");
const express = require("express");
const PageWelcome = require("./PageWelcome.js");

function Shared() {
  return React.createElement(PageWelcome.default, {});
}

const page = () =>
  React.createElement(
    "html",
    null,
    React.createElement(
      "head",
      null,
      " ",
      React.createElement("title", null, " ", "SSR React", " "),
      " "
    ),
    React.createElement(
      "body",
      null,
      React.createElement(
        "div",
        {
          id: "root",
        },
        React.createElement(Shared, null)
      ),
      React.createElement("script", {
        src: "/static/client.js",
      })
    )
  );

const app = express();

app.get("/", (_req, res) => {
  return res.send(
    `<div id="root">${ReactDOMServer.renderToStaticMarkup(
      React.createElement(page, null)
    )}</div>`
  );
});

const PORT = 1337;

app.listen(PORT, () => {
  console.log(`Server is listening on port ${PORT}`);
});
