import React from "react";
import ReactDOM from "react-dom/client";
import { restaurantList, CLOUDINARY_BASE_URL } from "./data";

/* My Food App structure will look like this, 
  1) Header
      - Logo
      - Nav Items(right side)
      - Cart
  2) Body
      - Search bar
      - Restaurants List
          - Restaurant card
              - Image
              - Name
              - Rating
  3) Footer
      - Links
      - Copyrights
       
*/

const Title = () => (
  <a href="/">
    <img
      className="logo"
      src="https://foodhouse.co.th/wp-content/uploads/2019/01/foodhouse-18.jpg"
      alt="Food Fire Logo"
    />
  </a>
);

const Header = () => (
  <div className="header">
    <Title />
    <div className="nav-items">
      <ul>
        <li>Home</li>
        <li>About</li>
        <li>Contact</li>
        <li>
          Cart
          {/* <i class="fa-solid fa-cart-shopping"></i> */}
        </li>
      </ul>
    </div>
  </div>
);

const RestaurantCard = ({ name, cloudinaryImageId, cuisines, avgRating }) => {
  return (
    <div className="card">
      <img src={CLOUDINARY_BASE_URL + cloudinaryImageId} />
      <h2>{name}</h2>
      <h3>{cuisines.join(", ")}</h3>
      <h4>{`${avgRating} stars`}</h4>
    </div>
  );
};

const Body = () => {
  const restaurants = restaurantList
    .filter((restaurant) => restaurant.type === "restaurant")
    .map((restaurant) => restaurant.data);
  return (
    <div className="restaurant-list">
      {restaurants.map((restaurant) => (
        <RestaurantCard key={restaurant.id} {...restaurant} />
      ))}
    </div>
  );
};

const Footer = () => <h4>Footer</h4>;

// AppLayout component to show: Header, Body, Footer
const AppLayout = () => {
  return (
    <React.Fragment>
      <Header />
      <Body />
      <Footer />
    </React.Fragment>
  );
};

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<AppLayout />);
