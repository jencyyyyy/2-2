const express = require("express");
const mongoose = require("mongoose");
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());



mongoose.connect("mongodb://localhost/groupStudy",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});

const connect = mongoose.connection;
connect.on("open",()=>{
    console.log("Database Connected");
})

app.use(express.json());
//Import all routes
const dishRoutes = require('./routers/dishRouter');

app.use('/dishes',dishRoutes);


app.listen(3000,()=>{
    console.log("Localhost connected");
})

