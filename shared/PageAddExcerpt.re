type action =
  | AuthorChanged(string)
  | ExcerptChanged(string)
  | SourceChanged(string)
  | PageChanged(string)
  | FormSubmitted
  | AddExcerptRequestSucceeded(Excerpt_t.t)
  | AddExcerptRequestFailed(string);

type submissionState =
  | NotAsked
  | Loading
  | Success(Excerpt_t.t)
  | Error(string);

type state = {
  author: string,
  excerpt: string,
  source: string,
  page: string,
  submissionState,
};

let row = (left, right) =>
  <>
    <div className="md:w-1/3"> <> left </> </div>
    <div className="md:w-2/3"> <> right </> </div>
  </>;

let reducer = (state, action) =>
  switch (action) {
  | AuthorChanged(author) => {...state, author}
  | ExcerptChanged(excerpt) => {...state, excerpt}
  | SourceChanged(source) => {...state, source}
  | PageChanged(page) => {...state, page}
  | FormSubmitted => {...state, submissionState: Loading}
  | AddExcerptRequestSucceeded(excerpt) => {
      ...state,
      submissionState: Success(excerpt),
    }
  | AddExcerptRequestFailed(msg) => {...state, submissionState: Error(msg)}
  };

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      reducer,
      {
        author: "",
        excerpt: "",
        source: "",
        page: "",
        submissionState: NotAsked,
      },
    );

  let txtInput = (name, value, _onChange) =>
    row(
      <label
        className="block text-gray-500 md:text-right mb-1 md:mb-0 pr-4"
        htmlFor="inline-full-name">
        {React.string(String.capitalize_ascii(name))}
      </label>,
      <Input
        className="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-blue-500"
        input_type=`Text
        name
        onChange={e => _onChange(ReactEvent.Form.target(e)##value)}
        value
      />,
    );

  let excerptInput = {
    let name = "excerpt";
    row(
      <label
        className="block text-gray-500 md:text-right mb-1 md:mb-0 pr-4"
        htmlFor=name>
        {React.string(String.capitalize_ascii(name))}
      </label>,
      <Textarea
        className="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-blue-500"
        name
        value={state.excerpt}
        onChange={e =>
          dispatch @@ ExcerptChanged(ReactEvent.Form.target(e)##value)
        }
      />,
    );
  };

  let submit =
    row(
      <div />,
      <Input
        className="shadow bg-blue-500 hover:bg-blue-400 focus:shadow-outline focus:outline-none text-white font-bold py-2 px-4 rounded"
        input_type=`Submit
        value="Submit"
      />,
    );

  <PageContainer>
    {switch (state.submissionState) {
     | Loading =>
       <>
         <h1 className="font-semibold text-xl tracking-tight mb-8">
           {React.string("Add new excerpt")}
         </h1>
         <p> {React.string("Loading....")} </p>
       </>
     | Error(msg) =>
       <>
         <h1 className="font-semibold text-xl tracking-tight mb-8">
           {React.string("Add new excerpt")}
         </h1>
         <p> {React.string("Error: " ++ msg)} </p>
       </>
     | Success(e) =>
       <>
         <h1 className="font-semibold text-xl tracking-tight mb-8">
           {React.string("Excerpt added successfully")}
         </h1>
         <p> {React.string("Added the following excerpt: ")} </p>
         <Excerpt e />
         <Link url="/" txt="Back home" />
       </>
     | NotAsked =>
       <>
         <h1 className="font-semibold text-xl tracking-tight mb-8">
           {React.string("Add new excerpt")}
         </h1>
         {<Form
            onSubmit={e => {
              ReactEvent.Form.preventDefault(e);
              dispatch @@ FormSubmitted;
              Client.request(
                ~method_=Post,
                ~input={
                  Excerpt_bs.write_t({
                    author: state.author,
                    excerpt: state.excerpt,
                    source: state.source,
                    page: Some(state.page),
                  });
                },
                Routes.sprintf(Router.ApiRoutes.add_excerpt()),
                Excerpt_bs.read_t,
              )
              |> Js.Promise.then_(res =>
                   (
                     switch (res) {
                     | Ok(excerpt) =>
                       dispatch @@ AddExcerptRequestSucceeded(excerpt)
                     | Error(err) =>
                       dispatch @@
                       AddExcerptRequestFailed(Client.errorToString(err))
                     }
                   )
                   ->Js.Promise.resolve
                 )
              |> ignore;
            }}>
            {List.mapi(
               (_i, x) =>
                 <div
                   className="md:flex md:items-center mb-6"
                   key={string_of_int(_i)}>
                   x
                 </div>,
               [
                 txtInput("author", state.author, author =>
                   dispatch @@ AuthorChanged(author)
                 ),
                 excerptInput,
                 txtInput("source", state.source, author =>
                   dispatch @@ SourceChanged(author)
                 ),
                 txtInput("page", state.page, author =>
                   dispatch @@ PageChanged(author)
                 ),
                 submit,
               ],
             )
             |> React.list}
          </Form>}
       </>
     }}
  </PageContainer>;
};
