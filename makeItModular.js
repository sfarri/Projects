var dir = process.argv[2];
var filter = process.argv[3];
var myModule = require('./module.js');

myModule (dir, filter, (err, data) => {
    if (err) return console.log("There was an error: ", err);
    data.forEach(file => { console.log(file); });
});