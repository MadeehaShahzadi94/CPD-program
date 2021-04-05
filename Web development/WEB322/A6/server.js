/*********************************************************************************
* WEB322 – Assignment 06
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Madeeha Shahzadi Student ID: 130638182  Date: April 10,2020
*
* Online (Heroku) Link: https://dry-plains-23527.herokuapp.com/ 

*
********************************************************************************/
const clientSessions = require('client-sessions');

var express = require("express");

var multer = require("multer");

var app = express();

var data_server = require("./data-service.js")

var path = require("path")

var HTTP_PORT = process.env.PORT || 8080;

var fs = require("fs");

var bodyParser = require('body-parser');

var exphbs = require('express-handlebars');

var dataServiceAuth = require("./data-service-auth.js");

/////////////// set up client session

app.use(clientSessions({
  cookieName: "session",
  secret: "assignment6web322",
  duration: 2 * 60 * 1000,
  activeDuration: 1000 * 6
}));

app.use((req, res, next) => {

  res.locals.session = req.session;
  next();
});

app.use(bodyParser.urlencoded({ extended: true }));

app.use(express.static('public'));


///////////// user authentication userLogin function middleware

function userLogin(req, res, next) {

  if (!(req.session.user)) {
    res.redirect("/login");
  }
  else { next(); }
}





// using multer library

const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
  }

});


var upload = multer({ storage: storage });

function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}

/////////////////////////    Navigation bar fixing     ///////////

app.set('view engine', '.hbs');
app.use(function (req, res, next) {
  let route = req.baseUrl + req.path;
  app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
  next();
});


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


/////////////////////// new routes


//////GET /login

app.get("/login", (req, res) => {

  res.render("login");
})

//////GET /register

app.get("/register", (req, res) => {

  res.render("register");
})

//////POST /register

app.post("/register", (req, res) => {
  dataServiceAuth.registerUser(req.body).
    then((data) => {
      res.render('register', { successMessage: "User created" });

    }).catch((err) => {

      res.render('register', { errorMessage: err, userName: req.body.userName })

    });
})

//////// POST /login

app.post("/login", (req, res) => {

  req.body.userAgent = req.get('User-Agent');

  dataServiceAuth.checkUser(req.body).then((user) => {
    req.session.user = {
      userName: user.userName,
      email: user.email,
      loginHistory: user.loginHistory
    }
    res.redirect('/employees');
  }).catch((err) => {

    res.render('login', { errorMessage: err, userName: req.body.userName })
  });
})


///////GET/logout

app.get("/logout", (req, res) => {

  req.session.reset();
  res.redirect("/");
});

/////// get/userHistory

app.get("/userHistory", userLogin, (req, res) => {

  res.render("userHistory");

})

//home.hbs

app.get("/", (req, res) => {

  res.render("home");
});

//about.hbs

app.get("/about", (req, res) => {

  res.render("about");

});

//addEmployee.hbs


//addImages.hbs

app.get("/images/add", userLogin, function (req, res) {

  res.render("addImage");

});

/////// reading images


app.post("/images/add", upload.single("imageFile"), userLogin, (req, res) => {
  res.redirect("/images");
});


app.get("/images", userLogin, (req, res) => {
  fs.
    readdir("./public/images/uploaded", function (err, imageFile) {
      res.render("images", { imageFile });
    })
});

//departments.json

app.get("/departments", userLogin, (req, res) => {
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


//employees.json

app.get("/employees", userLogin, (req, res) => {

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


////////post route for employees

app.post('/employees/add', userLogin, function (req, res) {
  data_server.addEmployee(req.body)
    .then(res.redirect('/employees'))
    .catch((err) => {
      res.status(500).send("Unable to add Employee");
    });
})

app.get("/employees/add", userLogin, (req, res) => {

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

///////// update employee data using post



app.post('/employee/update', userLogin, (req, res) => {
  console.log('update' + req.body);

  data_server.updateEmployee(req.body)
    .then(res.redirect('/employees'))
    .catch((err) => {
      res.status(500).send("Unable to Update Employee");
    });
});

////////        get department


app.get("/departments/add", userLogin, function (req, res) {

  res.render("addDepartment");

});

////////      post department

app.post("/departments/add", userLogin, (req, res) => {
  data_server.addDepartment(req.body)
    .then(res.redirect("/departments"))
    .catch((err) => {
      res.status(500).send("Unable to add department");
    });
})

////////     update department

app.post('/department/update', userLogin, (req, res) => {
  console.log('update' + req.body);

  data_server.updateDepartment(req.body)
    .then(res.redirect('/departments'))
    .catch((err) => {
      res.status(500).send("Unable to Update department");
    });
});

//////// get department by department id

app.get("/department/:departmentId", userLogin, (req, res) => {
  data_server.getDepartmentById(req.params.departmentId)
    .then((data) => {
      res.render("department", { department: data });
    })
    .catch(() => {
      res.status(404).send("Department Not Found");
    })

})

//////////  delete departments

app.get("/departments/delete/:departmentId", userLogin, (req, res) => {
  data_server.deleteDepartmentById(req.params.departmentId)
    .then((data) => {
      res.redirect("/departments");
    })
    .catch(() => {
      res.status(500).send("Unable to Remove Department / Department not found)");
    })

})



//////// new function to get employee by num

app.get("/employee/:empNum", userLogin, (req, res) => {
  let viewData = {};
  data_server.getEmployeeByNum(req.params.empNum).then((data) => {
    if (data) {
      viewData.employee = data;
    } else {
      viewData.employee = null;
    }
  }).catch(() => {
    viewData.employee = null;
  }).then(data_server.getDepartments)
    .then((data) => {
      viewData.departments = data;
      for (let i = 0; i < viewData.departments.length; i++) {
        if (viewData.departments[i].departmentId == viewData.employee.department) {
          viewData.departments[i].selected = true;
        }
      }
    }).catch(() => {
      viewData.departments = [];
    }).then(() => {
      if (viewData.employee == null) {
        res.status(404).send("Employee Not Found");
      } else {
        res.render("employee", { viewData: viewData });
      }
    });
});


/////////////////// deleting employees

app.get('/employees/delete/:empNum', userLogin, (req, res) => {
  data_server.deleteEmployeeByNum(req.params.empNum)
    .then((data) => res.redirect("/employees"))
    .catch(() => res.status(500).send("Unable to Remove Employee / Employee not found"))
})


////////////////////////////////////////////////
app.use(function (req, res) {
  res.status(404).send("Page Not Found");
})



data_server.initialize().then(dataServiceAuth.initialize)
  .then(() => { app.listen(HTTP_PORT, onHttpStart); })
  .catch(err => { console.log(err); })
app.use(express.static('public'));

