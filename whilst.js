var http = require('http'),
    async = require('async'),
        url = process.argv[2],
        test = "";

async.whilst(() => { return test != "meerkat"}, (callback) => {  })