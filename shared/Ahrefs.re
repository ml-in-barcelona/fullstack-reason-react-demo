module Panel = {
  [@react.component]
  let make = (~children) => {
    <div
      className={Css.style([
        Css.width(`vw(100.)),
        Css.backgroundColor(Theme.Color.backgroundBox),
        Css.padding2(~v=`rem(0.5), ~h=`rem(1.)),
      ])}>
      children
    </div>;
  };
};

module ShrinkerText = {
  [@react.component]
  let make = (~children, ~color) => {
    let first = children.[0] |> String.make(1);
    let rest = String.sub(children, 1, String.length(children) - 1);

    <>
      <span className={Css.style([Css.color(color)])}>
        {React.string(first)}
      </span>
      <span
        className={Css.style([
          Css.cursor(`pointer),
          Css.display(`inline),
          Css.color(Theme.Color.white),
          Theme.Media.onMobile([Css.display(`none)]),
        ])}>
        {React.string(rest)}
      </span>
    </>;
  };
};

module Logo = {
  [@react.component]
  let make = () => {
    <p
      className={Css.style([
        Css.fontSize(`px(30)),
        Css.fontWeight(`bold),
        Css.margin(`zero),
      ])}>
      <ShrinkerText color=Theme.Color.ahrefs> "ahrefs" </ShrinkerText>
    </p>;
  };
};
module Menu = {
  [@react.component]
  let make = (~currentNavigate: string, ~navigate: string => unit) => {
    let tools = [|
      "Dashboard",
      "Site Explorer",
      "Keywords Explorer",
      "Site Audit",
      "Rank Tracker",
      "Content Explorer",
    |];

    let _moreTools = [|
      "Site Explorer",
      "SEO Toolbar",
      "WordPress Plugin",
      "Ahrefs API",
      "Apps",
    |];

    let _externalLinks = [|"Community", "Academy"|];

    <div
      className={Css.style([
        Css.display(`flex),
        Css.alignItems(`center),
        Css.justifyContent(`left),
        Css.unsafe("gap", "1rem"),
        Css.marginTop(`px(1)),
        Css.padding2(~v=`rem(0.5), ~h=`rem(1.5)),
      ])}>
      {React.array(
         Belt.Array.mapWithIndex(tools, (key, item) =>
           <div
             key={Int.to_string(key)}
             className={Css.style([Css.display(`block)])}>
             <span
               onClick={_e => navigate(item)}
               className={Css.style([
                 currentNavigate == item
                   ? Css.color(Theme.Color.white)
                   : Css.color(Theme.Color.lightGrey),
                 Css.cursor(`pointer),
                 Css.fontSize(`px(14)),
                 Css.whiteSpace(`nowrap),
                 Css.hover([Css.color(Theme.Color.white)]),
               ])}>
               {React.string(item)}
             </span>
           </div>
         ),
       )}
    </div>;
  };
};

let useStateValue = (initial: 'a) => {
  React.useReducer((_ignored, newState) => newState, initial);
};

[@react.component]
let make = () => {
  let (currentNavigate, setNavigate) = useStateValue("Dashboard");

  <Root background=Theme.Color.brokenWhite>
    <>
      <Panel>
        <>
          <Row justify=`start align=`center>
            <>
              <Spacer bottom=1> <Logo /> </Spacer>
              <Menu
                currentNavigate
                navigate={to_ => setNavigate(to_) |> ignore}
              />
            </>
          </Row>
          <SubHeader />
        </>
      </Panel>
      <div
        className={Css.style([
          Css.height(`px(200)),
          Css.width(`percent(100.)),
        ])}>
        <Align> <h2> {React.string(currentNavigate)} </h2> </Align>
      </div>
    </>
  </Root>;
};
