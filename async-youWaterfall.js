var http = require('http')
, async = require('async')
, fs = require('fs')
, path = process.argv[2];

async.waterfall([
    cb =>{
    fs.readFile(path, 'utf-8', (err, data) => {
        if (err) {
            return cb(err);
        }
        cb(null, data);
    });
  },
    (data, cb) => {
    var body = "";
    http.get(data, res =>{
        res.on('data', chunk =>{
            body += chunk.toString();
        });
        res.on('end', () =>{
            console.log('end');
            cb(null, body);
        });
        res.on('error', err =>{
            console.log("ERROR: ${err}");
            cb(err);
        });
    })
  }
])  

