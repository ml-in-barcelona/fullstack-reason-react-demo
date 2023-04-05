[@react.component]
let make =
    (
      ~gap=0,
      ~align: Theme.align=`start,
      ~justify: Theme.justify=`around,
      ~fullHeight=false,
      ~fullWidth=false,
      ~children,
    ) => {
  let className =
    Css.style([
      Css.display(`flex),
      Css.flexDirection(`row),
      fullHeight ? Css.height(`percent(100.)) : Css.height(`auto),
      fullWidth ? Css.width(`percent(100.)) : Css.width(`auto),
      switch (align) {
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
      Css.gap(Theme.px(gap)),
    ]);

  <div className> children </div>;
};
