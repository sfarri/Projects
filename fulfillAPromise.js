var input = true;

var promise = new Promise((resolve, reject) => {
    setTimeout(() => {
        if (input == true) {
            return resolve("FULFILLED!");
        } else {
            return reject(new Error("REJECTED!"));
        }
    }, 300);
});
promise.then(console.log, error => console.error(error.message))