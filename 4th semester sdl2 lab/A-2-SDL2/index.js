const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());

//Connect to DataBase

mongoose.connect("mongodb://localhost/assignment2",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});

/*
var promise = mongoose.connect('mongodb://localhost/assignment2', {
  useMongoClient: true,

});
*/
const connect = mongoose.connection;

connect.on("open",()=>{
    console.log("Database connected");
});

app.use(express.json());
//Import Routes here
const promoRouter = require('./routes/promoRouter');
const leaderRouter = require('./routes/leaderRouter');

app.use('/promotions', promoRouter);
app.use('/leaders', leaderRouter);



//Start localhost
app.listen(3000,()=>{
    console.log("Localhost started..");
});
