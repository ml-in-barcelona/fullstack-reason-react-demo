[@react.component]
let make = (~excerpts: list(ExcerptT.t)) => {
  <PageContainer>
    <>
      <h1 key="header"> {React.string("Excerpts")} </h1>
      {excerpts
       |> List.mapi((_i, exceprt) =>
            <Excerpt key={string_of_int(_i)} exceprt />
          )
       |> Array.of_list
       |> React.array}
    </>
  </PageContainer>;
};
