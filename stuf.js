function fetchAsync (url, timeout, onData, onError) {
    console.log("fetcher!");
}
let fetchPromised = (url, timeout) => {
    return new Promise((resolve, reject) => {
        fetchAsync(url, timeout, resolve, reject)
    })
}
Promise.all([
    fetchPromised("temp.js", 500),
    fetchPromised("temp.js", 500),
    fetchPromised("temp.js", 500)
]).then((data) => {
    let [ foo, bar, baz ] = data
    console.log(`success: foo=${foo} bar=${bar} baz=${baz}`)
}, (err) => {
    console.log(`error: ${err}`)
})