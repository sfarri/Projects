var http = require('http');
var map = require('through2-map');

var port = process.argv[2] || 8000;

  http.createServer((request, response) => {
      if (request.method === 'POST') {
        request.pipe(map(chunk => {
            return chunk.toString().toUpperCase();
        })).pipe(response);
      }
      else 
        return response.end('Please send a POST\n');
  }).listen(port);