const route = require('express').Router();
const Books = require('../model/bookModel');

//Operations for /books

//get operation

route.get('/',async(req,res)=>{
    try{
        const book = await Books.find();
        res.json(book);
    }catch(error){
        res.json({message:error});
    }
})

//post operation

route.post('/',async(req,res)=>{
    const book = new Books(req.body);

    book.save(function(error,book){
        if(error) return res.send(error);

        res.json(book);
    })

})

//put opearation

route.put('/',async(req,res)=>{
    res.send('/books does not support Put function');
})

//delete function

route.delete('/',async(req,res)=>{
    try{
        const removeAll = await Books.deleteMany();
        res.send("All books removed from the database");
    }catch(error){
        res.json({message:error});
    }
});


// Operations for /books/{bookid}

//get 

route.get('/:bookid',async(req,res)=>{
    try{
        const book = await Books.findById(req.params.bookid);
        res.json(book);
    }catch(error){
        res.json({message:error});
    }
})


//post

route.post('/:bookid',async(req,res)=>{
    res.send("/books/{bookid} does not support post function");
})

//put 

route.put('/:bookid',async(req,res)=>{
    try{
        const bookUpdate = await Books.updateOne({
            _id:req.params.bookid},
            {$set: req.body}
        );
        res.json(bookUpdate);
    }catch(error){
        res.json({message:error});
    }
})


//delete

route.delete('/:bookid',async(req,res)=>{

    try{
        const delbook = await Books.findByIdAndDelete(req.params.bookid);
        res.send('That specific book is being deleted');
    }catch(error){
        res.json({message:error});
    }
})

/* ---end for books/{bookid} ----*/

// Operations for /books/{bookname}
/*
//get 

route.get('/:bookname',async(req,res)=>{
    try{
        const book = await Books.find({'name':{$in:req.params.bookname}});
        res.json(book);
    }catch(error){
        res.json({message:error});
    }
})


//post

route.post('/:bookname',async(req,res)=>{
    res.send("/books/{bookname} does not support post function");
})

//put 

route.put('/:bookname',async(req,res)=>{
    try{
        const bookUpdate = await Books.updateOne({'name':{$in: req.params.bookname}},
            {$set: req.body}
        );
        res.json(bookUpdate);
    }catch(error){
        res.json({message:error});
    }
})


//delete

route.delete('/:bookname',async(req,res)=>{

    try{
        const deletebook = await Books.findOneAndDelete({'name':{$in: req.param.bookname}});
        res.send('The book with the specific is being deleted');
    }catch(error){
        res.json({message:error});
    }
})

/* /books/{bookname} end for*/
module.exports= route;