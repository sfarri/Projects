var http = require('http'),
    async = require('async'),
        url = process.argv[2]

async.reduce(['one', 'two', 'three'], 0, (memo, item, callback) => {
    http.get(`${url}?number=${item}`, res => {
            var body = '';
            res.on('data', chunk => {
                    body += chunk.toString();
                })
                .on('end', () => {
                    callback(null, body);
                })
                .on('error', err => {
                    callback(err);
                });
        })
        .on('error', err => {
            callback(err);
        });
})