const express = require("express");
const app = express();
const dotenv = require('dotenv');
const mongoose = require('mongoose');

dotenv.config();

//Import ROutes
const authRoute = require('./routes/auth');
const postRoute = require('./routes/posts');


//Connect to DB
mongoose.connect("mongodb://localhost/3rdAssignmentSimilar",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});

const connect = mongoose.connection;

connect.on("open",()=>{
    console.log("Database connected");
});

//middlewares
app.use(express.json());


//Route Middlewares
app.use('/api/user', authRoute);
app.use('/api/posts', postRoute);



app.listen(3000,()=>
    console.log('Server Connected')
    );