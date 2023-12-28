import { Component } from "react";
import { Outlet, Link } from "react-router-dom";

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
      <div>
        <h1>About Us Page</h1>
        <p>
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
