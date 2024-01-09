import { useContext } from "react";
import UserContext from "../../utils/UserContext";
import { IMG_CDN_URL } from "../../config";
import { shortenText } from "../../utils/helper";

const RestaurantCard = ({ name, cloudinaryImageId, cuisines, avgRating }) => {
  const { user } = useContext(UserContext);

  return (
    <div className="flex flex-col w-52 p-3 m-3 h-80 shadow-lg rounded-xl bg-white text-black border border-solid border-black">
      <img className="w-full" src={IMG_CDN_URL + cloudinaryImageId} />
      <h2 className="font-bold text-xl pt-2">{shortenText(name, 14)}</h2>
      <h3 className="text-sm h-1/2">{shortenText(cuisines.join(", "), 100)}</h3>
      <h4 className="justify-self-end font-medium text-md">{`${avgRating} stars`}</h4>
      {/* <h5 className="font-bold">
        {user.name} - {user.email}
      </h5> */}
    </div>
  );
};

export default RestaurantCard;
