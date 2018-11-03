var http = require('http'),
    async = require('async'),
        fs = require('fs'), path = process.argv[2];

async.waterfall([
    callback => {
        fs.readFile(path, 'utf-8', (err, data) => {
            if (err) return callback(err);
            callback(null, data);
        });
    },

    (data, callback) => {
        var body = '';
        http.get(data, res => {
                res.on('data', chunk => {
                        body += chunk.toString();
                    }).on('end', () => {
                        //console.log('end');
                        callback(null, body);
                    });
            }).on('error', err => {
                console.log(`ERROR: ${err}`);
                callback(err);
            });
    }
], (err, result) => {
    if (err) {
        return console.error(err);
    }
    console.log(result)
});