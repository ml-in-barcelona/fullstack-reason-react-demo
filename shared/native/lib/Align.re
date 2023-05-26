type verticalAlign = [ | `top | `center | `bottom];
type horizontalAlign = [ | `left | `center | `right];

[@react.component]
let make = (~h: horizontalAlign=`center, ~v: verticalAlign=`center, ~children) => {
  let className =
    Css.style([
      Css.display(`flex),
      Css.flexDirection(`column),
      Css.height(`percent(100.)),
      Css.width(`percent(100.)),
      switch (h) {
      | `left => Css.alignItems(`flexStart)
      | `center => Css.alignItems(`center)
      | `right => Css.alignItems(`flexEnd)
      },
      switch (v) {
      | `top => Css.justifyContent(`flexStart)
      | `center => Css.justifyContent(`center)
      | `bottom => Css.justifyContent(`flexEnd)
      },
    ]);

  <div className> children </div>;
};
