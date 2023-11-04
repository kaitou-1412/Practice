import React from "react";
import ReactDOM from "react-dom/client";

const Title = () => <h1>Hello All!</h1>;

const HeaderComponent = () => (
  <div id="container">
    <Title />
    <h2 id="title" key="heading1">
      Hello Everyone from JSX!
    </h2>
    <h2 id="title" key="heading2">
      Hello Everyone!
    </h2>
  </div>
);
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<HeaderComponent />);
