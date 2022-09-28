switch (ReactDOM.querySelector("#root")) {
| Some(el) =>
  ReactDOM.render(
    <Shared.App> <h2> {React.string("client")} </h2> </Shared.App>,
    el,
  )
| None => ()
};
