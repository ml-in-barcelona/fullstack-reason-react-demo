[@react.component]
let make = (~children, ~background) => {
  <div
    className={Css.style([
      Css.margin(`zero),
      Css.padding(`zero),
      Css.width(`vw(100.)),
      Css.height(`vh(100.)),
      Css.backgroundColor(background),
    ])}>
    children
  </div>;
};
