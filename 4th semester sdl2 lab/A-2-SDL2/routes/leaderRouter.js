const express = require('express');
const router= express.Router();
const Leaders = require('../model/leaderSchema');

//get all leaders!
router.get('/', async (req, res) =>{
    try{
        const leaders = await Leaders.find();
        res.json(leaders);
    }
    catch(err){
        res.send(err.message);
    }
})

//get specific data by id
router.get(('/:leaderId'), async (req, res)=>{
    try{
        const leader = await Leaders.findById(req.params.leaderId);
        res.json(leader);
    }
    catch(err){
        res.send(err.message);
        console.log(res.statusCode);
    }
})

// Post data 
router.post('/', async (req, res) => {
    Leaders.create(req.body)
    .then((le)=>{
        res.json(le)
    }, (err) => next(err))
    .catch((err) => next(err));
  
    /*
    const leader = new Leaders({
        name: req.body.name,
        image:req.body.image,
        designation:req.body.designation,
        abbr: req.body.abbr,
        description:req.body.description,
        feature: req.body.feature
    })

    try{
        const data = await leader.save();
        res.json(data);
        console.log(res.statusCode);
    }
    catch(err){
        res.send(err.message);
        console.log(res.statusCode);
    }*/
})

// delete a single promo data
router.delete(('/:leaderId'), async (req, res)=>{
    try{
        const removeLeader = await Leaders.findByIdAndDelete(req.params.promoId);
        res.json(removeLeader);
    }
    catch(err) {
        res.send(err.message);
    }
})

// delete all promotion data
router.delete('/', async (req, res)=>{
    try{
        const removeAllLeader = await Leaders.deleteMany();
        res.send("delete all data...");
    }
    catch(err) {
        console.error(err.message);
    }
})

// put a single data (update)
router.put('/:leaderId', async (req, res)=>{
    try{
        const updateLeader = await Leaders.updateOne(
            {_id:req.params.leaderId},
                {$set:
                    {
                        name: req.body.name,
                        image:req.body.image,
                        designation:req.body.designation,
                        abbr: req.body.abbr,
                        description:req.body.description,
                        feature: req.body.feature
                    }
                });
        
        res.json(updateLeader);
    }
    catch(err) {
        res.send(err.message);
      //  console.log(res.statusCode);
    }
})

module.exports = router;