var React = require("react");
var Link = require("./Link.js");
var PageContainer = require("./PageContainer.js");

function PageWelcome() {
  return React.createElement(PageContainer.make, {
    children: React.createElement(
      React.Fragment,
      undefined,
      React.createElement(
        "h1",
        {
          className: "font-semibold text-xl tracking-tight mb-8",
        },
        "OCaml native webapp with SSR + React hydration"
      ),
      React.createElement("h2", undefined, "Hello"),
      React.createElement(
        "ul",
        {
          className: "list-disc list-inside mb-8",
        },
        [
          React.createElement(Link.make, {
            url: "/hello",
            txt: "hiya",
          }),
          React.createElement(Link.make, {
            url: "/hello/中文",
            txt: "中文",
          }),
          React.createElement(Link.make, {
            url: "/hello/Deutsch",
            txt: "Deutsch",
          }),
          React.createElement(Link.make, {
            url: "/hello/English",
            txt: "English",
          }),
        ].map((x, index) => React.createElement("li", { id: index + "" }, x))
      ),
      React.createElement("h2", undefined, "Excerpts"),
      React.createElement(
        "ul",
        {
          className: "list-disc list-inside mb-8",
        },
        $$Array.of_list(
          List.mapi(
            function (_i, x) {
              return React.createElement(
                "li",
                {
                  key: String(_i),
                },
                x
              );
            },
            {
              hd: React.createElement(Link.make, {
                url: "/excerpts/add",
                txt: "Add Excerpt",
              }),
              tl: {
                hd: React.createElement(Link.make, {
                  url: "???",
                  txt: "Authors with excerpts",
                }),
                tl: 0,
              },
            }
          )
        )
      ),
      React.createElement("h2", undefined, "Other examples"),
      React.createElement(
        "ul",
        {
          className: "list-disc list-inside mb-8",
        },
        React.createElement(
          React.Fragment,
          undefined,
          React.createElement(
            "li",
            undefined,
            React.createElement(Link.make, {
              url: "counter!:",
              txt: "Counter",
            })
          )
        )
      )
    ),
  });
}

exports.default = PageWelcome;
