const express = require('express');
const router = express.Router();
const Dish = require('../model/dishSchema');

//Get the parameters of all dishes one by one
router.get('/',async(req,res)=>{
    try{
        const dish = await Dish.find();
        res.json(dish);
    }catch(err){
            res.json({message:err})
        }
});

//Get specific dish by ID
router.get('/:dishId',async(req,res)=>{
    try{
        const dish = await Dish.findById(req.params.dishId);
        res.json(dish);
    }catch(err){
            res.json({message:error});
        }
});

//Post the values of parameter of a new dish
router.post('/',async (req,res)=>{
     const dish = new Dish({        
         name: req.body.name ,
         price: req.body.price,
         quantity: req.body.quantity

     });
     try{
         const savedDishes = await dish.save();
         res.json(savedDishes);
     }catch(err){
         res.json({message:err})
     }      
 })

//delete a dish
router.delete('/:dishId',async (req,res)=>{
    try{
         const deleteDish= await Dish.findByIdAndDelete(req.params.dishId);
         res.json(deleteDish);
     }catch(err){
         res.json({message: err});
         //res.json(err.message);
     }
  });

//Update a post
router.put('/:dishId',async (req,res)=>{
    try{
        const updatedDish = await Dish.updateOne(
            {_id: req.params.dishId},
            {$set:  
                {
                    name: req.body.name,
                    price: req.body.price,
                    quantity: req.body.quantity
                } 
            });
        res.json(updatedDish);
     }
     catch(err){
         res.json({message: err});
     }
  });

module.exports = router;