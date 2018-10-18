var http = require('http'),
    async = require('async'),
        path1 = process.argv[2],
        path2 = process.argv[3];

        function buildGetRequest(path) {
            return function(callback) {
                http
                .get(path, res => {
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
                })
            }
        }

async.series({
    requestOne: buildGetRequest(path1),
    requestTwo: buildGetRequest(path2)
}, (err, result) => {
    if (err) {
        return console.error(err);
    }
    console.log(result);
});