function main() {
    var promise = new Promise((fulfill, reject) => {
        fulfill("I FIRED");
        reject(new Error("I DID NOT FIRE"));
    });

    promise.then(console.log, onRejected);
}

function onRejected(error) {
    console.error(error.message);
}

main();