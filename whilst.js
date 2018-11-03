var async = require('async'),
    http = require('http'),
    response = "",
    count = 0,
    url = process.argv[2];

async.whilst(() => {
        return response !== 'meerkat';
    }, callback => {
        http.get(url, res => {
            count++;
            var body = "";
            res.on('data', chunk => {
                body += chunk.toString();
            }).on('end', () => {
                response = body.trim();
                callback();
            });
        }).on('error', err => {
            return console.log(err);
        });
    }, err => {
        console.log(count);
    }
);