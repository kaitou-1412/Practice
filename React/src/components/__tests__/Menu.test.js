import "@testing-library/jest-dom";
import { fireEvent, render, waitFor } from "@testing-library/react";
import { Provider } from "react-redux";
import { StaticRouter } from "react-router-dom/server";
import Header from "../Header";
import RestaurantMenu from "../RestaurantMenu";
import store from "../../utils/store";
import { MENU_DATA } from "../../mocks/data";

global.fetch = jest.fn(() =>
  Promise.resolve({
    json: () => Promise.resolve(MENU_DATA),
  })
);

test("Add items to cart", async () => {
  const restaurantMenuPage = render(
    <StaticRouter>
      <Provider store={store}>
        <Header />
        <RestaurantMenu />
      </Provider>
    </StaticRouter>
  );

  await waitFor(() => expect(restaurantMenuPage.getByTestId("menu")));

  const addBtn = restaurantMenuPage.getAllByTestId("addBtn");

  fireEvent.click(addBtn[0]);
  fireEvent.click(addBtn[2]);

  const cart = restaurantMenuPage.getByTestId("cart");
  expect(cart.innerHTML).toBe("Cart - 2 items");
});
