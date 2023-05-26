let useStateValue = (initial: 'a) => {
  React.useReducer((_ignored, newState) => newState, initial);
};

/* module ExternalLinkIcon = {
     [@react.component]
     let make = (~children) => {
       <svg
         xmlns="http://www.w3.org/2000/svg"
         viewBox="0 0 24 24"
         width="24px"
         height="24px">
         <path
           d="M 5 3 C 3.9069372 3 3 3.9069372 3 5 L 3 19 C 3 20.093063 3.9069372 21 5 21 L 19 21 C 20.093063 21 21 20.093063 21 19 L 21 12 L 19 12 L 19 19 L 5 19 L 5 5 L 12 5 L 12 3 L 5 3 z M 14 3 L 14 5 L 17.585938 5 L 8.2929688 14.292969 L 9.7070312 15.707031 L 19 6.4140625 L 19 10 L 21 10 L 21 3 L 14 3 z"
         />
       </svg>;
     };
   }; */

module ExternalLinkIcon = {
  [@react.component]
  let make = () => {
    <span className={Css.style([Css.fontSize(`px(10))])}>
      {React.string({js|🔗|js})}
    </span>;
  };
};

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

module Dropdown = {
  module Trigger = {
    [@react.component]
    let make = (~isOpen, ~onClick) => {
      <div
        onClick
        className={Css.style([
          Css.color(isOpen ? Theme.Color.white : Theme.Color.lightGrey),
          Css.cursor(`pointer),
          Css.userSelect(`none),
          Css.fontSize(`px(14)),
          Css.whiteSpace(`nowrap),
          Css.hover([Css.color(Theme.Color.white)]),
        ])}>
        {React.string("More tools")}
      </div>;
    };
  };

  /* let useClickOutside = (domRef, callback) => {
       open Webapi.Dom;
       let onClickHandler = event => {
         MouseEvent.stopPropagation(event);
         let target = MouseEvent.target(event);
         let targetElement = EventTarget.unsafeAsElement(target);
         let targetIsOutsideOverlayTrigger =
           switch (domRef |> Js.Nullable.toOption) {
           | Some(ref_) => !Element.contains(targetElement, ref_)
           | None => false
           };

         if (targetIsOutsideOverlayTrigger) {
           callback();
         };
       };

       React.useEffect2(
         () => {
           Document.addMouseDownEventListener(onClickHandler, document);
           Some(
             () =>
               Document.removeMouseDownEventListener(onClickHandler, document),
           );
         },
         (onClick, domRef.React.current),
       );
     }; */

  [@react.component]
  let make = (~items, ~onClick) => {
    let (isOpen, setIsOpen) = useStateValue(false);
    let _triggerRef = React.useRef(Js.Nullable.null);

    /* useClickOutside(triggerRef, () =>
         if (isOpen) {
           setIsOpen(false);
         }
       ); */

    <div className={Css.style([Css.position(`relative)])}>
      <Trigger isOpen onClick={_e => setIsOpen(!isOpen)} />
      {isOpen
         ? {
           <div
             className={Css.style([
               Css.position(`absolute),
               Css.top(`px(25)),
               Css.left(`percent(-50.)),
               Css.background(Theme.Color.backgroundBox),
               Css.padding(`rem(1.)),
               Css.borderRadius(`px(6)),
               Css.boxShadow(
                 Css.Shadow.box(
                   ~x=`zero,
                   ~y=`zero,
                   ~blur=`px(10),
                   ~spread=`px(1),
                   Css.rgba(0, 0, 0, `percent(30.)),
                 ),
               ),
             ])}>
             {React.array(
                Belt.Array.mapWithIndex(items, (key, item) =>
                  <div
                    key={Int.to_string(key)}
                    className={Css.style([
                      Css.display(`block),
                      Css.margin2(~h=`zero, ~v=`rem(0.3)),
                    ])}>
                    <span
                      onClick={_e => onClick(item)}
                      className={Css.style([
                        Css.color(Theme.Color.lightGrey),
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
         }
         : React.null}
    </div>;
  };
};

module Menu = {
  /* let useOnResize = () => {
       React.useEffect1(
         () => {
           open Webapi.Dom;
           let windowAsTarget = Window.asEventTarget(window);
           let handleResize = _ => setWindowHeight(_ => getWindowHeight());
           EventTarget.addEventListener("resize", handleResize, windowAsTarget);
           Some(
             () =>
               EventTarget.removeEventListener(
                 "resize",
                 handleResize,
                 windowAsTarget,
               ),
           );
         },
         [||],
       );
     }; */

  [@react.component]
  let make = (~currentNavigate: string, ~navigate: string => unit) => {
    let (tools, _setTools) =
      useStateValue([|
        "Dashboard",
        "Site Explorer",
        "Keywords Explorer",
        "Site Audit",
        "Rank Tracker",
        "Content Explorer",
      |]);

    let (moreTools, _setMoreTools) =
      useStateValue([|
        "Alerts",
        "Ahrefs Rank",
        "Batch Analysis",
        "Link intersect",
        "SEO Toolbar",
        "WordPress Plugin",
        "Ahrefs API",
        "Apps",
      |]);

    let externalLinks = [|"Community", "Academy"|];

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
      <Dropdown items=moreTools onClick=navigate />
      <span
        className={Css.style([
          Css.color(Theme.Color.white),
          Css.fontSize(`px(10)),
          Css.userSelect(`none),
        ])}>
        {React.string("|")}
      </span>
      {React.array(
         Belt.Array.mapWithIndex(externalLinks, (key, item) =>
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
               <Row gap=1> {React.string(item)} <ExternalLinkIcon /> </Row>
             </span>
           </div>
         ),
       )}
    </div>;
  };
};

[@react.component]
let make = () => {
  let (currentNavigate, setNavigate) = useStateValue("Dashboard");

  <Root background=Theme.Color.brokenWhite>
    <Panel>
      <Row justify=`start align=`center>
        <Spacer bottom=1> <Logo /> </Spacer>
        <Menu currentNavigate navigate={to_ => setNavigate(to_) |> ignore} />
      </Row>
      <SubHeader />
    </Panel>
    <div
      className={Css.style([
        Css.height(`px(200)),
        Css.width(`percent(100.)),
      ])}>
      <Align> <h2> {React.string(currentNavigate)} </h2> </Align>
    </div>
  </Root>;
};
