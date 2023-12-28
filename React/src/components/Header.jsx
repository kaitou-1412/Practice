import { Link, useNavigate } from "react-router-dom";
import Logo from "../assets/img/foodhouse.jpg";

const Title = () => (
  <Link to="/">
    <img className="logo" src={Logo} alt="Food House Logo" />
  </Link>
);

/* <i class="fa-solid fa-cart-shopping"></i> */

const Header = ({ isLoggedin, setIsLoggedin }) => {
  const navigate = useNavigate();

  return (
    <div className="header">
      <Title />
      <div className="nav-items">
        <ul>
          <li>
            <Link to="/">Home</Link>
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
              <button onClick={() => navigate("/login")}>Login</button>
            )}
          </li>
        </ul>
      </div>
    </div>
  );
};

export default Header;
