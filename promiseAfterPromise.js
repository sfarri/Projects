// var firstPromise = first();

// var secondPromise = firstPromise.then(value => { 
//     return second(value) 
// });

// secondPromise.then(console.log);

var promise = first().then(value => { 
    return second(value) 
}).then(console.log);