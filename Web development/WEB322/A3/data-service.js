
var fs = require('fs');
/*************************************************************** */
var employees =new Array();
/**************************************************************** */
var departments = new Array();

/***************************************************************** */

module.exports.initialize = ()=>
 {
    fs.readFile('data/employees.json', 'utf-8', (err, data) => 
    {employees = JSON.parse(data);
    });
    fs.readFile('data/departments.json', 'utf-8', (err, data) =>
     {departments = JSON.parse(data);
    });

    return new Promise((resolve, reject) => {
        resolve("File is not opening!");
        reject("No Data");
    });
   /* return new Promise((resolve, reject)=>
     {
        try
         {
            fs.readFile('./data/employees.json', (err, data)=>
             {
                if (err) throw err;
                employess = JSON.parse(data);
            });
            fs.readFile('./data/departments.json', (err, data)=>
             {
                if (err) throw err;//reject()
                departments = JSON.parse(data);
            });
        } catch (ex)
         {
            reject("File is not opening!");
        }
        resolve("JSON file successfully read.");
    });*/
}
/***************************************************************** */

module.exports.getAllEmployees = ()=> {
    //var Employees = [];
    return new Promise((resolve, reject)=> {
       // for (var i = 0; i < employess.length; i++) {
            resolve(employees);
        
        if (Employees.length == 0) {
            reject("No data");
        }
        //resolve(Employees);
    });
}

/************************************************************** */
module.exports.getManagers = ()=> {
   // var manager = new Array();
    return new Promise((resolve, reject)=> {
       var managers = employees.filter(employees=>
           employees.isManager ==true
       );
       resolve(managers);
        if (employess.length == 0) {
            reject("No Data");
        } 
        /*else {
            for (var q = 0; q < employess.length; q++) {
                if (employess[q].isManager == true) {
                    manager.push(employess[q]);
                }
            }
            /*if (manager.length == 0) {
                reject("No Data");
            }
        }
        resolve(manager);*/
    });
}
/****************************************************************** */
module.exports.getDepartments = ()=> {
    //var department = [];
    return new Promise((resolve, reject)=> {
        resolve(departments);
        if (departments.length == 0) {
            reject("No Data");
        } 
    });
}
/********************************************************************* */
module.exports.addEmployee = function(employeeData){
    if(!employeeData.isManager){ 
    employeeData.isManager=false;
    }else 
    employeeData.isManager = true;
    employeeData.employeeNum = employees.length+1;
    employees.push(employeeData);
    return new Promise((resolve, reject) => {
        resolve(employees);
        if(employees.length == 0)
        reject("no results returned");
    });
};
/***************************************************************************** */
module.exports.getEmployeesByStatus = function(status){
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.status == status);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}
/******************************************************************************** */
module.exports.getEmployeesByDepartment = function(department){
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.department == department);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0){
        reject("no results returned");
        }
    });
}
/********************************************************************************* */
module.exports.getEmployeesByManager = function(manager){
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.employeeManagerNum == manager);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0){
        reject("no results returned");
        }
    });
}
/*********************************************************************************** */
module.exports.getEmployeesByNum = function(num){
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.employeeNum == num);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0){
        reject("no results returned");
        }
    });
}