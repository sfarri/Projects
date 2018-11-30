var promise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("RESOLVED");
        reject(new Error("REJECTED"));
    }, 300);
});

var goodPromise = Promise.resolve("RESOLVED");
var badPromise = Promise.reject(new Error("REJECTED"));

badPromise.then(console.log(goodPromise)).catch(err => {
    console.error(`THERE IS AN ERROR ${err.message}`);
});

