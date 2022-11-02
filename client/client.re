module Wat = {
  [@react.component]
  let make = (~excerpt: ExcerptT.t) => {
    let page =
      switch (excerpt.page) {
      | None => ""
      | Some(p) => Printf.sprintf(", page %s", p)
      };

    <div className="content">
      <blockquote
        className="relative p-4 text-xl border-l-4 bg-neutral-100 text-neutral-600 border-neutral-500 quote">
        <p className="mb-2"> {React.string(excerpt.excerpt)} </p>
        <cite>
          {React.string(
            Printf.sprintf("-- %s (%s%s)", excerpt.author, excerpt.source, page),
          )}
        </cite>
      </blockquote>
    </div>;
  };
};

let excerpt: ExcerptT.t = {
  page: None,
  excerpt: "I'm an excerpt",
  author: "Author",
  source: "https://sourcegraph.com/github.com/facebook/hhvm/-/tree/hphp/hack/src/utils",
}

switch (ReactDOM.querySelector("#root")) {
| Some(el) =>
  ReactDOM.render(<Wat excerpt />, el)
| None => ()
};
