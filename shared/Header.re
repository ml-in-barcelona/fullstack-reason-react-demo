type item = {
  label: string,
  link: string,
};

module Menu = {
  [@react.component]
  let make = () => {
    let data = [|
      {
        label: "Documentation",
        link: "https://github.com/ml-in-barcelona/server-reason-react",
      },
      {
        label: "Issues",
        link: "https://github.com/ml-in-barcelona/server-reason-react/issues",
      },
      {label: "About", link: "https://twitter.com/davesnx"},
    |];

    <div
      className={Css.style([
        Css.display(`flex),
        Css.alignItems(`center),
        Css.justifyContent(`left),
        Css.unsafe("gap", "1rem"),
        Css.marginTop(`rem(0.5)),
      ])}>
      {React.array(
         Belt.Array.mapWithIndex(data, (key, item) =>
           <div
             className={Css.style([Css.display(`block)])}
             key={Int.to_string(key)}>
             <a
               href={item.link}
               target="_blank"
               className={Css.style([
                 Css.color(Css.hex("9b9b9b")),
                 Css.fontSize(`px(14)),
                 Css.hover([Css.color(Css.white)]),
               ])}>
               {React.string(item.label)}
             </a>
           </div>
         ),
       )}
    </div>;
  };
};

[@react.component]
let make = () => {
  <div className={Css.style([Css.color(Css.plum), Css.fontSize(`px(24))])}>
    <h1 className={Css.style([Css.margin(`px(0))])}>
      {React.string("Server Reason React")}
    </h1>
    <Menu />
  </div>;
};
