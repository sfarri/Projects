var input = false;

var promise = new Promise((fulfill, reject) => {
    setTimeout(() => {
        if (input == true) {
            return fulfill("FULFILLED!");
        } else {
            return reject(new Error("REJECTED!"));
        }
    }, 300);
});
promise.then(console.log, error => console.error(error.message))