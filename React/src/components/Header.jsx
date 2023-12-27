import { useState } from "react";
import { Link } from "react-router-dom";
import Logo from "../assets/img/foodhouse.jpg";

const Title = () => (
  <Link to="/">
    <img className="logo" src={Logo} alt="Food House Logo" />
  </Link>
);

/* <i class="fa-solid fa-cart-shopping"></i> */

const Header = () => {
  const [isLoggedin, setIsLoggedin] = useState(true);

  return (
    <div className="header">
      <Title />
      <div className="nav-items">
        <ul>
          <li>
            <Link to="/">Hom</Link>e
          </li>
          <li>
            <Link to="/about">About</Link>
          </li>
          <li>
            <Link to="/contact">Contact</Link>
          </li>
          <li>Cart</li>
          <li>
            {isLoggedin ? (
              <button onClick={() => setIsLoggedin(false)}>Logout</button>
            ) : (
              <button onClick={() => setIsLoggedin(true)}>Login</button>
            )}
          </li>
        </ul>
      </div>
    </div>
  );
};

export default Header;
