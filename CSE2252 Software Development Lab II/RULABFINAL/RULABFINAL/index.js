//Create const values for accessing the packages we just installed

const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');


//Using the const for the operations
const app = express();
app.use(bodyParser.json());
app.use(express.json());

mongoose.connect("mongodb://localhost:/DoggsDB",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});


const connect = mongoose.connection;
connect.on("open",()=>{
    console.log("Database connected");
});

const dogRouter = require('./routes/dogRoute');
app.use('/api/dogs', dogRouter);


//Start localhost
app.listen(3000,()=>{
    console.log("Localhost started..")
});
