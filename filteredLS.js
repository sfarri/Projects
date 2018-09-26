/*eslint-env node*/
/*eslint no-console:0, */
/*global */
var fs = require('fs');
var folder = process.argv[2];
var extension = "." + process.argv[3];

fs.readdir(folder, (err, files) => {
    if (err) {
        console.log("Unknown Error 1: " + err);
        return;
    }
    files.forEach(file => {
        if (file.indexOf(extension) > -1) {
            console.log(file);
        }
    });
})