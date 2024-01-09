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
    <div className="py-5">
      <h2 className="font-extrabold text-xl">Profile Component</h2>
      <h3 className="pt-5">Name: {name}</h3>
      <h3 className="pb-2">Count: {count}</h3>
      <button
        className="bg-white text-black rounded-lg px-2 py-1 mr-2"
        onClick={() => setCount((c) => c + 1)}
      >
        Set
      </button>
      <button
        className="bg-white text-black rounded-lg px-2 py-1 mr-2"
        onClick={() => setCount(0)}
      >
        Reset
      </button>
    </div>
  );
};

export default Profile;
