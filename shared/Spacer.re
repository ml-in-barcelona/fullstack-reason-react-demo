let unsafeWhenNotZero = (prop, value) =>
  if (value == 0) {
    [];
  } else {
    [prop(value |> Theme.px)];
  };

[@react.component]
let make = (~children=?, ~top=0, ~left=0, ~right=0, ~bottom=0, ~all=0) => {
  let className =
    Css.style(
      List.flatten([
        unsafeWhenNotZero(Css.marginTop, top),
        unsafeWhenNotZero(Css.marginBottom, bottom),
        unsafeWhenNotZero(Css.marginLeft, left),
        unsafeWhenNotZero(Css.marginRight, right),
        unsafeWhenNotZero(Css.margin, all),
      ]),
    );

  <div className>
    {switch (children) {
     | None => React.null
     | Some(c) => c
     }}
  </div>;
};
