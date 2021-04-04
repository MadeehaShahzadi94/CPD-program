/*********************************************************************************
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: _Madeeha Shahzadi_ Student ID: _130638182_ Date: _January, 27 2020_
*
* Online (Heroku) Link: _https://dry-plains-23527.herokuapp.com/_
*
********************************************************************************/ 
var express = require("express");

var app = express();

var path = require("path");
var data_service = require("./data-service.js");

/* piblic is not changing, public used for user see front web*/
app.use(express.static('public'));

var path = require("path");
var data_service = require("./data-service.js");

/*Initialize function in dataservice file */
var HTTP_PORT = process.env.PORT || 8080;
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
    return new Promise((_res) => {
        data_service.initialize().then((data) => {
            console.log(data)
        }).catch((err) => {
            console.log(err);
        });
    });
}
/******************************************************************************** */
//Routhes
  app.get("/", (req, res)=> {
    res.sendFile(path.join(__dirname, "/views/home.html"));
});

/******************************************************************************** */
app.get("/about",(req, res)=> {
    res.sendFile(path.join(__dirname, "/views/about.html"));
});
/******************************************************************************** */
app.get("/employees", (req, res)=> {
    data_service.getAllEmployees().then((data)=> {
        res.json(data);
    }).catch((err)=>{
        res.json({ message: err });
    });
})
/******************************************************************************* */
app.get("/managers", (req, res)=> {
    data_service.getManagers().then((data)=> {
        res.json(data);
    }).catch((err)=> {
        res.json({ message: err });
    });
})
/******************************************************************************* */
app.get("/departments", (req, res)=> {
    data_service.getDepartments().then((data)=> {
        res.json(data);
    }).catch((err)=> {
        res.json({ message: err });
    });
})
/********************************************************************************* */
app.use((_req, res) => {
    res.status(404).send("Page Not Found!");
});
/********************************************************************************** */
app.listen(HTTP_PORT, onHttpStart);