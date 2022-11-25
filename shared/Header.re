[@react.component]
let make = () => {
  <div className={Css.style([Css.color(Css.plum), Css.fontSize(`px(24))])}>
    <h1 className={Css.style([Css.margin(`px(0))])}>
      {React.string("Hello World")}
    </h1>
  </div>;
};
