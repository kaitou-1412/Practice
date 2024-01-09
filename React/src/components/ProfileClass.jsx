import React from "react";

class Profile extends React.Component {
  constructor(props) {
    super(props);
    const { name } = this.props;
    // Create State
    this.state = {
      userInfo: {
        name: "",
        avatar_url: "",
        public_repos: 0,
      },
    };
    console.log("Child - constructor");
  }

  render() {
    const { name, avatar_url, public_repos } = this.state.userInfo;
    console.log("Child - render");
    return (
      <div className="py-5">
        <h2 className="font-extrabold text-xl">Profile Class Component</h2>
        <h3 className="pt-5">Name: {name}</h3>
        <h4>Public Repos: {public_repos}</h4>
        <img className="pt-5" src={avatar_url} alt="User Image" />
      </div>
    );
  }

  async componentDidMount() {
    // API Calls
    const data = await fetch("https://api.github.com/users/kaitou-1412");
    const json = await data.json();
    console.log(json);
    this.setState({
      userInfo: {
        name: json.name,
        avatar_url: json.avatar_url,
        public_repos: json.public_repos,
      },
    });
    console.log("Child - componentDidMount");
  }

  componentDidUpdate() {
    console.log("Child - componentDidUpdate");
  }

  componentWillUnmount() {
    console.log("Child - componentWillUnmount");
  }
}

export default Profile;
