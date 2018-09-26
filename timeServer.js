var port = process.argv[2] || 8000;
var net = require('net');

function today() {
  var date = new Date();
  return date.getFullYear() + '-' 
    + zeroFill(date.getMonth() + 1) + '-' 
    + zeroFill(date.getDate()) + ' ' 
    + zeroFill(date.getHours()) + ':' 
    + zeroFill(date.getMinutes());
}

function zeroFill(i) {
  // if (i < 10)
  //   return '0' + i;
  // else 
  //   return i;
//or
  return i < 10 ? '0' + i : i;
}

var server = net.createServer((socket) => {
  socket.write(today())
  socket.end('\n');
}).on('error', (err) => {
  throw err;
});
server.listen(port);