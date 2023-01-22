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
      melange: Path.resolve(__dirname, "node_modules", "melange"),
      ["@emotion/hash"]: Path.resolve(__dirname, "client", "hash.js"),
    },
  },
});
