# fullstack-reason-react-demo

> **Warning**
> This repo is in constant flux as I'm polishing the experience with `server-reason-react` and related libraries. If you are interested in this you can contact me in[Twitter](https://www.twitter.com/davesnx).

A demo of a fullstack reason-react app using Melange and Dream, which means
all code is written in Reason and compiled by both [Melange](https://github.com/melange-re/melange) and OCaml. Showcasing server-reason-react.

It uses dune to build the project and esy/npm for the dependencies.

The app consist of 3 folders: `shared`, `server` and `client`.

## `client`

A folder that contains the code executed in the client only, it is compiled by Melange to JavaScript and uses all the ReScript goodies: Belt, Js, etc. Currently is very tiny, as tiny as:

```re
switch (ReactDOM.querySelector("#root")) {
| Some(el) => ReactDOM.render(<Shared_js.App />, el)
| None => ()
};
```

client only renders the `Shared_js.App` component, which is defined in the `shared` folder. To understand how Shared_js is generated from `shared` keep reading.

## `server`

A Dream app with a home route which serves an HTML page written in [1*]server-reason-react and rendered by server-reason-react-dom with renderToString.

[1*] server-reason-react is the implementation of react and react-dom with the exact same API as reason-react, but in the server. It's thought to be used transparently as you were using reason-react.

## `shared`

The folder contains the shared code between `client` and `server`. dune generates the two libraries `Shared_js` and `Shared_native` with `copy_files#` and the dependencies that matter for each compilation.

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

The code of shared consist of an app to demostrate a few usages of server-reason-react implementations, such as emotion or js.

- `server-reason-react.css` is the implementation of bs-css in the server. Maintains the same API and does the same functionality as emotion.js but in the server. All Css.* methods are available and generates the hash of the classnames. It also adds a fn `Css.render_style_tag()` to render the resultant CSS in the page, with the intention to be called in native.
- `server-reason-react.belt` is the implementation of [Belt](https://rescript-lang.org/docs/manual/latest/api/belt) in pure OCaml.
- `server-reason-react.js` is an incomplete implementation of [Js](https://rescript-lang.org/docs/manual/latest/api/js)

## Problems

- This demo relies on a few technologies/features that aren't polished. For now (dune, Melange and server-reason-react) are patched to specific versions from Github commit hashes. Check [esy.json](./esy.json) for exact versions.
- **editor support**. Currently there's no editor support in the `shared` folder. Haven't played much with it and I'm not sure if is doable to have proper support with `copy_files`. Other methods of compilation (vlib) can have better support. After [ocaml/dune/pull/6476](https://github.com/ocaml/dune/pull/6476) it should be smooth.
- Js from ReScript isn't availables in native. We have Js APIs implemented in OCaml/C FFI. The only piece that is missing is `Js.t` representation that maps to JavaScript Object in ReScript, but there's no equivalent in native. For now `Js.t ({..})` are treated as a OCaml object and for accessing to properties with double hash (`##`) we have the ppx [server-reason-react.double_hash](https://github.com/ml-in-barcelona/server-reason-react/blob/main/lib/shims/ppx/double_hash.ml) which transforms `a##b` to `a#b`. This causes a few problems: ReactEvent.ml API relies on `Js.t` and I needed to change to handle an empty object, but I can't access any property unless I type them all (which I could, but doesn't seem ideal).
Until we can extract from Melange how to handle it, it might remain like this (broken in most places) or not being an option for now.
