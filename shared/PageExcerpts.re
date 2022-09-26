[@react.component]
let make = (~excerpts: list(Excerpt_t.t)) => {
  let children = [
    <h1 key="header"> {React.string("Excerpts")} </h1>,
    ...List.mapi(
         (_i, e) => <Excerpt key={string_of_int(_i)} e />,
         excerpts,
       ),
  ];
  <PageContainer> {children |> React.list} </PageContainer>;
};
