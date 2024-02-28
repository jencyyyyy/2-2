const mongoose = require('mongoose');

require('mongoose-currency').loadType(mongoose);
var Currency = mongoose.Types.Currency;

const promoSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true 
    },
    image:{
        type: String,
        required: true
    },
    label:{
        type: String,
        default: ''
    },
    price: {
        type : Currency,
        required: true,
        min:0 
    },
    description:{
        type: String,
        required: true
    },
    feature:{
        type: Boolean,
        default:false   
    }
    
})

module.exports = mongoose.model('promo', promoSchema);