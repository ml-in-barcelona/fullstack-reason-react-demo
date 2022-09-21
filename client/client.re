open Webapi.Dom;

let () = {
  let body = document |> Document.querySelector("body");

  switch (body) {
  | None => ()
  | Some(body) =>

    let text = Shared.greet(`Client);

    let p = document |> Document.createElement("p");
    p->Element.setInnerText(text);
    body |> Element.appendChild(p);
  }
};
