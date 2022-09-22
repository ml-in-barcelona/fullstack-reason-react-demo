module App = {
  [@react.component]
  let make = (~children) => {
    <div>
      <h1>{React.string("SSR React")}</h1>
      {children}
    </div>
  }
};
