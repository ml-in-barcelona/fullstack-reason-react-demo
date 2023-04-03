open Theme;

[@react.component]
let make =
    (~gap=0, ~align=`start, ~justify=`around, ~fullHeight=false, ~children) => {
  let className =
    Css.style([
      Css.display(`flex),
      Css.flexDirection(`column),
      fullHeight ? Css.height(`percent(100.)) : Css.height(`auto),
      switch ((align: align)) {
      | `start => Css.alignItems(`flexStart)
      | `center => Css.alignItems(`center)
      | `end_ => Css.alignItems(`flexEnd)
      },
      switch (justify) {
      | `around => Css.justifyContent(`spaceAround)
      | `between => Css.justifyContent(`spaceBetween)
      | `evenly => Css.justifyContent(`spaceEvenly)
      | `start => Css.justifyContent(`flexStart)
      | `center => Css.justifyContent(`center)
      | `end_ => Css.justifyContent(`flexEnd)
      },
      Css.unsafe("gap", Theme.to_string(gap)),
    ]);

  <div className> children </div>;
};
