import { useRouteError } from "react-router-dom";

const Error = () => {
  const { status, statusText } = useRouteError();

  return (
    <div className="h-screen bg-blue text-white p-5">
      <h1 className="font-extrabold text-3xl py-5">Oops!!!</h1>
      <h2>Something went wrong...</h2>
      <h2>{status + " : " + statusText}</h2>
    </div>
  );
};

export default Error;
