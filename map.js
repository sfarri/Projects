var http = require('http'),
    async = require('async'),
        path1 = process.argv[2],
        path2 = process.argv[3];

async.map([path1, path2], (path, callback) => {
    var body = '';
    http.get(path, res => {
        res.on('data', chunk => {
            body += chunk.toString();
        }).on('end', () => {
            callback(null, body);
        }).on('error', err => {
            callback(err);
        });
    }).on('error', err => {
        callback(err);
    });
}, (err, results) => {
    if (err) return console.log(err);
    return console.log(results);
});