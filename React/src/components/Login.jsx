import React from "react";
import { useNavigate, useOutletContext } from "react-router-dom";
import { Formik, Form, Field, ErrorMessage } from "formik";

const Login = () => {
  const navigate = useNavigate();
  const [setIsLoggedin] = useOutletContext();

  function handleNavigate(values) {
    // Alert the input values of the form that we filled
    alert(values);
    // setTimeout for navigate from login page to home page
    setTimeout(function () {
      setIsLoggedin(true);
      navigate("/");
    }, 0);
  }

  return (
    <div className="flex-grow bg-blue text-white p-5">
      <h1 className="font-extrabold text-3xl py-5">Login Page</h1>
      <Formik
        initialValues={{ email: "", password: "" }}
        validate={(values) => {
          const errors = {};
          if (!values.email) {
            errors.email = "Required";
          } else if (
            !/^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$/i.test(values.email)
          ) {
            errors.email = "Invalid email address";
          }
          if (!values.password) {
            errors.password = "Required";
          } else if (values.password.length < 5) {
            errors.password = "Password must be atleast 5 characters long";
          }
          return errors;
        }}
        onSubmit={(values) => {
          // call handleNavigate and pass input filed data
          handleNavigate(JSON.stringify(values));
        }}
      >
        {({ isSubmitting }) => (
          <Form className="flex flex-col items-start justify-around w-80 h-48">
            <Field
              type="email"
              name="email"
              placeholder="Email"
              className="w-full h-8 rounded-lg px-5"
            />
            <ErrorMessage name="email" component="div" />
            <Field
              type="password"
              name="password"
              placeholder="Password"
              className="w-full h-8 rounded-lg px-5"
            />
            <ErrorMessage name="password" component="div" />
            <button
              className="bg-white text-black px-5 py-1 self-center rounded-full"
              type="submit"
              disabled={isSubmitting}
            >
              Submit
            </button>
          </Form>
        )}
      </Formik>
    </div>
  );
};

export default Login;
