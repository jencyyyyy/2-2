const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());
// Connection URL
mongoose.connect("mongodb://localhost/DevEd", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const connect = mongoose.connection;

connect.on("open", () => {
    console.log("DB connected... ");
})


//Import Routes

const postsRoute = require('./routes/posts');
app.use('/posts', postsRoute);

//app.use('/user',userRoute);
  
//ROUTES=>
app.get('/',(req,res)=>{
    res.send('We are on home');
})



//http://localhost:3000/
//listen to server
app.listen(3000, ()=>{
    console.log("running...")
});






/*
//Middlewares
//Somethin which will show up when go from one route to anoter
app.use('/posts', ()=>{
    console.log("This is middleware running");
});
*/

