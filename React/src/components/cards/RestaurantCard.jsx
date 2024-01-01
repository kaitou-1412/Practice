import { useContext } from "react";
import UserContext from "../../utils/UserContext";
import { IMG_CDN_URL } from "../../config";

const RestaurantCard = ({ name, cloudinaryImageId, cuisines, avgRating }) => {
  const { user } = useContext(UserContext);

  return (
    <div className="w-52 p-3 m-3 shadow-lg rounded-xl bg-red-50">
      <img className="w-full" src={IMG_CDN_URL + cloudinaryImageId} />
      <h2 className="font-bold text-xl pt-2 ">{name}</h2>
      <h3 className="text-sm">{cuisines.join(", ")}</h3>
      <h4 className="font-medium text-md">{`${avgRating} stars`}</h4>
      <h5 className="font-bold">
        {user.name} - {user.email}
      </h5>
    </div>
  );
};

export default RestaurantCard;
