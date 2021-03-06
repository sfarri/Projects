var http = require('http'),
    async = require('async'),
        url = process.argv[2]

async.reduce(['one', 'two', 'three'], 0, (memo, item, callback) => {
    var body = '';
    http.get(`${url}?number=${item}`, res => {
        res.on('data', chunk => {
            body += chunk.toString();
        }).on('end', () => {
            callback(null, memo + Number(body));
        }).on('error', err => {
            callback(err);
        });
    }).on('error', err => {
        callback(err);
    });
}, (err, result) => {
    if (err) {
        return console.error(err);
    }
    console.log(result);
});