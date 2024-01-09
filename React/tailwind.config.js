/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./**/*.{html,js,jsx}", "./src/**/*.{html,js,jsx}"],
  theme: {
    extend: {
      colors: {
        black: "#152A38",
        blue: "#29435C",
        green: "#556E53",
        white: "#D1D4C9",
      },
    },
  },
  plugins: [],
};
