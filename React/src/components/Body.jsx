import { useEffect, useState } from "react";
import RestaurantCard from "./cards/RestaurantCard";
import Shimmer from "./cards/Shimmer";
import { swiggy_api_URL } from "../config";
import { Link } from "react-router-dom";

const filterData = (searchText, restaurants) => {
  return restaurants.filter((restaurant) =>
    restaurant?.name?.toLowerCase().includes(searchText?.toLowerCase())
  );
};

const Body = () => {
  const [defaultRestaurants, setDefaultRestaurants] = useState([]);
  const [restaurants, setRestaurants] = useState([]);
  const [searchInput, setSearchInput] = useState("");

  useEffect(() => {
    getRestaurants();
  }, []);

  async function getRestaurants() {
    // handle the error using try... catch
    try {
      const data = await fetch(swiggy_api_URL);
      const json = await data.json();
      const restaurants = json?.data?.cards
        ?.filter(
          (card) =>
            card?.card?.card["@type"] ===
              "type.googleapis.com/swiggy.gandalf.widgets.v2.GridWidget" &&
            card?.card?.card?.gridElements?.infoWithStyle["@type"] ===
              "type.googleapis.com/swiggy.presentation.food.v2.FavouriteRestaurantInfoWithStyle"
        )
        .map(
          (card) => card?.card?.card?.gridElements?.infoWithStyle?.restaurants
        )
        .flat()
        .map((restaurant) => restaurant?.info);
      setDefaultRestaurants(restaurants);
      setRestaurants(restaurants);
    } catch (error) {
      console.log(error);
    }
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
