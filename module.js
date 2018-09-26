/*eslint-env node*/
/*eslint no-console:0, */
/*global */
var fs = require('fs');
var path = require('path');

module.exports = (folder, extension, callback) => {
    fs.readdir(folder, (err, files) => {
        if (err) return callback(err);
        else {
            files = files.filter(file => {
                if ( path.extname(file) === '.' + extension ) return true;
            })
            return callback(null, files);
        }
    })
}