const express = require("express");
const dishRouter = express.Router();

const Dish = require('../models/dishSchema');

//Get 
dishRouter.get('/',async(req,res)=>{
    try{
        const dish = await Dish.find();
        res.json(dish);
    }catch(err){
        res.json({message:err})
    }
})

//Post
dishRouter.post('/',async (req,res)=>{
    
    const dish =new Dish({
        name: req.body.name,
        price:req.body.price,
        quantity:req.body.quantity
    });

    try{
        const saveDish = await dish.save();
        res.json(saveDish);
    }catch(err){
        res.json({message:err})
    }  
})



module.exports = dishRouter;