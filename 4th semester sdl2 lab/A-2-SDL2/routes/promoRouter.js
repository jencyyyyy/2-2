const express = require('express');
const router= express.Router();
const Promotions = require('../model/promoSchema');

// get all promotions data 
router.get('/', async (req, res) =>{
    try{
        const promo = await Promotions.find();
        res.json(promo);
    }
    catch(err){
        res.send(err.message);
    }

})

//get specific data by id
router.get(('/:promoId'), async (req, res)=>{
    try{
        const promo = await Promotions.findById(req.params.promoId);
        res.json(promo);
    }
    catch(err){
        res.send(err.message);
        console.log(res.statusCode);
    }
})

// Post data 
router.post('/', async (req, res) => {
    const promoData = new Promotions({
        name: req.body.name,
        image:req.body.image,
        label:req.body.label,
        price:req.body.price,
        description:req.body.description,
        feature: req.body.feature
    })

    try{
        const data = await promoData.save();
        res.json(data);
        console.log(res.statusCode);
    }
    catch(err){
        res.send(err.message);
        console.log(res.statusCode);
    }
})

// delete a single promo data
router.delete(('/:promoId'), async (req, res)=>{
    try{
        const deletePromo = await Promotions.findByIdAndDelete(req.params.promoId);
        res.json(deletePromo);
    }
    catch(err) {
        res.send(err.message);
    }
})
 
// delete all promotion data
router.delete('/', async (req, res)=>{
    try{
        const deleteAllPromos = await Promotions.deleteMany();
        res.send("delete all data...");
    }
    catch(err) {
        console.error(err.message);
    }
})

// put a single data 
router.put('/:promoId', async (req, res)=>{
    try{
        const updatePromo = await Promotions.updateOne(
            {_id:req.params.promoId},
                {$set:
                    {
                        name: req.body.name,
                        image:req.body.image,
                        label:req.body.label,
                        price:req.body.price,
                        description:req.body.description,
                        feature: req.body.feature
                    }
                });
        
        res.json(updatePromo);
    }
    catch(err) {
        res.send(err.message);
      //  console.log(res.statusCode);
    }
})

module.exports = router;