function alwaysThrows() {
    throw new Error("OH NOES");
}

function iterate(count) {
    console.log(count);
    return count + 1;
}

function onResolve() {
    console.log("WIN!");
}

function onReject(error) {
    console.log(error.message)
}

Promise.resolve(iterate(1))
    .then(iterate)
    .then(iterate)
    .then(iterate)
    .then(iterate)
    .then(alwaysThrows)
    .then(iterate)
    .then(iterate)
    .then(iterate)
    .then(iterate)
    .then(iterate)
    .then(onResolve)
    .catch(onReject);