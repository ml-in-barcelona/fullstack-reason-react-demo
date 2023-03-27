const Path = require("path");

module.exports = (env) => ({
  entry: "./_build/default/client/client/client/client.js",
  mode: env.production ? "production" : "development",
  output: {
    path: Path.join(__dirname, "static"),
    filename: "main.js",
  },
  resolve: {
    alias: {
      "@emotion/hash": Path.resolve(__dirname, "_build/default/client/hash/client/", "hash.js"),
    },
  },
});
