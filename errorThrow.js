function parsedPromise(json) {
    return new Promise((resolve, reject) => {
        try {
            //resolve("Resolved");
            resolve(JSON.parse(json));
        }
        catch (e) {
            reject(e);
        }
    })
};

function onReject(error) {
    console.log(error.message);
};

function onResolve(data) {
    console.log(data);
};

parsedPromise(process.argv[2]).then(onResolve, onReject);