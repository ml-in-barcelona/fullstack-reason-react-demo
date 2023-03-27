type item = {
  label: string,
  link: string,
};

module Menu = {
  [@react.component]
  let make = () => {
    let data = [|
      {
        label: "Documentation",
        link: "https://github.com/ml-in-barcelona/server-reason-react",
      },
      {
        label: "Issues",
        link: "https://github.com/ml-in-barcelona/server-reason-react/issues",
      },
      {label: "About", link: "https://twitter.com/davesnx"},
    |];

    <div>
      {React.array(
         Belt.Array.mapWithIndex(data, (key, item) =>
           <div key={Int.to_string(key)}>
             <a href={item.link} target="_blank">
               {React.string(item.label)}
             </a>
           </div>
         ),
       )}
    </div>;
  };
};

[@react.component]
let make = () => {
  <div> <h1> {React.string("Server Reason React")} </h1> <Menu /> </div>;
};
