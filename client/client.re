switch (ReactDOM.querySelector("#root")) {
| Some(el) =>
  ReactDOM.render(<Shared.App />, el)
| None => ()
};
