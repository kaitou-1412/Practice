import React, { useState, lazy, Suspense } from "react";
import ReactDOM from "react-dom/client";
import { createBrowserRouter, RouterProvider, Outlet } from "react-router-dom";
import Header from "./components/Header";
import Body from "./components/Body";
import Footer from "./components/Footer";
import Contact from "./components/Contact";
import RestaurantMenu from "./components/RestaurantMenu";
import Profile from "./components/Profile";
import ProfileClassComponent from "./components/ProfileClass";
import Login from "./components/Login";
import Error from "./components/Error";
import Shimmer from "./components/cards/Shimmer";
import UserContext from "./utils/UserContext";

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

// Chunking/Code Splitting/Dynamic Bundling/Dynamic Import/On Demand Loading/Lazy Loading
const Instamart = lazy(() => import("./components/Instamart"));
const About = lazy(() => import("./components/About"));

// AppLayout component to show: Header, Body, Footer
const AppLayout = () => {
  const [isLoggedin, setIsLoggedin] = useState(false);
  const [user, setUser] = useState({
    name: "Ruban Sahoo",
    email: "ruban1work@gmail.com",
  });

  return (
    <UserContext.Provider value={{ user: user, setUser: setUser }}>
      <Header isLoggedin={isLoggedin} setIsLoggedin={setIsLoggedin} />
      <Outlet context={[setIsLoggedin]} />
      <Footer />
    </UserContext.Provider>
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
        element: (
          <Suspense fallback={<h1>Loading...</h1>}>
            <About />
          </Suspense>
        ),
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
      {
        path: "/instamart",
        element: (
          <Suspense fallback={<Shimmer />}>
            <Instamart />
          </Suspense>
        ),
      },
    ],
  },
  ,
]);

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<RouterProvider router={appRouter} />);
