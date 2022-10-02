const React = require("react");
const ReactDOMServer = require("react-dom/server");
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

export default {
  port: 7007,
  fetch() {
    return new Response(
      `<div id="root">${ReactDOMServer.renderToString(
        React.createElement(page, null)
      )}</div>`
    );
  },
};
