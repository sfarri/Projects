var http = require('http'),
    async = require('async'),
        hostname = process.argv[2],
        port = process.argv[3];

async.series({
        post: callback => {
            var opts = {
                hostname: hostname,
                port: port,
                method: 'POST',
                path: '/users/create'
            };
            async.times(5, (i, timesDone) => {
                    var req = http.request(opts, res => {
                        res.on('data', chunk => {
                            //empty
                        }).on('end', () => {
                            timesDone(null);
                        }).on('error', err => {
                            return console.error(err);
                        });
                    }).on('error', err => {
                        return console.error(err);
                    });
                    var data = JSON.stringify({
                        user_id: i + 1
                    });
                    req.write(data);
                    req.end();
                },
                err => {
                    if (err) {
                        return console.error(err);
                    }
                    callback(null);
                });
        },
        get: callback => {
            http.get('http://' + process.argv.slice(2).join(':') + '/users', res => {
                var body = '';
                res.on('data', chunk => {
                        body += chunk.toString();
                    })
                    .on('end', () => {
                        callback(null, body)
                    });
            })
        }
    },
    (err, results) => {
        if (err) {
            return console.error(err);
        }
        console.log(results.get);
    });