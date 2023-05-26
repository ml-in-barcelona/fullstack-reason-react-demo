let useState = a => {
  let (value, setValue) = React.useState(_ => a);
  let setValueStatic = value => setValue(_ => value);
  (value, setValueStatic);
};

module Counter = {
  [@react.component]
  let make = (~name) => {
    let (count, setCount) = useState(0);

    <div>
      <p>
        {React.string(
           name ++ " clicked " ++ Int.to_string(count) ++ " times",
         )}
      </p>
      <button onClick={_ => setCount(count + 1)}>
        {React.string("Click me")}
      </button>
    </div>;
  };
};

switch (ReactDOM.querySelector("#root")) {
| Some(el) => ReactDOM.hydrate(<Shared_js.App />, el)
| None => ()
};
