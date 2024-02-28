const mongoose = require('mongoose');

const dogSchema = new mongoose.Schema({
    name:{
        type: String,
        required:true,
        unique:true
    },
    age:{
        type: Number,
        required: true,
    },
    gender: {
        type: String,
        enum: ['male', 'female'],
        required: true
    }
});

module.exports= mongoose.model('Dogs',dogSchema);