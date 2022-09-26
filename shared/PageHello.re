[@react.component]
let make = (~lang) => {
  let greeting =
    switch (lang) {
    | "Deutsch" => "Hallo, Welt!"
    | "English" => "Hello, World!"
    | s when s == {j|中文|j} => {j|你好，世界!|j}
    | _ => "Language not supported :(\nYou can add a language via PR to https://github.com/jchavarri/ocaml_webapp"
    };
  <PageContainer> <> <p> {React.string(greeting)} </p> </> </PageContainer>;
};
