var http = require('http');
var fs = require('fs');

var port = process.argv[2] || 8000;
var fileName = process.argv[3];

http.createServer(function (req, res) {
    fs.createReadStream(fileName).pipe(res);
}).listen(port);