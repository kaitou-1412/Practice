import { useState, useContext } from "react";
import { Link } from "react-router-dom";
import RestaurantCard from "./cards/RestaurantCard";
import Shimmer from "./cards/Shimmer";
import { filterData } from "../utils/helper";
import useRestaurantCards from "../utils/useRestaurantCards";
import useOnline from "../utils/useOnline";
import UserContext from "../utils/UserContext";

const Body = () => {
  const [searchInput, setSearchInput] = useState("");
  const [restaurants, defaultRestaurants, setRestaurants] =
    useRestaurantCards();
  const { user, setUser } = useContext(UserContext);

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
      <div className="search-container p-5 bg-red-50">
        <input
          type="text"
          className="search-input"
          placeholder="Search"
          value={searchInput}
          onChange={(e) => setSearchInput(e.target.value)}
        />
        <button
          className="search-btn p-2 my-2 ml-5 bg-purple-800 text-white rounded-lg hover:bg-fuchsia-200 hover:text-black"
          onClick={() => {
            const data = filterData(searchInput, defaultRestaurants);
            setRestaurants(data);
          }}
        >
          Search
        </button>
        <input
          value={user.name}
          onChange={(e) =>
            setUser({
              ...user,
              name: e.target.value,
            })
          }
        ></input>
        <input
          value={user.email}
          onChange={(e) =>
            setUser({
              ...user,
              email: e.target.value,
            })
          }
        ></input>
      </div>
      {restaurants.length === 0 ? (
        <h1>No restaurant matches your search!</h1>
      ) : (
        <div className="flex flex-wrap">
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
