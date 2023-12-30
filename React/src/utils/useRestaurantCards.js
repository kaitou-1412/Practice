import { useEffect, useState } from "react";
import { swiggy_api_URL } from "../config";

const useRestaurantCards = () => {
  const [defaultRestaurants, setDefaultRestaurants] = useState([]);
  const [restaurants, setRestaurants] = useState([]);

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

  return [restaurants, defaultRestaurants];
};

export default useRestaurantCards;
