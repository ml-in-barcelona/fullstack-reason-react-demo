const Path = require("path");

module.exports = (env) => ({
  entry: {
    app: "./_build/default/client/app/client/app.js",
    header: "./_build/default/client/header/client/header.js"
  },
  mode: env.production ? "production" : "development",
  output: {
    path: Path.join(__dirname, "static"),
    filename: "[name].js",
  },
  resolve: {
    alias: {
      "@emotion/hash": Path.resolve(__dirname, "_build/default/client/hash/client/", "hash.js"),
    },
  },
});
