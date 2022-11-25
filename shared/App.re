[@react.component]
let make = () => {
  <div
    className={Css.style([
      Css.padding(`rem(2.)),
      Css.maxWidth(`px(800)),
      Css.margin2(~v=`zero, ~h=`auto),
      Css.border(`px(2), `solid, Css.gray),
      Css.borderRadius(`px(6)),
      Css.marginTop(`rem(4.)),
    ])}>
    <Header />
    <span
      className={Css.style([
        Css.display(`block),
        Css.width(`percent(100.)),
        Css.height(`px(1)),
        Css.backgroundColor(Css.gray),
        Css.margin4(
          ~top=`rem(1.),
          ~bottom=`rem(1.),
          ~left=`rem(-2.0),
          ~right=`rem(-2.0),
        ),
        Css.paddingRight(`rem(4.)),
      ])}
    />
    <Counter />
  </div>;
};
