[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 0);

  let increment = (_event) => {
    setCount((_) => count + 1);
  };

  <div>
    <>
      <h1 key="header" onClick={increment}> {"Counter"->React.string} </h1>
      <p key="desc">
        {React.string(
           "The HTML (including counter value) comes first from the OCaml native server"
           ++ " then is updated by React after hydration",
         )}
      </p>
    </>
  </div>;
};
