const express = require('express');
const router = express.Router();
const Dogs = require('../model/dogSchema');


//Operations for api/dogs route
//Post operation
router.post('/', async (req,res)=>{
    const dog = new Dogs({
        name: req.body.name ,
        age: req.body.age ,
        gender: req.body.gender
    });

    try{
        const savedDogs = await dog.save();
        res.json(savedDogs);
    }catch(err){
        res.json({message:err})
    } 
});
//get operation
router.get('/', async (req,res)=>{
     try{
         const dog = await Dogs.find();
         res.json(dog);
     }catch(error){
         res.json({message:error});
     }
 
 })
//put operation
router.put('/',async(req, res) => {
    res.send('PUT operation not supported on /api/dogs');
})

//delete operation
router.delete('/',async(req, res) => {
    try{
        const removeData = await Dogs.deleteMany();
        res.send("delete all data...");
    }catch(error){
        res.json({message:error});
    }
})

 /*-----------------------------------end of api/dogs/ route----------------------------------------------------------*/

/*
//------------------Operations for api/dogs/{dogId} route----------------------------
//Post operation
router.post('/:dogId', async (req,res)=>{
        res.send('POST operation not supported on /api/dogs/{dogId}');    
    } 
)
 //get operation
 router.get('/:dogId', async (req,res)=>{   
      try{
          const dog = await Dogs.findById(req.params.dogId);
          res.json(dog);
      }catch(error){
          res.json({message:error});
      }
  
  })
 //put operation
 router.put('/:dogId',async(req, res) => {
    try{
        const updateDog = await Dogs.findById(req.params.dogId);
        updateDog.name = req.body.name ;
        updateDog.age = req.body.age ;
        updateDog.gender= req.body.gender;

        const updatedDog = await updateDog.save();

        res.json(updatedDog);
    }
    catch(error) {
        res.json({message:error});
        console.log(res.statusCode);
    }
 })
 //delete operation
 router.delete('/:dogId',async(req, res) => {
     try{
         const removeData = await Dogs.findByIdAndDelete(req.params.dogId);
         res.send("Removed");
     }catch(error){
         res.json({message:error});
     }
     })

 /*-----------------------------------end of api/dogs/{dogId} route----------------------------------------------------------*/



 //------------------Operations for api/dogs/{dogname} route------------------------------------------------
 //Post operation
 router.post('/:dogName', async (req,res)=>{

    res.send({
        error: 'POST operation not supported on /api/dogs/{dogName}'
    })

 });

 //get operation
 router.get('/:dogName', async (req,res)=>{   

    try{
        const dog = await Dogs.find ({'name': { $in: req.params.dogName }})  
        res.json(dog);
      }catch(error){
          res.json({message:error});
      }
  
  })
 //put operation
 router.put('/:dogName',async(req, res) => {
    try{
        const updateDog = await Dogs.findOne({'name':{ $in: req.params.dogName }});
        updateDog.name = req.body.name ;
        updateDog.age = req.body.age ;
        updateDog.gender= req.body.gender;
        const updatedDog = await updateDog.save();
        res.json(updatedDog);
    }
    catch(error) {
        res.json({message:error});

    }
 })
 //delete operation
 router.delete('/:dogName',async(req, res) => {
     try{
         const removeData = await Dogs.findOneAndDelete({'name': { $in: req.params.dogName }});
         res.send("Removed");
     }catch(error){
         res.json({message:error});
     }
 })
 /*-----------------------------------end of api/dogs/{dogname} route----------------------------------------------------------*/





 module.exports = router;