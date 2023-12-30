export const filterData = (searchText, restaurants) => {
  return restaurants.filter((restaurant) =>
    restaurant?.name?.toLowerCase().includes(searchText?.toLowerCase())
  );
};
