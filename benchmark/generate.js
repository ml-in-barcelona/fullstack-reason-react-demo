
const renderLink = () => {
  return `function Link(props) {
    return React.createElement(
      "a",
      {
        className: "text-blue-500 hover:text-blue-800",
        href: props.url,
        onClick: function (e) {
          e.preventDefault();
          console.log(e);
        },
      },
      props.txt
    );
  }`
};

const FileHeader = `const React = require("react");`

const layout = `function layout () {
  React.createElement("html", null, React.createElement("head", null," ", React.createElement("title", null, " ", "SSR React", " "), " "),
  React.createElement("body", null, React.createElement("div", { id: "root", }, React.createElement(app, null)), React.createElement("script", { src: "/static/client.js" })))};

export default layout;
`

const range = (num, value) =>
  Array.from({ length: num }).fill(value);

const generateApp = (c_number = 10) => {
  const children = `React.createElement(Link, { key: "", url: "https://random.url", txt: "Visit random" })`;
  const childrens = range(c_number, children).toString();
  const menu = `React.createElement("ul", {}, [${childrens}])`;
  const page = `function app() { return ${menu} }`;
  return page
}

const number_of_components = process.argv[2];

const contents = renderLink() + "\n\n" + generateApp(number_of_components) + "\n\n" + layout;
console.log(page)
