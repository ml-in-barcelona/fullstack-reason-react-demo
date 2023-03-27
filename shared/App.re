module Wrapper = {
  [@react.component]
  let make = (~children) => {
    <div> children </div>;
  };
};

module Hr = {
  [@react.component]
  let make = () => {
    <span />;
  };
};

module Layout = {
  [@react.component]
  let make = (~children) => {
    <div> children </div>;
  };
};

[@react.component]
let make = () => {
  <div className={Css.style([Css.padding(`zero)])}>
    <Layout>
      <>
        <Wrapper> <Header /> </Wrapper>
        <Hr />
        <Wrapper> <Counter /> </Wrapper>
      </>
    </Layout>
  </div>;
};
