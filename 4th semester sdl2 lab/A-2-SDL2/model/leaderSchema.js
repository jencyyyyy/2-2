const mongoose = require('mongoose');

const leaderSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true 
    },
    image:{
        type: String,
        required: true
    },
    designation:{
        type: String,
       required:true
    },
    abbr: {
        type : String,
        required: true,
    },
    description:{
        type: String,
       required:true
    },
    feature:{
        type: Boolean,
        default:false   
    }

})

module.exports= mongoose.model('leader',leaderSchema)