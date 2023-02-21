# fullstack-reason-react-demo

> **Warning**
> This repo is in constant flux as I'm polishing the experience with `server-reason-react` and related tooling.

A demo of a fullstack reason-react app using Melange and Dream, which means
all code is written in Reason and compiled by both [Melange](https://github.com/melange-re/melange) and OCaml. Showcasing server-reason-react.

It uses dune to build the project and esy/npm for the dependencies.

The app consist of 3 folders: `shared`, `server` and `client`, which encapsulates each compilation target defined by dune.

## `client/`

A folder that contains the code executed in the client only. It's defined in dune as a `melange.emit` to emit JavaScript from Reason via Melange. It uses all the ReScript goodies: Belt, Js, etc. Currently is tiny: client only renders the `Shared_js.App` component:

```re
switch (ReactDOM.querySelector("#root")) {
| Some(el) => ReactDOM.render(<Shared_js.App />, el)
| None => ()
};
```

## `server/`

An executable that expose a dream app with a home route which serves an HTML page. Written in [server-reason-react](https://github.com/ml-in-barcelona/server-reason-react) and send it as a string with `ReactDOM.renderToString`

## `shared/`

The folder contains the library for shared code between `client` and `server`. dune generates the two libraries `Shared_js` and `Shared_native` with `copy_files#` and the dependencies that matter for each compilation:

```dune
; shared/js/dune
(library
 (name shared_js)
 (modes melange)
 (flags :standard -bs-jsx 3)
 (libraries reason_react bs_css bs_css_emotion))

(copy_files# "../*.re")
```

```dune
; shared/native/dune
(library
 (name shared_native)
 (modes best) ; best means native and byte
 (libraries
  server-reason-react.react
  server-reason-react.reactDom
  server-reason-react.js
  server-reason-react.css)
 (preprocess
  (pps server-reason-react.ppx)))

(copy_files# "../*.re")
```

`Shared_js` is compiled by Melange to JavaScript while `Shared_native` by OCaml to a native library.

The code of shared consist of an app to demostrate a few usages of server-reason-react implementations, such as server-reason-react.emotion or server-reason-react.js.

- `server-reason-react.css` is the implementation of bs-css in the server. Maintains the same API and does the same functionality as emotion.js but in the server. All Css.* methods are available and generates the hash of the classnames. It also adds a fn `Css.render_style_tag()` to render the resultant CSS in the page, with the intention to be called in native.
- `server-reason-react.belt` is the implementation of [Belt](https://rescript-lang.org/docs/manual/latest/api/belt) in pure OCaml.
- `server-reason-react.js` is an incomplete implementation of [Js](https://rescript-lang.org/docs/manual/latest/api/js)

## Problems

- This demo relies on a few technologies/features that aren't polished. For now (dune, Melange and server-reason-react) are patched to specific versions from Github commit hashes. Check [esy.json](./esy.json) for exact versions.
- **editor support**. Currently there's no editor support in the `shared` folder. Haven't played much with it and I'm not sure if is doable to have proper support with `copy_files`. Other methods of compilation (vlib) can have better support. After [ocaml/dune/pull/6476](https://github.com/ocaml/dune/pull/6476) it can be smooth. 
- Js from ReScript isn't availables in native. We have Js APIs implemented in OCaml/C FFI. The only piece that is missing is `Js.t` representation that maps to JavaScript Object in ReScript, but there's no equivalent in native.
