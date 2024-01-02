import { useParams } from "react-router-dom";
import { useDispatch, useSelector } from "react-redux";
import Shimmer from "./cards/Shimmer";
import { IMG_CDN_URL } from "../config";
import useRestaurantInfo from "../utils/useRestaurantInfo";
import {
  increaseItemQuantity,
  decreaseItemQuantity,
  removeItem,
} from "../utils/cartSlice";

const RestaurantMenu = () => {
  const { resId } = useParams();
  const [restaurant, menu] = useRestaurantInfo(resId);

  const cartItems = useSelector((store) => store.cart);
  const dispatch = useDispatch();
  const handleIncreaseQuantity = (item) => {
    dispatch(increaseItemQuantity(item));
  };
  const handleDecreaseQuantity = (item) => {
    dispatch(decreaseItemQuantity(item));
  };
  const handleRemoveItem = (item) => {
    dispatch(removeItem(item));
  };

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
                      <strong>{item?.card?.info?.name}</strong>
                      <span className="mx-5 bg-orange-300">
                        &#8377; {item?.card?.info?.price / 100}
                      </span>
                      {cartItems[item?.card?.info?.id] && (
                        <span className="bg-slate-400">
                          Q: {cartItems[item?.card?.info?.id].quantity} items
                        </span>
                      )}
                      <span>
                        <button
                          className="mx-5 bg-green-100"
                          onClick={() =>
                            handleIncreaseQuantity(item?.card?.info)
                          }
                        >
                          ➕
                        </button>
                        <button
                          className="mx-5 bg-red-100"
                          onClick={() =>
                            handleDecreaseQuantity(item?.card?.info)
                          }
                        >
                          ➖
                        </button>
                        <button
                          className="mx-5 bg-blue-100"
                          onClick={() => handleRemoveItem(item?.card?.info)}
                        >
                          ⛌
                        </button>
                      </span>
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
