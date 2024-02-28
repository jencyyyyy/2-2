const express = require('express');
const router = express.Router();

const Post = require('../models/Posts');
/*
router.get('/',(req,res)=>{
    res.send("We are on posts");
    ;
});
*/
//Get back all posts
router.get('/',async(req,res)=>{

    console.log("We are on posts");
    try{
        const posts = await Post.find();
        res.json(posts);
        }catch(err){
            res.json({message:error})
        }
});
/*
router.get('/specific',(req,res)=>{
    res.send('specific');
});
*/

//Submit a Post
router.post('/',async (req,res)=>{
   // console.log(req.body);
    const post = new Post({        
        title : req.body.title,
        description : req.body.description       
    });
    try{
        const savedPost = await post.save();
        res.json(savedPost);
    }catch(err){
        res.json({message:err})
    }      
});

//Get specific post
router.get('/:postId',async (req,res)=>{
   // console.log(req.params.postId);
   try{
        const post = await Post.findById(req.params.postId);
        res.json(post);
    }catch(err){
        res.json({message: err});
    }
 
});

//Delete
router.delete('/:postId',async (req,res)=>{
   try{
        const removePost= await Post.remove({_id: req.params.postId});
        res.json(removePost);
    }catch(err){
        res.json({message: err});
    }
 });

//Update a post
router.patch('/:postId',async (req,res)=>{
    try{
        const updatedPost= await Post.updateOne(
            {_id: req.params.postId},
            {$set:{title: req.body.title,
                    description: req.body.description} 
         });

        res.json(updatedPost);
     }catch(err){
         res.json({message: err});
     }
  });


module.exports = router;


