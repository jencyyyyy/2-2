const express = require('express');
const router = express.Router();

const verify = require('../verifyToken');

router.get('/',verify, (req,res) =>{
   
    res.send(req.user);
    /*res.json({
        posts:{
            title: 'my first post',
            description: 'random data you shouldnt access'
        }
    });*/

});


module.exports = router;