var iPromise = new Promise((resolve, reject) => {
    if (true) {
        throw 'something broke. jk im a troll'
        resolve('resolved')
    } else {
        reject('rejected!')
    }
});
console.log(1)
setTimeout(console.log, 0, 3)
iPromise.then(console.log('otherwords (4)'), console.log).catch(console.log)
console.log(2)