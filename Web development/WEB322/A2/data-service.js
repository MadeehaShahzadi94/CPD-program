
var fs = require('fs');
var Employees =new Array();
var departments = new Array();
// Initializer.
module.exports.initialize = ()=>
 {
    return new Promise((resolve, reject)=>
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
    });
}
//getAllEmployees()

module.exports.getAllEmployees = ()=> {
    //var Employees = [];
    return new Promise((resolve, reject)=> {
        for (var i = 0; i < employess.length; i++) {
            Employees.push(employess[i]);
        }
        if (Employees.length == 0) {
            reject("No data");
        }
        resolve(Employees);
    })
}


//getManager()
module.exports.getManagers = ()=> {
    var manager = new Array();
    return new Promise((resolve, reject)=> {
        if (employess.length == 0) {
            reject("No Data");
        } else {
            for (var q = 0; q < employess.length; q++) {
                if (employess[q].isManager == true) {
                    manager.push(employess[q]);
                }
            }
            /*if (manager.length == 0) {
                reject("No Data");
            }*/
        }
        resolve(manager);
    });
}
//getDepartment()
module.exports.getDepartments = ()=> {
    var department = [];
    return new Promise((resolve, reject)=> {
        if (employess.length == 0) {
            reject("No Data");
        } else {
            for (var v = 0; v < departments.length; v++) {
                department.push(departments[v]);
            }
            if (department.length == 0) {
                reject("No Data");
            }
        }
        resolve(department);
    });
}