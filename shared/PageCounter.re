[@react.component]
let make = () => {
  let (count, _setCount) = React.useState(() => 0);

  <PageContainer>
    <>
      <h1 key="header"> {React.string("Counter")} </h1>
      <p key="desc">
        {React.string(
          "The HTML (including counter value) comes first from the OCaml native server"
          ++ " then is updated by React after hydration",
        )}
      </p>
      <p key="counter"> {React.string(string_of_int(count))} </p>
    </>
  </PageContainer>;
};
