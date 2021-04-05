/*********************************************************************************
* WEB422 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: _Madeeha Shahzadi_ Student ID: _130638182_ Date: _May 28 2020_
* Heroku Link: _https://fathomless-shore-31697.herokuapp.com/__
*
********************************************************************************/ 
const express = require("express");
//const PATH = require("Path")
const cors = require("cors");
const bodyParser = require("body-parser");
const dataService = require("./modules/data-service.js");
//module.export PATH="/Applications/mongodb-osx-x86_64-x.x.x/bin:$PATH"
const myData = dataService("mongodb+srv://mshahzadi1:Noor@2013@cluster0-d8czh.mongodb.net/blog?retryWrites=true&w=majority");
//mongo "mongodb+srv://cluster0-rkiux.mongodb.net/<dbname>" --username mshahzadi1

const app = express();

app.use(cors());

app.use(bodyParser.json());

const HTTP_PORT = process.env.PORT || 8080;

// ************* API Routes
app.get("/", (req, res) => {
    res.send("Madeeha Shahzadi");
});

// POST /api/sales (NOTE: This route must read the contents of the request body)
app.post("/api/sales", (req, res) =>{
    myData.addNewSale(req.body)
    .then((data) => {res.json({message : data})})
    .catch((err) => {res.json({message : err})})
  
});


// GET /api/sales (NOTE: This route must accept the numeric query parameters "page" and "perPage", ie: /api/sales?page=1&perPage=5 )


app.get("/api/sales", (req, res) =>{
    myData.getAllSales(req.query.page, req.query.perPage)
    .then((data) => {res.json(data);})
    .catch((err) => {res.json({message : err});});
   
});


// GET /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8)
app.get("/api/sales/:_id", (req, res) => {
    myData.getSaleById(req.params._id)
    .then((data) => {res.json(data);})
    .catch((err) => {res.json({message : err});});
    
});

// PUT /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8 as well as read the contents of the request body)
app.put("/api/sales/:_id", (req, res) => {
    myData.updateSaleById(req.body, req.params._id)
    .then((data) => {res.json({message : data});})
    .catch((err) => {res.json({message : err});});
   
});



// DELETE /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8)
app.delete("/api/sales/:_id", (req, res) => {
    myData.deleteSaleById(req.params._id)
    .then((data) => {res.json({message : data});})
    .catch((err) => {res.json({message : err});});
    
});


// ************* Initialize the Service & Start the Server

myData.initialize().then(()=>{
    app.listen(HTTP_PORT,()=>{
        console.log(`server listening on: ${HTTP_PORT}`);
    });
}).catch((err)=>{
    console.log(err);
});

