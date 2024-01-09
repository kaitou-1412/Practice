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
    return (
      <div className="bg-blue text-white p-5 flex-grow">
        <h1 className="font-extrabold text-3xl py-5">
          🔴 Offline, Please check your internet connection!!!
        </h1>
      </div>
    );
  }

  // Early return
  if (!defaultRestaurants) return null;

  return defaultRestaurants.length === 0 ? (
    <Shimmer />
  ) : (
    <div className="flex-grow flex flex-col">
      <div className="search-container p-5 w-full bg-white flex items-center justify-between">
        <div>
          {" "}
          <input
            data-testid="search-input"
            type="text"
            className="search-input text-black h-8 pl-2 rounded-md border border-solid border-black focus:border focus:border-solid focus:border-blue"
            placeholder="Search"
            value={searchInput}
            onChange={(e) => setSearchInput(e.target.value)}
          />
          <button
            data-testid="search-btn"
            className="search-btn p-2 my-2 ml-5 bg-blue text-white rounded-lg hover:bg-green"
            onClick={() => {
              const data = filterData(searchInput, defaultRestaurants);
              setRestaurants(data);
            }}
          >
            Search
          </button>
        </div>
        <div>
          <input
            className="text-black text-center px-2 mx-2 rounded-full border border-black"
            value={user.name}
            onChange={(e) =>
              setUser({
                ...user,
                name: e.target.value,
              })
            }
          ></input>
          <input
            className="text-black mx-2 px-2 rounded-full border border-black"
            value={user.email}
            onChange={(e) =>
              setUser({
                ...user,
                email: e.target.value,
              })
            }
          ></input>
        </div>
      </div>
      {restaurants.length === 0 ? (
        <div className="bg-blue text-white p-5 flex-grow">
          <h1 className="font-extrabold text-3xl py-5">
            No restaurant matches your search!
          </h1>
        </div>
      ) : (
        <div className="px-10 py-5 bg-blue flex-grow">
          <div
            data-testid="restaurant-list"
            className="flex flex-wrap justify-start"
          >
            {restaurants.map((restaurant, index) => (
              <Link
                key={`${index}-${restaurant.id}`}
                to={`/restaurant/${restaurant.id}`}
              >
                <RestaurantCard {...restaurant} />
              </Link>
            ))}
          </div>
        </div>
      )}
    </div>
  );
};

export default Body;
