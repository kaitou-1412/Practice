import { useParams } from "react-router-dom";
import Shimmer from "./cards/Shimmer";
import { IMG_CDN_URL } from "../config";
import useRestaurantInfo from "../utils/useRestaurantInfo";

const RestaurantMenu = () => {
  const { resId } = useParams();
  const [restaurant, menu] = useRestaurantInfo(resId);

  return !restaurant ? (
    <Shimmer />
  ) : (
    <div className="flex">
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
