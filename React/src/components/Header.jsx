import { useContext } from "react";
import { Link, useNavigate } from "react-router-dom";
import { useSelector } from "react-redux";
import Logo from "../assets/img/foodhouse.jpg";
import useOnline from "../utils/useOnline";
import UserContext from "../utils/UserContext";
import { getDictionaryLength } from "../utils/helper";

const Title = () => (
  <Link to="/">
    <img
      data-testid="logo"
      className="pl-2 w-24"
      src={Logo}
      alt="Food House Logo"
    />
  </Link>
);

/* <i class="fa-solid fa-cart-shopping"></i> */

const Header = ({ isLoggedin, setIsLoggedin }) => {
  const navigate = useNavigate();
  const isOnline = useOnline();
  const { user } = useContext(UserContext);
  const cartItems = useSelector((store) => store.cart);
  const numberOfItems = getDictionaryLength(cartItems);

  return (
    <div className="flex items-center justify-between bg-red-100 shadow-lg">
      <Title />
      <div className="nav-items">
        <ul className="flex">
          <li className="p-3">
            <Link to="/">Home</Link>
          </li>
          <li className="p-3">
            <Link to="/about">About</Link>
          </li>
          <li className="p-3">
            <Link to="/contact">Contact</Link>
          </li>
          <li className="p-3">
            <Link to="/instamart">Instamart</Link>
          </li>
          <li className="p-3">
            <Link to="/cart" data-testid="cart">
              Cart - {numberOfItems} items
            </Link>
          </li>
          <li data-testid="online-status" className="p-3">
            {isOnline ? "✅" : "❌"}
          </li>
          <li className="p-3 font-bold text-red-900">{user.name}</li>
          <li className="p-3">
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
