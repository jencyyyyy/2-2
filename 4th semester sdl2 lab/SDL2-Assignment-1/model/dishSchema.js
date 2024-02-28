const mongoose = require('mongoose');

require('mongoose-currency').loadType(mongoose);
var Currency = mongoose.Types.Currency;


const dishSchema = new mongoose.Schema({
    name:{
        type:String,
        required:true,
        unique:true
    },
    price:{
        type:Currency,
        required:true,
        min:0
    },
    quantity: {
        type: Number,
        required:true
    }
})

module.exports= mongoose.model('dish',dishSchema)