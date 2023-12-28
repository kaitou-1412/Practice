import { useState, useEffect } from "react";

const Profile = ({ name }) => {
  const [count, setCount] = useState(0);
  useEffect(() => {
    console.log("useEffect");
    const timer = setInterval(() => {
      console.log("Hello from functional component profile");
    }, 1000);
    return () => {
      clearInterval(timer);
      console.log("useEffect return");
    };
  }, []);
  console.log("render");
  return (
    <>
      <h2>Profile Component</h2>
      <h3>Name: {name}</h3>
      <h3>Count: {count}</h3>
      <button onClick={() => setCount((c) => c + 1)}>Set</button>
      <button onClick={() => setCount(0)}>Reset</button>
    </>
  );
};

export default Profile;
