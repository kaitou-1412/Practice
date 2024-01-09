import { useDispatch } from "react-redux";
import {
  increaseItemQuantity,
  decreaseItemQuantity,
  removeItem,
} from "../utils/cartSlice";
import { shortenText } from "../utils/helper";
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
    <div className="flex flex-col w-52 p-3 m-3 h-80 shadow-lg rounded-xl bg-white text-black border border-solid border-black">
      <img className="w-full" src={IMG_CDN_URL + imageId} />
      <h2 className="font-bold text-xl pt-2">{shortenText(name, 14)}</h2>
      <h3 className="text-sm h-1/2">{shortenText(description, 100)}</h3>
      <h4 className="justify-self-end font-medium text-md flex justify-between items-center">
        <span>&#8377; {price / 100}</span>
        <span className="w-16 px-1 border-2 border-double border-blue flex items-center justify-between rounded-full">
          <button
            className="hover:cursor-pointer"
            onClick={handleIncreaseQuantity}
          >
            ﹢
          </button>
          <span>{quantity}</span>
          <button
            className="hover:cursor-pointer"
            onClick={handleDecreaseQuantity}
          >
            ﹣
          </button>
        </span>
        <button className="hover:cursor-pointer" onClick={handleRemoveItem}>
          <img
            className="w-6 h-6"
            src="https://www.shutterstock.com/image-vector/trash-can-icon-symbol-delete-600nw-1454137346.jpg"
            alt="Delete"
          />
        </button>
      </h4>
    </div>
  );
};

export default FoodItem;
