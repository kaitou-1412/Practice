import { Component } from "react";
import { Outlet, Link } from "react-router-dom";
import UserContext from "../utils/UserContext";

// const About = () => {
//   return (
//     <div>
//       <h1>About Us Page</h1>
//       <p> Finding the Path 🚀</p>
//       <Outlet />
//     </div>
//   );
// };

class About extends Component {
  constructor(props) {
    super(props);
    console.log("Parent - constructor");
  }
  render() {
    console.log("Parent - render");
    return (
      <div className="flex-grow bg-blue text-white p-5">
        <h1 className="font-extrabold text-3xl py-5">About Us Page</h1>
        <UserContext.Consumer>
          {({ user }) => (
            <h4 className="font-bold text-xl py-10">
              {user.name}- {user.email}
            </h4>
          )}
        </UserContext.Consumer>
        <p className="py-5">
          {" "}
          Finding the <Link to="profile">Path</Link> 🚀
        </p>
        <Outlet />
      </div>
    );
  }
  componentDidMount() {
    this.timer = setInterval(() => {
      console.log("Hello Ruban!");
    }, 1000);
    console.log("Parent - componentDidMount");
  }
  componentWillUnmount() {
    clearInterval(this.timer);
    console.log("Parent - componentWillUnmount");
  }
}

export default About;
