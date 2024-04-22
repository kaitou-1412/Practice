const express = require("express");
const app = express();

const bodyParser = require("body-parser");
const multer = require("multer"); // v1.0.5
const upload = multer(); // for parsing multipart/form-data

app.use(bodyParser.json()); // for parsing application/json
app.use(bodyParser.urlencoded({ extended: true })); // for parsing application/x-www-form-urlencoded

const productRoute = require("./routes/products.js");

const dotenv = require("dotenv");
dotenv.config();

const port = process.env.PORT;
const db_uri = process.env.DB_URI;

const mongoose = require("mongoose");
mongoose
  .connect(db_uri)
  .then(() => {
    console.log("Connected to the database!");
    app.listen(port, () => {
      console.log(`Server is running on port ${port}`);
    });
  })
  .catch(() => {
    console.log("Connection to the database failed !");
  });

// routes
app.use("/api/products", productRoute);

app.get("/", (req, res) => {
  res.send("Hello World!");
});
