let oneDirectionRule = (prop: string, value: int) =>
  switch (value) {
  | 0 => []
  | _ => [Css.unsafe(prop, value |> Theme.to_string)]
  };

let shorthandRule = (prop: string, value) =>
  switch (value) {
  | 0 => []
  | _ => [Css.unsafe(prop, value |> Theme.to_string)]
  };

[@react.component]
let make =
    (~children=?, ~top=0, ~left=0, ~right=0, ~bottom=0, ~all=0, ~inner=false) => {
  let className =
    Css.style(
      List.flatten([
        oneDirectionRule(inner ? "marginTop" : "paddingTop", top),
        oneDirectionRule(inner ? "marginBottom" : "paddingBottom", bottom),
        oneDirectionRule(inner ? "marginLeft" : "paddingLeft", left),
        oneDirectionRule(inner ? "marginRight" : "paddingRight", right),
        shorthandRule(inner ? "margin" : "padding", all),
      ]),
    );

  <div className>
    {switch (children) {
     | None => React.null
     | Some(c) => c
     }}
  </div>;
};
