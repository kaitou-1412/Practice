import { useState } from "react";

const Title = () => (
  <a href="/">
    <img
      className="logo"
      src="https://foodhouse.co.th/wp-content/uploads/2019/01/foodhouse-18.jpg"
      alt="Food Fire Logo"
    />
  </a>
);

/* <i class="fa-solid fa-cart-shopping"></i> */

const Header = () => {
  const [isLoggedin, setIsLoggedin] = useState(true);

  return (
    <div className="header">
      <Title />
      <div className="nav-items">
        <ul>
          <li>Home</li>
          <li>About</li>
          <li>Contact</li>
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
