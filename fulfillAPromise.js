var input = true

var promise = new Promise((fulfill, reject) => {
    // Your solution here
    setTimeout(() => {
        if (input == true) {
            return fulfill("FULFILLED!"); 
        }
        else {
            return reject("FAILED!");   
        }
    }, 300);
  });

  promise.then(console.log)
  // Your solution here