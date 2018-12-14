var http = require("q-io/http");

http.read('http://localhost:7000')
.then(response => response.toString())
.then(response => {
    http.read(`http://localhost:7001/${response}`)
    .then(JSON.parse)
    .then(console.log)
});