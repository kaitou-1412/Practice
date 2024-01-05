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

test("Remove items from cart", async () => {
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
  const removeBtn = restaurantMenuPage.getAllByTestId("removeBtn");

  fireEvent.click(addBtn[0]);
  fireEvent.click(addBtn[1]);
  fireEvent.click(addBtn[2]);

  const cart = restaurantMenuPage.getByTestId("cart");
  expect(cart.innerHTML).toBe("Cart - 3 items");

  fireEvent.click(removeBtn[0]);

  expect(cart.innerHTML).toBe("Cart - 2 items");
});
