/*********************************************************************************
* WEB322 – Assignment 03
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: _Madeeha Shahzadi_ Student ID: _130638182_ Date: _Feb, 18 2020_
*
* Online (Heroku) Link:  https://dry-plains-23527.herokuapp.com/
*
********************************************************************************/ 

var HTTP_PORT = process.env.PORT || 8080;
/****************************************************************************** */

var express = require("express");
/******************************************************************************* */

var multer = require("multer");
/******************************************************************************** */
var bodyParser = require("body-parser");
/********************************************************************************* */
var app = express();
/********************************************************************************* */
var path = require('path');
/********************************************************************************** */
var fs = require('fs');
/*********************************************************************************** */

var data_service = require('./data-service.js');
/************************************************************************************ */
const storage = multer.diskStorage({
    destination: "./public/images/uploaded/",
    filename: function (req, file, cb) {
      cb(null, Date.now() + path.extname(file.originalname));
    }
});
var upload = multer({ storage: storage });
/*************************************************************************************** */
app.use(express.static('public'));
/*************************************************************************************** */
app.use(bodyParser.urlencoded({ extended: true }));
/************************************************************************************ */

/*Initialize function in data_service file */

/*function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
    return new Promise((_res) => {
        data_service.initialize().then((data) => {
            console.log(data)
        }).catch((err) => {
            console.log(err);
        });
    });
}*/
/******************************************************************************** */
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/home.html"));
});
/********************************************************************************* */
app.get("/about", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/about.html"));
});
/********************************************************************************** */
app.get("/employees/add", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/addEmployee.html"));
});
/*********************************************************************************** */
app.get("/images/add", (req, res) => {
    res.sendFile(path.join(__dirname+"/views/addImage.html"));
});
/************************************************************************************** */
app.get('/employee/:employeeNum', (req, res) => {
    data_service.getEmployeesByNum(req.params.employeeNum)
    .then((data) => {
        res.json(data);
    })
});
/*************************************************************************************** */
app.get('/employees', (req, res) => {
    if(req.query.status) {
        data_service.getEmployeesByStatus(req.query.status)
            .then((data) => {
                res.json(data)
            })
            .catch((err) =>{
                 res.json({"message": err})
                })
    }else if(req.query.manager){
        data_service.getEmployeesByManager(req.query.manager)
            .then((data) => {
                res.json(data)
            })
            .catch((err) => {
                res.json({"message": err})
            })
    }else if(req.query.department){
        data_service.getEmployeesByDepartment(req.query.department)
            .then((data) =>{

             res.json(data)
            })
            .catch((err) => {
            res.json({"message": err})
        })
    }else{
        data_service.getAllEmployees()
            .then((data) =>{
                      res.json(data)
                         })
            .catch((err) =>{
                 res.json({"message": err})
                })
    }
});

app.get('/managers', (req, res) => {
    data_service.getManagers()
        .then((data) => {
        res.json(data)
    })
        .catch((err) => {
            res.json({"message": err})
        })
});

app.get('/departments', (req, res) => {
    data_service.getDepartments()
        .then((data) => {
            res.json(data)
        })
        .catch((err) => {
            res.json({"message": err})
        })
})

app.get("/images", (req, res) => {
    fs.readdir("./public/images/uploaded", (err, imageFile)=>{
        res.json(imageFile);
    })
})

app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
});

app.post('/employees/add', (req, res)=> {
    data_service.addEmployee(req.body)
        .then(res.redirect('/employees'))
        .catch((err) => {
            res.json({"message": err})
        })   
}) 

app.get('*', (req, res) => {
    
    res.status(404).send("Page is not founded, Please try again:(");
    
})

data_service.initialize()
.then((data) => {
    app.listen(HTTP_PORT, () => console.log(`Listening on port ${HTTP_PORT}`));
})
.catch(() => {
    console.log("Error, please try again:(");
})