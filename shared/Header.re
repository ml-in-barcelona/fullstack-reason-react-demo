[@react.component]
let make = () => {
  <div className={Css.style([Css.display(`block)])}>
    <h1> {React.string("Hello World")} </h1>
  </div>;
};
