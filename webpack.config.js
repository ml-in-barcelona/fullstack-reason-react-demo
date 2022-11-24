const Path = require("path");
const outputDir = Path.join(__dirname, "static");

module.exports = (env) => ({
  entry: "./_build/default/client/client/client/client.js",
  mode: env.production ? "production" : "development",
  output: {
    path: outputDir,
    filename: "main.js",
  },
});
