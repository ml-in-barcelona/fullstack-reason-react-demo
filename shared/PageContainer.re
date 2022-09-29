[@react.component]
let make = (~children) => {
  <div className="flex xs:justify-center overflow-hidden">
    <div
      className="mt-8 md:mt-32 mx-8 md:mx-32 min-w-md lg:align-center w-full px-4 md:px-8 max-w-2xl">
      children
    </div>
  </div>;
};
