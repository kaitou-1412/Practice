import { shimmer_card_unit } from "../../config";

const ShimmerCard = () => {
  return (
    <div className="w-52 h-80 p-3 m-3 shadow-lg rounded-xl bg-white">
      <div className="w-full h-24 bg-gray-200"></div>
      <h2 className="w-full h-6 mt-4 bg-gray-400"></h2>
      <h3 className="w-full h-1/3 mt-3 bg-gray-400"></h3>
      <h4 className="w-full h-4 mt-3 bg-gray-400"></h4>
    </div>
  );
};

const Shimmer = () => {
  return (
    <div className="flex-grow px-10 py-5 bg-black">
      <div data-testid="shimmer" className="flex flex-wrap justify-start">
        {new Array(shimmer_card_unit).fill(0).map((data, index) => {
          return <ShimmerCard key={index}></ShimmerCard>;
        })}
      </div>
    </div>
  );
};

export default Shimmer;
