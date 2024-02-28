const mongoose = require("mongoose");

const dishSchema = new mongoose.Schema({

    name:{
        type:String,
        required:true,
        unique:true
    },
    price:{
        type: "String",
        required:true
    },
    quantity:{
        type: Number,
        required:true
    }
})

module.exports= mongoose.model('dish',dishSchema);
