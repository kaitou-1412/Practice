import { useEffect, useState } from "react";
import { useParams } from "react-router-dom";
import Shimmer from "./cards/Shimmer";
import { menu_api_URL, IMG_CDN_URL } from "../config";

const RestaurantMenu = () => {
  const { resId } = useParams();
  const [restaurant, setRestaurant] = useState(null);
  const [menu, setMenu] = useState([]);

  useEffect(() => {
    getRestaurantInfo();
  }, []);

  async function getRestaurantInfo() {
    try {
      const data = await fetch(menu_api_URL + resId.toString());
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
      console.log("restaurantData", restaurantData);
      console.log("menuData", menuData);
    } catch (error) {
      console.log(error);
    }
  }

  return !restaurant ? (
    <Shimmer />
  ) : (
    <div className="restaurant-menu-container">
      <div>
        <h2>{restaurant?.name}</h2>
        <img
          src={IMG_CDN_URL + restaurant?.cloudinaryImageId}
          alt="Restaurant Image"
        />
        <h3>{restaurant?.areaName}</h3>
        <h3>{restaurant?.city}</h3>
        <h3>{restaurant?.avgRating} stars</h3>
        <h3>{restaurant?.costForTwoMessage}</h3>
      </div>
      <div>
        <h1>Menu</h1>
        {menu &&
          menu?.map((category, categoryIndex) => (
            <div key={categoryIndex}>
              <h2>{category?.title}</h2>
              <ol>
                {category?.items?.map((item, itemIndex) => (
                  <li key={`${itemIndex} - ${item?.card?.info?.id}`}>
                    <p>
                      <strong>{item?.card?.info?.name}</strong>&#8377;{" "}
                      {item?.card?.info?.price / 100}
                    </p>
                    <p>{item?.card?.info?.description}</p>
                    {/* <img
                      src={IMG_CDN_URL + item?.card?.info?.imageId}
                      alt="Item Image"
                    /> */}
                  </li>
                ))}
              </ol>
            </div>
          ))}
      </div>
    </div>
  );
};

export default RestaurantMenu;
