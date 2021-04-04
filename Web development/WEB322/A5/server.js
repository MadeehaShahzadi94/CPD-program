/*********************************************************************************
* WEB322 – Assignment 05
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Madeeha Shahzadi Student ID: 130638182  Date: March 23,2020
*
* Online (Heroku) Link: https://dry-plains-23527.herokuapp.com/ 

*
********************************************************************************/

var express = require("express");
/****************************************************************************** */
var multer = require("multer");
/******************************************************************************** */
var app = express();
/******************************************************************************** */
var data_server = require("./data-service.js")
/********************************************************************************** */
var path = require("path")
/******************************************************************************** */
var HTTP_PORT = process.env.PORT || 8080;
/******************************************************************************** */
var fs = require("fs");
/******************************************************************************** */
var bodyParser = require('body-parser');
/******************************************************************************** */
var exphbs = require('express-handlebars');
/******************************************************************************** */
app.use(bodyParser.urlencoded({ extended: true }));
/********************************************************************************* */
app.use(express.static('public'));
/******************************************************************************** */
// using multer library

const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
  }

});

/************************************************************************************ */
var upload = multer({ storage: storage });

function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}
/************************************************************************************** */
/////////////////////////    Navigation bar fixing     ///////////

app.set('view engine', '.hbs');
app.use(function (req, res, next) {
  let route = req.baseUrl + req.path;
  app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
  next();
});

/******************************************************************************************* */
app.engine('.hbs', exphbs({
  extname: '.hbs',
  defaultLayout: 'main',
  helpers: {
    navLink: function (url, options) {
      return '<li' + ((url == app.locals.activeRoute) ? ' class="active"' : '')
        + '><a href="' + url + '">' + options.fn(this) + '</a></li>'
    },

    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
        throw new Error("Handlerbars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
        return options.inverse(this);
      } else {
        return options.fn(this);
      }
    }
  }
}));

/******************************************************************************** */

app.get("/", (req, res) => {

  res.render("home");
});

/********************************************************************************** */

app.get("/about", (req, res) => {

  res.render("about");

});

/*********************************************************************************** */

app.get("/images/add", function (req, res) {

  res.render("addImage");

});
/********************************************************************************** */
app.post("/images/add", upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
});

/*********************************************************************************** */
app.get("/images", (req, res) => {
  fs.readdir("./public/images/uploaded", function (err, imageFile) {
    res.render("images", { imageFile });
  })
});

/************************************************************************************ */

app.get("/departments", (req, res) => {
  data_server.getDepartments()
    .then((data) => {
      if (data.length > 0) {
        res.render("departments", { departments: data })
      }
      else {
        res.render("departments", { "message": "no results" })
      }
    })
    .catch((err) => { res.render("departments", { "message": "no results" }) })
});


/****************************************************************************************** */

app.get("/employees", (req, res) => {

  if (req.query.status) {
    data_server.getEmployeesByStatus(req.query.status)
      .then((data) => {
        if (data.length > 0) {

          res.render("employees", { employees: data })
        }
        else {
          res.render("employees", { "message": "no data" })
        }
      })

      .catch((err) => { res.render("employees", { "message": "no data" }) })

  }
  else if (req.query.department) {
    data_server.getEmployeesByDepartment(req.query.department)
      .then((data) => {
        if (data.length > 0) {

          res.render("employees", { employees: data })
        }
        else {
          res.render("employees", { "message": "no data" })
        }
      })
      .catch((err) => { res.render("employees", { "message": "no data" }) })
  }
  else if (req.query.manager) {
    data_server.getEmployeesByManager(req.query.manager)
      .then((data) => {
        if (data.length > 0) {

          res.render("employees", { employees: data })
        }
        else {
          res.render("employees", { "message": "no data" })
        }
      })
      .catch((err) => { res.render("employees", { "message": "no data" }) })
  }
  else {
    data_server.getAllEmployees()
      .then((data) => {
        console.log(data);
        if (data.length > 0) {

          res.render("employees", { employees: data })
        } else {
          res.render("employees", { "message": "no data" })
        }
      })
      .catch((err) => {

        res.render("employees", { "message": "no data" })
      });
  }

});

/************************************************************************************ */

app.post('/employees/add', function (req, res) {
  data_server.addEmployee(req.body)
    .then(res.redirect('/employees'))
    .catch((err) => {
      res.status(500).send("Unable to add Employee");
    });
})
/************************************************************************************** */
app.get("/employees/add", (req, res) => {
  //res.sendFile(path.join(__dirname+"/views/addEmployee.html"));
  data_server.getDepartments()
    .then((data) => {
      console.log(data);
      res.render("addEmployee", { departments: data })
    })
    .catch((err) => {
      console.log(err);
      res.render("addEmployee", { departments: [] })
    })
});

/****************************************************************************************** */



app.post('/employee/update', (req, res) => {
  console.log('update' + req.body);

  data_server.updateEmployee(req.body)
    .then(res.redirect('/employees'))
    .catch((err) => {
      res.status(500).send("Unable to Update Employee");
    });
});

/*************************************************************************************** */

app.get("/departments/add", function (req, res) {

  res.render("addDepartment");

});

////////      post department

app.post("/departments/add", (req, res) => {
  data_server.addDepartment(req.body)
    .then(res.redirect("/departments"))
    .catch((err) => {
      res.status(500).send("Unable to add department");
    });
})

////////     update department

app.post('/department/update', (req, res) => {
  console.log('update' + req.body);

  data_server.updateDepartment(req.body)
    .then(res.redirect('/departments'))
    .catch((err) => {
      res.status(500).send("Unable to Update department");
    });
});

//////// get department by department id

app.get("/department/:departmentId", (req, res) => {
  data_server.getDepartmentById(req.params.departmentId)
    .then((data) => {
      res.render("department", { department: data });
    })
    .catch(() => {
      res.status(404).send("Department Not Found");
    })

})

//////////  delete departments

app.get("/departments/delete/:departmentId", (req, res) => {
  data_server.deleteDepartmentById(req.params.departmentId)
    .then((data) => {
      res.redirect("/departments");
    })
    .catch(() => {
      res.status(500).send("Unable to Remove Department / Department not found)");
    })

})



//////// new function to get employee by num

app.get("/employee/:empNum", (req, res) => {
  // initialize an empty object to store the values
  let viewData = {};
  data_server.getEmployeeByNum(req.params.empNum).then((data) => {
    if (data) {
      viewData.employee = data; //store employee data in the "viewData" object as "employee"
    } else {
      viewData.employee = null; // set employee to null if none were returned
    }
  }).catch(() => {
    viewData.employee = null; // set employee to null if there was an error
  }).then(data_server.getDepartments)
    .then((data) => {
      viewData.departments = data; // store department data in the "viewData" object as "departments"
      // loop through viewData.departments and once we have found the departmentId that matches
      // the employee's "department" value, add a "selected" property to the matching
      // viewData.departments object
      for (let i = 0; i < viewData.departments.length; i++) {
        if (viewData.departments[i].departmentId == viewData.employee.department) {
          viewData.departments[i].selected = true;
        }
      }
    }).catch(() => {
      viewData.departments = []; // set departments to empty if there was an error
    }).then(() => {
      if (viewData.employee == null) { // if no employee - return an error
        res.status(404).send("Employee Not Found");
      } else {
        res.render("employee", { viewData: viewData }); // render the "employee" view
      }
    });
});


/////////////////// deleting employees

app.get('/employees/delete/:empNum', (req, res) => {
  data_server.deleteEmployeeByNum(req.params.empNum)
    .then((data) => res.redirect("/employees"))
    .catch(() => res.status(500).send("Unable to Remove Employee / Employee not found"))
})


////////////////////////////////////////////////
app.use(function (req, res) {
  res.status(404).send("Page Not Found");
})
data_server.initialize()
  .then(() => { app.listen(HTTP_PORT, onHttpStart); })
  .catch(err => { console.log(err); })
app.use(express.static('public'));

