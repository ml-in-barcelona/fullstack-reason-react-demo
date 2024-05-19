switch (ReactDOM.querySelector("#root")) {
| Some(el) => ignore @@ ReactDOM.Client.hydrateRoot(el, <Shared_js.Ahrefs />)
| None => ()
};
