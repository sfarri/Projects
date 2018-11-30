var promise = new Promise((fulfill, reject) => {
    fulfill("PROMISE VALUE");
    reject("REJECTED VALUE");
});

promise.then(console.log);
console.log("MAIN PROGRAM");