var employees = new Array();
var departments = new Array();
/*************************************************************************************************************/
var fs = require('fs');

/***********************************************************************************************************/
var exports = module.exports = {};
/********************************************************************************************************* */
exports.initialize = function() {
    
    fs.readFile('data/employees.json', 'utf-8', (err, data) => 
    {employees = JSON.parse(data);});
    fs.readFile('data/departments.json', 'utf-8', (err, data) => 
    {departments = JSON.parse(data);});

    return new Promise((resolve, reject) => {
        resolve("sucessfully access");
        reject("unable to read the data");
    });
};
/****************************************************************************************************************** */
exports.getAllEmployees = ()=>{
    return new Promise((resolve, reject) => {
        resolve(employees);
        if(employees.length == 0){
        reject("no results returned");
     }});
};
/****************************************************************************************************************** */
exports.getManagers = ()=>{
    return new Promise((resolve, reject) => {
        var m_manager= employees.filter(employees => 
            employees.isManager == true);
        resolve(m_manager);
        if(employees.length == 0)
        reject("no results returned");
    });
};
/******************************************************************************************************************* */
exports.getDepartments = ()=>{
    return new Promise((resolve, reject) => {
        resolve(departments);
        if (departments.length == 0)
        reject("no results returned");
    });

};  
/******************************************************************************************************************** */
exports.addEmployee = (employeeData)=>{
    if(!employeeData.isManager) employeeData.isManager=false;
    else employeeData.isManager = true;
    employeeData.employeeNum = employees.length+1;
    employees.push(employeeData);
    return new Promise((resolve, reject) => {
        resolve(employees);
        if(employees.length == 0)
        reject("no results returned");
    });
};

/************************************************************************************************************************* */
exports.getEmployeesByStatus = (status)=>{
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.status == status);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}
/************************************************************************************************************************** */

exports.getEmployeesByDepartment = (department)=>{
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.department == department);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}
/************************************************************************************************************************** */
exports.getEmployeesByManager = (manager)=>{
    return new Promise((resolve, reject) => {
        var filteredEmployees = employees.filter(employees => 
            employees.employeeManagerNum == manager);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}

/************************************************************************************************************************* */
module.exports.getEmployeeByNum = (num) => {
    return new Promise((resolve, reject) => {
        for (var j = 0; j < employess.length; j++) {
            if (employess[j].employeeNum == num) {
                resolve(employess[j]);
            }
        }
        reject("No Result Returned!!!");
    });
}
/*************************************************************************************************************************** */

exports.updateEmployee = function(employeeData){
    return new Promise((resolve, reject) => {
        if(employeeData.isManager == (employeeData.isManager)) 
        true;
        else
        false;
        return new Promise((resolve, reject) => {
            employees.forEach(employee => {

                if (employee.employeeNum == employeeData.employeeNum) {
                    employees.splice(employeeData.employeeNum - 1, 1, employeeData);
                }
            });
            resolve();
        });
    });
};


        