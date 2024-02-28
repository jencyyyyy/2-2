//Making a Schema for book
// contains all charecteristics of Book

const mongoose = require('mongoose');

const bookSchema =new mongoose.Schema({
    name:{
        type: String,
        required: true,
        unique:true
    },
    price:{
        type:Number,
        required: true
    },
    author:{
        type: String,
        required: true
    }
})

module.exports = mongoose.model("BookList",bookSchema);