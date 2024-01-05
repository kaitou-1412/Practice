import { shimmer_card_unit } from "../../config";

const ShimmerCard = () => {
  return (
    <div className="w-52 h-52 p-3 m-3 shadow-lg rounded-xl">
      <div className="w-full h-24 bg-gray-400"></div>
      <h2 className="w-full h-5 mt-4 bg-gray-200"></h2>
      <h3 className="w-full h-3 mt-3 bg-gray-200"></h3>
      <h4 className="w-full h-2 mt-2 bg-gray-200"></h4>
    </div>
  );
};

const Shimmer = () => {
  return (
    <div data-testid="shimmer" className="flex flex-wrap">
      {new Array(shimmer_card_unit).fill(0).map((data, index) => {
        return <ShimmerCard key={index}></ShimmerCard>;
      })}
    </div>
  );
};

export default Shimmer;
