import { useSelector, useDispatch } from "react-redux";
import { clearCart } from "../utils/cartSlice";
import { getDictionaryLength } from "../utils/helper";
import FoodItem from "./FoodItem";

const Cart = () => {
  const cartItems = useSelector((store) => store.cart);
  const dispatch = useDispatch();
  const handleClearCart = () => {
    dispatch(clearCart());
  };
  const numberOfItems = getDictionaryLength(cartItems);

  return (
    <div className="flex-grow bg-blue p-5">
      <h1 className="font-bold text-3xl text-white">
        Cart Items - {numberOfItems > 0 ? numberOfItems : "Empty"}
      </h1>
      {numberOfItems > 0 && (
        <button
          className="p-2 m-5 bg-green text-white"
          onClick={handleClearCart}
        >
          Clear Cart
        </button>
      )}
      <div className="flex flex-wrap">
        {Object.values(cartItems).map(({ item, quantity }, index) => (
          <FoodItem
            key={`${index} - ${item.id}`}
            {...item}
            quantity={quantity}
          />
        ))}
      </div>
    </div>
  );
};

export default Cart;
