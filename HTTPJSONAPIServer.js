var http = require('http');
var url = require('url');
var port = process.argv[2];

http.createServer((request, response) => {
    var urlObject = url.parse(request.url, true);
    var path = urlObject.pathname;
    var startTime = urlObject.query.iso;
    var result = null;
    if (path === '/api/unixtime') {
        result = getUnixTimeStamp(startTime);
    }
    else if (path === '/api/parsetime') {
        result = getTimeObject(startTime);
    }
    if (result) {
        response.writeHead(200, { 'Content-Type': 'application/json' })
        response.end(JSON.stringify(result));
    }
    else {
        response.writeHead(404);
        response.end('Error: Path Not Found');
    }
}).listen(port);

function getUnixTimeStamp(startTime) {
    var unixTimeStamp = {
        unixtime: getTimeStamp(startTime)
    };
    return unixTimeStamp;
}

function getTimeObject(startTime) {
    var date = new Date(getTimeStamp(startTime));
    var formattedDate = { 
        hour:   date.getHours(),
        minute: date.getMinutes(),
        second: date.getSeconds()
    };
    return formattedDate;
}

function getTimeStamp(startTime) {
    return Date.parse(startTime);
}