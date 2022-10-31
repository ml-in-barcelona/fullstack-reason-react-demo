module Wat = {
  [@react.component]
  let make = (~exceprt: ExcerptT.t) => {
    let page =
      switch (exceprt.page) {
      | None => ""
      | Some(p) => Printf.sprintf(", page %s", p)
      };

    <div className="content">
      <blockquote
        className="relative p-4 text-xl border-l-4 bg-neutral-100 text-neutral-600 border-neutral-500 quote">
        <p className="mb-2"> {React.string(exceprt.excerpt)} </p>
        <cite>
          {React.string(
            Printf.sprintf("-- %s (%s%s)", exceprt.author, exceprt.source, page),
          )}
        </cite>
      </blockquote>
    </div>;
  };
};

switch (ReactDOM.querySelector("#root")) {
| Some(el) =>
  ReactDOM.render(<Wat />, el)
| None => ()
};
