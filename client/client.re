Belt.Array.map([|1, 2, 3|], x => x + 1)->Js.log;

switch (ReactDOM.querySelector("#root")) {
| Some(el) => ReactDOM.hydrate(<Shared_js.App />, el)
| None => ()
};
