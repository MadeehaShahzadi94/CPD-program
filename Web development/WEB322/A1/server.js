/*tHIS IS MY work
ID: 13068182
Last Name: Shahzadi
link https://peaceful-harbor-71782.herokuapp.com/*/ 

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();
app.get("/", (req, res) => {
    res.send("Madeeha Shahzadi ID: 13068182");
});
app.listen(HTTP_PORT);