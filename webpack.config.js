const Path = require("path");

module.exports = (env) => ({
  entry: ["./_build/default/client/app/client/app.js",
  "./_build/default/client/header/client/header.js"],
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
