let className = Emotion.style([Css.Properties.display(`block)]);

module Header = {
  [@react.component]
  let make = () => {
    <div className />;
  };
};

module App = {
  [@react.component]
  let make = () => {
    <> <Header /> <PageWelcome /> </>;
  };
};
