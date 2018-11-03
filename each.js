var http = require('http'),
    async = require('async'),
        path1 = process.argv[2],
        path2 = process.argv[3];

async.each([path1, path2], (path, callback) => {
    http.get(path, res => {
        var body = '';
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
});