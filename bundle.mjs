import Esbuild from "esbuild";
import * as FS from "fs/promises";
import { commonjs } from "@hyrious/esbuild-plugin-commonjs";

const readPackageJson = () => FS.readFile("./package.json", "utf-8");

const getDependencies = () =>
  readPackageJson().then((packageJson) => {
    const { dependencies } = JSON.parse(packageJson);
    return Object.keys(dependencies);
  });

const args = process.argv.slice(2);
const isWatch = args.some((arg) => arg === "--watch" || arg === "-w");

getDependencies()
  .then((dependencies) => {
    return Esbuild.build({
      watch: isWatch,
      entryPoints: ["client/client.js"],
      outfile: "static/bundle.js",
      bundle: true,
      external: ["melange/lib", ...dependencies],
      plugins: [commonjs()],
    });
  })
  .then(() => {
    console.log(`Build successful`);
  })
  .catch((error) => {
    console.error("Build fail: " + error);
    process.exit(1);
  });
