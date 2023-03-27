[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 23);

  let increment = event => {
    let _target = ReactEvent.Mouse.target(event);
    Js.Console.log("Console works too! " /* ++ target##value */);
    setCount(_ => count + 1);
  };

  <div>
    <div>
      <p> {React.string("Counter")} </p>
      <button onClick=increment>
        {React.string(Int.to_string(count))}
      </button>
    </div>
    <p>
      {React.string(
         "The HTML (including counter value) comes first from the server"
         ++ " then is updated by React after render or hydration (depending if you are running ReactDOM.render or ReactDOM.hydrate on the client).",
       )}
    </p>
  </div>;
};
