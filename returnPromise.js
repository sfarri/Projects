// var promise = new Promise((resolve, reject) => {
//     resolve("MANHATTAN");
//     reject("reject");
// });
// promise.then(attachTitle).then(console.log);

Promise.resolve('MANHATTAN')
    .then(attachTitle)
    .then(console.log);

function attachTitle(name) {
    return `DR. ${name}`;
}