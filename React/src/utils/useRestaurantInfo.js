import { useEffect, useState } from "react";
import { FETCH_MENU_URL } from "../config";

const useRestaurantInfo = (resId) => {
  const [restaurant, setRestaurant] = useState(null);
  const [menu, setMenu] = useState([]);

  useEffect(() => {
    getRestaurantInfo();
  }, []);

  async function getRestaurantInfo() {
    try {
      const data = await fetch(FETCH_MENU_URL + resId);
      const json = await data.json();
      const restaurantData = json?.data?.cards
        ?.filter(
          (card) =>
            card?.card?.card["@type"] ===
            "type.googleapis.com/swiggy.presentation.food.v2.Restaurant"
        )
        .map((card) => card?.card?.card?.info)[0];
      const menuData = json?.data?.cards
        ?.filter((card) => card?.hasOwnProperty("groupedCard"))[0]
        ?.groupedCard?.cardGroupMap?.REGULAR?.cards?.filter(
          (card) =>
            card?.card?.card["@type"] ===
            "type.googleapis.com/swiggy.presentation.food.v2.ItemCategory"
        )
        ?.map((card) => {
          return {
            title: card?.card?.card?.title,
            items: card?.card?.card?.itemCards,
          };
        });
      setRestaurant(restaurantData);
      setMenu(menuData);
    } catch (error) {
      console.log(error);
    }
  }

  return [restaurant, menu];
};

export default useRestaurantInfo;
