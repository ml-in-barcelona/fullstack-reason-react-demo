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
        Css.padding4(
          ~top=`rem(4.0),
          ~bottom=`zero,
          ~left=`rem(2.0),
          ~right=`rem(2.0),
        ),
        Theme.Media.onMobile([Css.overflow(`hidden)]),
      ])}>
      children
    </div>;
  };
};

module Header = {
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
                   Css.hover([Css.color(Theme.Color.white)]),
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
    <div
      className={Css.style([Css.color(Css.plum), Css.fontSize(`px(24))])}>
      <h1 className={Css.style([Css.margin(`px(0))])}>
        {React.string("Server Reason React")}
      </h1>
      <Spacer top=2> <Menu /> </Spacer>
    </div>;
  };
};

[@react.component]
let make = () => {
  <Root background=Theme.Color.darkGrey>
    <Layout>
      <Stack gap=8 justify=`start>
        <> <Header /> <Hr /> <Counter /> </>
      </Stack>
    </Layout>
  </Root>;
};
