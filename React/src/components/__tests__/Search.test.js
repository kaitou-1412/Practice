import "@testing-library/jest-dom";
import { fireEvent, render, waitFor } from "@testing-library/react";
import { Provider } from "react-redux";
import { StaticRouter } from "react-router-dom/server";
import Body from "../Body";
import store from "../../utils/store";
import { RESTAURANT_DATA } from "../../mocks/data";
import { shimmer_card_unit } from "../../config";

global.fetch = jest.fn(() =>
  Promise.resolve({
    json: () => Promise.resolve(RESTAURANT_DATA),
  })
);

test("Shimmer should load on homepage", () => {
  const body = render(
    <StaticRouter>
      <Provider store={store}>
        <Body />
      </Provider>
    </StaticRouter>
  );
  const shimmer = body.getByTestId("shimmer");
  expect(shimmer.children.length).toBe(shimmer_card_unit);
});

test("Restaurants should load on homepage", async () => {
  const body = render(
    <StaticRouter>
      <Provider store={store}>
        <Body />
      </Provider>
    </StaticRouter>
  );

  await waitFor(() => expect(body.getByTestId("search-btn")));

  const restaurantList = body.getByTestId("restaurant-list");
  expect(restaurantList.children.length).toBe(29);
});

test("Search for string(food) on homepage", async () => {
  const body = render(
    <StaticRouter>
      <Provider store={store}>
        <Body />
      </Provider>
    </StaticRouter>
  );

  await waitFor(() => expect(body.getByTestId("search-btn")));

  const input = body.getByTestId("search-input");
  fireEvent.change(input, { target: { value: "food" } });

  const searchBtn = body.getByTestId("search-btn");
  fireEvent.click(searchBtn);

  const restaurantList = body.getByTestId("restaurant-list");
  expect(restaurantList.children.length).toBe(1);
});
