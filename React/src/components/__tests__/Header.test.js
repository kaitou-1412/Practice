import { StaticRouter } from "react-router-dom/server";
import { Provider } from "react-redux";
import { render } from "@testing-library/react";
import Header from "../Header";
import store from "../../utils/store";

test("Logo should load on rendering header", () => {
  // Load Header Component
  // get the virtual DOM object for our header component
  const header = render(
    <StaticRouter>
      <Provider store={store}>
        <Header />
      </Provider>
    </StaticRouter>
  );

  // check if logo is loaded
  const logo = header.getAllByTestId("logo")[0];
  expect(logo.src).toBe(window.location.origin + "/" + "dummy.jpg");
});

test("Online status should be green on rendering header", () => {
  // Load Header Component
  // get the virtual DOM object for our header component
  const header = render(
    <StaticRouter>
      <Provider store={store}>
        <Header />
      </Provider>
    </StaticRouter>
  );

  // check if online status is green
  const onlineStatus = header.getByTestId("online-status");
  expect(onlineStatus.innerHTML).toBe("✅");
});

test("Cart should have 0 items on rendering header", () => {
  // Load Header Component
  // get the virtual DOM object for our header component
  const header = render(
    <StaticRouter>
      <Provider store={store}>
        <Header />
      </Provider>
    </StaticRouter>
  );

  // check if cart is having 0 items
  const cart = header.getByTestId("cart");
  expect(cart.innerHTML).toBe("Cart - 0 items");
});
