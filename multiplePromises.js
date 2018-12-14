function all(promise1, promise2) {
    return new Promise((resolve, reject) => {
        var counter = 0;
        var results = [];

        promise1.then(result => {
            results.push(result);
            counter++;
            if (counter >= 2) {
                resolve(results);
            }
        });
        promise2.then(result => {
            results.push(result);
            counter++;
            if (counter >= 2) {
                resolve(results);
            }
        });
    });
}

all(getPromise1(), getPromise2()).then(response => {
    console.log(response);
})