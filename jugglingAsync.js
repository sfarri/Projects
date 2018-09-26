var http = require('http');
// let body = "";

// http.get(process.argv[2], (response) => {
//     response.setEncoding('utf8');
//     response.on('data', (data) => {
//         body += data;
//     }).on('end', () => {
//         console.log(body);
//         body = "";
//         http.get(process.argv[3], (response) => {
//             response.setEncoding('utf8');
//             response.on('data', (data) => {
//                 body += data;
//             }).on('end', () => {
//                 console.log(body);
//                 body = "";
//                 http.get(process.argv[4], (response) => {
//                     response.setEncoding('utf8');
//                     response.on('data', (data) => {
//                         body += data;
//                     }).on('end', () => {
//                         console.log(body);
//                         body = "";
//                     }).on('error', console.error)
//                 });
//             }).on('error', console.error)
//         });
//     }).on('error', console.error)
// });

function main(url1, url2, url3) {
    var container = []
    httpGet(url1, container);
    httpGet(url2, container);
    httpGet(url3, container);
}

function httpGet (index) {
    let body = "";
    http.get(process.argv[2 + index], function (response) {
        response.setEncoding('utf8');
        response.on('data', (data) => {
            body += data;
        }).on('error', console.error)

        results[index] = data.toString()
        count++

        if (count === 3) {
          printArray(results)
        }
      })
    }
  for (var i = 0; i < 3; i++) {
    httpGet(i)
  }

function httpGet(url, container) {
    let body = "";
    http.get(url, (response) => {
        response.setEncoding('utf8');
        response.on('data', (data) => {
            body += data;
        }).on('end', () => {
            //console.log(body)
            container.push(body);
            return container;
            if (container.length >= 3) {
                printArray(container);
            }
        })
    }).on('error', console.error)
}

function printArray(body) {
    body.forEach(element => {
        console.log(element);
    });
}

//------------------------------------------
var http = require('http')
var bl = require('bl')
var results = []
var count = 0

function printResults () {
  for (var i = 0; i < 3; i++) {
    console.log(results[i])
  }
}

function httpGet (index) {
  http.get(process.argv[2 + index], function (response) {
    response.pipe(bl(function (err, data) {
      if (err) {
        return console.error(err)
      }

      results[index] = data.toString()
      count++

      if (count === 3) {
        printResults()
      }
    }))
  })
}

for (var i = 0; i < 3; i++) {
  httpGet(i)
}

// main(process.argv[2], process.argv[3], process.argv[4]);