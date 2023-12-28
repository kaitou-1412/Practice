import React, { useState } from "react";
import ReactDOM from "react-dom/client";
import Header from "./components/Header";
import Body from "./components/Body";
import Footer from "./components/Footer";
import About from "./components/About";
import Contact from "./components/Contact";
import RestaurantMenu from "./components/RestaurantMenu";
import Profile from "./components/Profile";
import ProfileClassComponent from "./components/ProfileClass";
import Login from "./components/Login";
import Error from "./components/Error";
import { createBrowserRouter, RouterProvider, Outlet } from "react-router-dom";

/* My Food App structure will look like this, 
  1) Header
      - Logo
      - Nav Items(right side)
      - Cart
  2) Body
      - Search bar
      - Restaurants List
          - Restaurant card
              - Image
              - Name
              - Rating
  3) Footer
      - Links
      - Copyrights
       
*/

// AppLayout component to show: Header, Body, Footer
const AppLayout = () => {
  const [isLoggedin, setIsLoggedin] = useState(false);

  return (
    <React.Fragment>
      <Header isLoggedin={isLoggedin} setIsLoggedin={setIsLoggedin} />
      <Outlet context={[setIsLoggedin]} />
      <Footer />
    </React.Fragment>
  );
};

const appRouter = createBrowserRouter([
  {
    path: "/",
    element: <AppLayout />,
    errorElement: <Error />,
    children: [
      {
        path: "/",
        element: <Body />,
      },
      {
        path: "/about",
        element: <About />,
        children: [
          {
            path: "profile",
            element: (
              <>
                <Profile name="Ruban" />
                <ProfileClassComponent name="First Child" />
              </>
            ),
          },
        ],
      },
      {
        path: "/contact",
        element: <Contact />,
      },
      {
        path: "/login",
        element: <Login />,
      },
      {
        path: "/restaurant/:resId",
        element: <RestaurantMenu />,
      },
    ],
  },
  ,
]);

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<RouterProvider router={appRouter} />);
