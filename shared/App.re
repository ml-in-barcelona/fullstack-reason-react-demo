module Wrapper = {
  [@react.component]
  let make = (~children) => {
    <div
      className={Css.style([Css.display(`block), Css.padding(`rem(2.))])}>
      children
    </div>;
  };
};

module Hr = {
  [@react.component]
  let make = () => {
    <span
      className={Css.style([
        Css.display(`block),
        Css.width(`percent(100.)),
        Css.height(`px(1)),
        Css.backgroundColor(Css.gray),
      ])}
    />;
  };
};

module Layout = {
  [@react.component]
  let make = (~children) => {
    <div
      className={Css.style([
        Css.maxWidth(`px(800)),
        Css.margin2(~v=`zero, ~h=`auto),
        Css.border(`px(2), `solid, Css.gray),
        Css.borderRadius(`px(6)),
      ])}>
      children
    </div>;
  };
};

[@react.component]
let make = () => {
  <div className={Css.style([Css.padding(`rem(2.))])}>
    <Layout>
      <div>
        <Wrapper> <Header /> </Wrapper>
        <Hr />
        <Wrapper> <Counter /> </Wrapper>
      </div>
    </Layout>
  </div>;
};
