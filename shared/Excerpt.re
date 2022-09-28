[@react.component]
let make = (~e: Excerpt_t.t) => {
  let page =
    switch (e.page) {
    | None => ""
    | Some(p) => Printf.sprintf(", page %s", p)
    };

  <div className="content">
    <blockquote
      className="relative p-4 text-xl border-l-4 bg-neutral-100 text-neutral-600 border-neutral-500 quote">
      <p className="mb-2"> {React.string(e.excerpt)} </p>
      <cite>
        {React.string(
           Printf.sprintf("-- %s (%s%s)", e.author, e.source, page),
         )}
      </cite>
    </blockquote>
  </div>;
};
