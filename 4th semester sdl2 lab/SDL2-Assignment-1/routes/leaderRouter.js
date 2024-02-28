const express = require('express');
const router = express.Router();
const Leader = require('../model/leaderSchema');

//Get the parameters of all dishes one by one
router.get('/',async(req,res)=>{
    try{
        const leaders = await Leader.find();
        res.json(leaders);
    }catch(err){
            res.json({message:error})
        }
});

//Get specific dish by ID
router.get('/:leaderId',async(req,res)=>{
    try{
        const leader = await Leader.findById(req.params.leaderId);
        res.json(leader);
    }catch(err){
            res.json({message:error});
            console.log(res.statusCode);
        }
});

//Post the values of parameter of a new dish
router.post('/',async (req,res)=>{
     const LeaderData = new Leader({        
        name: req.body.name ,
        designation: req.body.designation,
        age: req.body.age

     })
     try{
         const postLeader = await LeaderData.save();
         res.json(postLeader);
         console.log("leader saved, status: " + res.statusCode);

     }catch(err){
        res.json({message:err})
        console.log(res.statusCode);
     }      
 })

//delete a dish
router.delete('/:leaderId',async (req,res)=>{
    try{
         const deleteLeader= await Leader.findByIdAndDelete(req.params.leaderId);
         res.json(deleteLeader);
     }catch(err){
         res.json({message: err});
         //res.json(err.message);
     }
  });

//Update a post
router.put('/:leaderId',async (req,res)=>{
    try{
        const updatedLeader = await Leader.updateOne(
            {_id: req.params.leaderId},
            {$set:  
                {
                    name: req.body.name,
                    designation: req.body.designation,
                    age: req.body.age
                } 
            });
        res.json(updatedLeader);
     }
     catch(err){
        res.json({message: err});
     }
  });

module.exports = router;