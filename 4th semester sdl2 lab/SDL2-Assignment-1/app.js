const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());

//Connect to DataBase
mongoose.connect("mongodb://localhost/a1",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});

const connect = mongoose.connection;
connect.on("open",()=>{
    console.log("Database connected");
});


app.use(express.json());
//Import Routes here
const dishRouter = require('./routes/dishRouter');
const promoRouter = require('./routes/promoRouter');
const leaderRouter = require('./routes/leaderRouter');

app.use('/dishes', dishRouter);
app.use('/promotions', promoRouter);
app.use('/leader', leaderRouter);



//Start localhost
app.listen(3000,()=>{
    console.log("Localhost started..")
});

