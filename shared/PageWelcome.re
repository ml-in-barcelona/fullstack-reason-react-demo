[@react.component]
let make = () => {
  <PageContainer>
    <>
      <h1 className="font-semibold text-xl tracking-tight mb-8">
        {React.string("OCaml native webapp with SSR + React hydration")}
      </h1>
      <h2> {React.string("Hello")} </h2>
      <ul className="list-disc list-inside mb-8">
        {List.mapi(
          (_i, x) => <li key={string_of_int(_i)}> x </li>,
          [
            <Link url="/hello" txt="hiya" />,
            <Link url={j|/hello/中文|j} txt={j|中文|j} />,
            <Link url="/hello/Deutsch" txt="Deutsch" />,
            <Link url="/hello/English" txt="English" />,
          ],
        )
        |> Array.of_list
        |> React.array}
      </ul>
      <h2> {React.string("Excerpts")} </h2>
      <ul className="list-disc list-inside mb-8">
        {List.mapi(
          (_i, x) => <li key={string_of_int(_i)}> x </li>,
          [
            <Link url="/excerpts/add" txt="Add Excerpt" />,
            <Link
              url={"???"}
              txt="Authors with excerpts"
            />,
          ],
        )
        |> Array.of_list
        |> React.array}
      </ul>
      <h2> {React.string("Other examples")} </h2>
      <ul className="list-disc list-inside mb-8">
        <>
          <li>
            <Link
              url={"counter!:"}
              txt="Counter"
            />
          </li>
        </>
      </ul>
      </>
  </PageContainer>;
};
