/*********************************************************************************
*  WEB322 – Assignment 04
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part 
*  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Madeeha Shahzadi Student ID: 130638182 Date: November 1,2019
*
*  Online (Heroku) Link: https://young-caverns-02301.herokuapp.com/
*
********************************************************************************/ 
//lishening local host port
var HTTP_PORT = process.env.PORT || 8080;
//express package support
var express = require("express");
//for images or files
var multer = require("multer");
//we are using body-parser because of it is support POST.
var bodyParser = require("body-parser");
//template engine
var exphbs = require('express-handlebars');
//Part of express
var app = express();
// it is supporting the paths of the program
var path = require('path');
//reading the files
var fs = require('fs');
//suport the file data-service.js
var dataService = require('./data-service.js');
/*************************************************************************************************************/
const storage = multer.diskStorage({
    destination: "./public/images/uploaded/",
    filename: function (req, file, cb) {
      cb(null, Date.now() + path.extname(file.originalname));
    }
});
var upload = multer({ storage: storage });
/********************************************
*Sttaic property that supports public folder*
*********************************************/
app.use(express.static('public'));
/*************************************************************************************************************/
app.use(bodyParser.urlencoded({ extended: true }));
/************************************************************************************************************/
//Engine of of template support the html a new way
app.engine('.hbs', exphbs({
    extname:'.hbs',
    defaultLayout:'main',
    helpers:{
    navLink:function(url, options){
        return '<li' + ((url==app.locals.activeRoute)? ' class="active"':'')
            +'><a href="'+url+'">'+options.fn(this)+'</a></li>'
    },
    equal:function(lvalue, rvalue, options){
        if(arguments.length<3)
            throw new Error("Handlerbars Helper equal needs 2 parameters");
        if(lvalue != rvalue){
            return options.inverse(this);
        }else{
            return options.fn(this);
        }
    }
}
}));
app.set('view engine', '.hbs');
/******************************************************************************************************************/
app.use(function(req,res,next){
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
});


/*****************************************************************************************************************/
// for home route
app.get("/", (req, res) => {
   // res.sendFile(path.join(__dirname+"/views/home.html"));

   res.render("home");
});
/****************************************************************************************************************/
// for about page
app.get("/about", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/about.html"));

    res.render("about");
});
/***************************************************************************************************************/
//for employees page
app.get("/employees/add", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/addEmployee.html"));

    res.render("addEmployee");
});
/************************************************************************************************************/
//for images page
app.get("/images/add", (req, res) => {
    //res.sendFile(path.join(__dirname+"/views/addImage.html"));

    res.render("addImage");
});
/****************************************************************************************************************/
//number of employees
app.get("/employee/:empNum", (req, res) => {
    dataService.getEmployeeByNum(req.params.empNum).then((data) => {
        res.render("employee", { data: data });
    }).catch((err) => {
        res.status(404).send("Employee Not Found!!!");
    });
});
/******************************************************************************************************************/
// why it is important...
//when we search some employee with ? it is support that.
app.get('/employees', (req, res) => {
    if(req.query.status) {
        dataService.getEmployeesByStatus(req.query.status)
            .then((data) => 
            res.render("employees",{employees:data}))
            .catch(() =>
             res.render("employees",{message: "no results"}))
    }else if(req.query.manager){
        dataService.getEmployeesByManager(req.query.manager)
            .then((data) => 
            res.render("employees",{employees:data}))
            .catch(() =>
             res.render("employees",{message: "no results"}))
    }else if(req.query.department){
        dataService.getEmployeesByDepartment(req.query.department)
            .then((data) => 
            res.render("employees",{employees:data}))
            .catch(() =>
             res.render("employees",{message: "no results"}))
    }else{
        dataService.getAllEmployees()
            .then((data) => 
            res.render("employees",{employees:data}))
            .catch(() => 
            res.render("employees",{message: "no results"}))
    }
});
/*******************************************************************************************************************/
//it is not in the teacher sample.
/*app.get('/managers', (req, res) => {
    
    dataService.getManagers()
        
    .then((data) => res.json(data))
        
    .catch((err) => res.json({"message": err}))
});*/
/********************************************************************************************************************/
//for the department page
app.get('/departments', (req, res) => {
    dataService.getDepartments()
        .then((data) => 
        res.render("departments", 
        {departments: data}))
        .catch((err) => 
        res.json({"message": err}))
})
/*********************************************************************************************************************/
//for images that upload in the folder
// jo hum daly gy pics wo ja kr is folder main save ho gi
app.get("/images", (req, res) => {
    fs.readdir("./public/images/uploaded", (err, imageFile)=>{
       // res.json(imageFile);
       res.render("images", {
            data:imageFile,title: "Images"
       });
    })
})
/********************************************************************************************************************/
// it is work with the body-parser and it is making easy to add pics in the folder
app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
});
/************************************************************************************************************************/
// when we add the employee in the employees.json it will uploaded employee.json file.
app.post('/employees/add',(req, res)=> {
    dataService.addEmployee(req.body)
        .then(res.redirect('/employees'))
        .catch((err) => 
        res.json({"message": err}))   
}) 
/********************************************************************************************************************** */
app.post("/employee/update", function(req, res){
    dataService.updateEmployee(req.body)
    
    .then(res.redirect('/employees'))
});

/*************************************************************************************************************/
//when page is not loaded it is giving us error
app.get('/', (req, res) => {
    
    res.status(404);
    res.send("<<<<<<<<<<<<<<<<<<<<<<<<<<page is not found>>>>>>>>>>>>>>>>>>>>>>");
})
/********************************************************************************************************* */
// setup http server to listen on HTTP_PORT
dataService.initialize()
.then((data) => {
    app.listen(HTTP_PORT, () =>
     console.log(`Listening on port ${HTTP_PORT}`));
})
.catch(() => {
    console.log("Error, please try again:(");
})