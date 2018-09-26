var http = require('http');
var url = process.argv[2];
let body = "";
let count = 0;

http.get(url, (response) => {
    response.setEncoding('utf8');
    response.on('data', (data) => {
        body += data;
        count += data.length;
    }).on('end', () => {
        console.log(count + "\n" + body);
    }).on('error', console.error)
});