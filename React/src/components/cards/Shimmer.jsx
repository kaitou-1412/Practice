import { shimmer_card_unit } from "../../config";

const ShimmerCard = () => {
  return (
    <div className="shimmer-card">
      <div className="shimmer-image"></div>
      <h2 className="shimmer-name"></h2>
      <h3 className="shimmer-cuisines"></h3>
      <h4 className="shimmer-rating"></h4>
    </div>
  );
};

const Shimmer = () => {
  return (
    <div className="restaurant-list">
      {new Array(shimmer_card_unit).fill(0).map((data, index) => {
        return <ShimmerCard key={index}></ShimmerCard>;
      })}
    </div>
  );
};

export default Shimmer;
