import { useState } from "react";
import { useParams } from "react-router-dom";
import { useDispatch, useSelector } from "react-redux";
import Shimmer from "./cards/Shimmer";
import { IMG_CDN_URL } from "../config";
import useRestaurantInfo from "../utils/useRestaurantInfo";
import { increaseItemQuantity, decreaseItemQuantity } from "../utils/cartSlice";

const RestaurantMenu = () => {
  const { resId } = useParams();
  const [restaurant, menu] = useRestaurantInfo(resId);
  const [visibleSection, setIsVisibleSection] = useState(0);

  const cartItems = useSelector((store) => store.cart);
  const dispatch = useDispatch();
  const handleIncreaseQuantity = (item) => {
    dispatch(increaseItemQuantity(item));
  };
  const handleDecreaseQuantity = (item) => {
    dispatch(decreaseItemQuantity(item));
  };

  return !restaurant ? (
    <Shimmer />
  ) : (
    <div data-testid="menu" className="flex bg-blue text-white flex-grow">
      <div className="p-5">
        <h2 className="font-extrabold text-3xl">{restaurant?.name}</h2>
        <img
          className="py-5"
          src={IMG_CDN_URL + restaurant?.cloudinaryImageId}
          alt="Restaurant Image"
        />
        <div className="flex justify-between">
          <span className="font-medium text-xl">
            {restaurant?.areaName + ", " + restaurant?.city}
          </span>
          <span>{restaurant?.avgRating} stars</span>
        </div>
        <h3>{restaurant?.costForTwoMessage}</h3>
      </div>
      <div className="p-5 w-2/3">
        {menu.length > 0 && <h1 className="font-bold text-3xl">Menu</h1>}
        <ul className="pt-3">
          {menu &&
            menu?.map((category, categoryIndex) => (
              <li
                className={
                  "py-5 px-2 my-2 rounded-lg bg-white text-black" +
                  (visibleSection === categoryIndex
                    ? " border border-solid border-white"
                    : "")
                }
                key={categoryIndex}
              >
                <div className="flex items-center justify-between font-bold text-2xl">
                  <span>{category?.title}</span>
                  <button
                    onClick={() =>
                      setIsVisibleSection(
                        visibleSection === categoryIndex ? -1 : categoryIndex
                      )
                    }
                    className="cursor-pointer"
                  >
                    {visibleSection === categoryIndex ? "🔼" : "🔽"}
                  </button>
                </div>
                {visibleSection === categoryIndex && (
                  <ol>
                    {category?.items?.map((item, itemIndex) => (
                      <li
                        key={`${itemIndex} - ${item?.card?.info?.id}`}
                        className="text-white px-5 py-2 my-2 bg-black rounded-lg"
                      >
                        <div className="flex justify-between py-1">
                          <div className="font-medium text-xl">
                            {item?.card?.info?.name}
                          </div>
                          <div className="flex items-center">
                            <span className="mx-5">
                              &#8377; {item?.card?.info?.price / 100}
                            </span>
                            {cartItems[item?.card?.info?.id] ? (
                              <div className="w-16 px-1 bg-white text-black border-2 border-double border-blue flex items-center justify-between rounded-full">
                                <button
                                  data-testid="addBtn"
                                  className="py-1"
                                  onClick={() =>
                                    handleIncreaseQuantity(item?.card?.info)
                                  }
                                >
                                  ➕
                                </button>
                                <span className="text-center">
                                  {cartItems[item?.card?.info?.id].quantity}
                                </span>
                                <button
                                  className="py-1"
                                  onClick={() =>
                                    handleDecreaseQuantity(item?.card?.info)
                                  }
                                >
                                  ➖
                                </button>
                              </div>
                            ) : (
                              <button
                                data-testid="addBtn"
                                className="w-16 py-1 bg-green text-white rounded-full"
                                onClick={() =>
                                  handleIncreaseQuantity(item?.card?.info)
                                }
                              >
                                Add
                              </button>
                            )}
                          </div>
                        </div>

                        {item?.card?.info?.imageId && (
                          <div className="py-4">
                            <img
                              className="w-64"
                              src={IMG_CDN_URL + item?.card?.info?.imageId}
                              alt="Item Image"
                            />
                          </div>
                        )}

                        {item?.card?.info?.description && (
                          <p className="py-1">
                            {item?.card?.info?.description}
                          </p>
                        )}
                      </li>
                    ))}
                  </ol>
                )}
              </li>
            ))}
        </ul>
      </div>
    </div>
  );
};

export default RestaurantMenu;
