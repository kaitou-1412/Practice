import { useDispatch } from "react-redux";
import {
  increaseItemQuantity,
  decreaseItemQuantity,
  removeItem,
} from "../utils/cartSlice";
import { IMG_CDN_URL } from "../config";

const FoodItem = ({ id, name, description, imageId, price, quantity }) => {
  const dispatch = useDispatch();

  const handleIncreaseQuantity = () => {
    dispatch(increaseItemQuantity({ id: id }));
  };
  const handleDecreaseQuantity = () => {
    dispatch(decreaseItemQuantity({ id: id }));
  };
  const handleRemoveItem = () => {
    dispatch(removeItem({ id: id }));
  };

  return (
    <div className="w-56 p-2 m-2 shadow-lg bg-pink-50">
      <img className="w-full" src={IMG_CDN_URL + imageId} />
      <h2 className="font-bold text-xl">{name}</h2>
      <h3>{description}</h3>
      <h4>Rupees: {price / 100}</h4>
      <h4>Quantity: {quantity}</h4>
      <h5>
        <button
          className="mx-5 bg-green-300 hover:cursor-pointer"
          onClick={handleIncreaseQuantity}
        >
          ﹢
        </button>
        <button
          className="mx-5 bg-red-400 hover:cursor-pointer"
          onClick={handleDecreaseQuantity}
        >
          ﹣
        </button>
        <button
          className="mx-5 bg-blue-400 hover:cursor-pointer"
          onClick={handleRemoveItem}
        >
          ❌
        </button>
      </h5>
    </div>
  );
};

export default FoodItem;
