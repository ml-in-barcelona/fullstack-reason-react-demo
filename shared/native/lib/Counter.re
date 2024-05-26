[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 23);

  let increment = event => {
    let _target = React.Event.Mouse.target(event);
    print_endline("Console works too! " /* ++ target##value */);
    setCount(_ => count + 1);
  };

  <div className={Css.style([Css.color(Css.whitesmoke)])}>
    <div
      className={Css.style([
        Css.display(`flex),
        Css.justifyContent(`left),
        Css.alignItems(`center),
        Css.unsafe("gap", "1rem"),
      ])}>
      <p
        className={Css.style([
          Css.margin(`zero),
          Css.fontSize(`px(25)),
          Css.fontWeight(`bold),
        ])}>
        {React.string("Counter")}
      </p>
      <button onClick=increment>
        {React.string(Int.to_string(count))}
      </button>
    </div>
    <p className={Css.style([Css.lineHeight(`px(24))])}>
      {React.string(
         "The HTML (including counter value) comes first from the server"
         ++ " then is updated by React after render or hydration (depending if you are running ReactDOM.render or ReactDOM.hydrate on the client).",
       )}
    </p>
  </div>;
};
