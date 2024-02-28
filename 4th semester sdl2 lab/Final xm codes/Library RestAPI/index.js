const express = require('express');
const mongoose = require('mongoose');
const parser = require('body-parser');

const file = express();
file.use(parser.json());
file.use(express.json());

mongoose.connect("mongodb://localhost:/LibraryDataBase",{
    useNewUrlParser: true,
    useUnifiedTopology: true
});


const connected = mongoose.connection;

connected.on("open",()=>{
    console.log("Connected to database");
});

file.use('/books',require('./Routes/bookRoute'));


file.listen(3000,()=>{
    console.log("Started the LocalHost");
})

