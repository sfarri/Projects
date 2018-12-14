var http = require("q-io/http")
http.read('http://localhost:1337').then(response => JSON.parse(response)).then(console.log)