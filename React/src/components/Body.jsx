import { useState } from "react";
import { Link } from "react-router-dom";
import RestaurantCard from "./cards/RestaurantCard";
import Shimmer from "./cards/Shimmer";
import { filterData } from "../utils/helper";
import useRestaurantCards from "../utils/useRestaurantCards";
import useOnline from "../utils/useOnline";

const Body = () => {
  const [searchInput, setSearchInput] = useState("");
  const [restaurants, defaultRestaurants] = useRestaurantCards();

  const online = useOnline();

  if (!online) {
    return <h1>🔴 Offline, Please check your internet connection!!!</h1>;
  }

  // Early return
  if (!defaultRestaurants) return null;

  return defaultRestaurants.length === 0 ? (
    <Shimmer />
  ) : (
    <>
      <div className="search-container">
        <input
          type="text"
          className="search-input"
          placeholder="Search"
          value={searchInput}
          onChange={(e) => setSearchInput(e.target.value)}
        />
        <button
          className="search-btn"
          onClick={() => {
            const data = filterData(searchInput, defaultRestaurants);
            setRestaurants(data);
          }}
        >
          Search
        </button>
      </div>
      {restaurants.length === 0 ? (
        <h1>No restaurant matches your search!</h1>
      ) : (
        <div className="restaurant-list">
          {restaurants.map((restaurant, index) => (
            <Link
              key={`${index}-${restaurant.id}`}
              to={`/restaurant/${restaurant.id}`}
            >
              <RestaurantCard {...restaurant} />
            </Link>
          ))}
        </div>
      )}
    </>
  );
};

export default Body;
