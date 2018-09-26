(async () => {
    console.log('1');
    await Promise.resolve('4').then(console.log);
    setTimeout(console.log, 0, '5');
    setTimeout(console.log , 0, '6');
    var shoppe = '2';
    await Promise.resolve(shoppe).then(console.log);
    console.log('3');
})();