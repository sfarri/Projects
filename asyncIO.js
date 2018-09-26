/*eslint-env node*/
/*eslint no-console:0, */
/*global */
var fs = require('fs');

function getLength(fileName, getLengthCallback) {
    
    fs.readFile(fileName, 'utf8', function doneReading(err, fileContents) {
        if(err) {
            console.log("Unknown Error #1: " + err);
            return;
        }
        getLengthCallback(null, fileContents.split('\n').length - 1);
     });
}

getLength(process.argv[2], (err, length) => {
    if(err) {
        console.log("Unknown Error #2: " + err);
        return;
    }
    console.log(length);
});
