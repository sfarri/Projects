function main () {

var obj = {
    key1: ()=>1,
    key2: ()=>2,
    keyRewrite: ()=> {
        // this.keyRewrite = () => 'taco'
        return 'meep'
    },
}

console.log(obj.keyRewrite())
var moop = obj.keyRewrite();
obj.keyRewrite = () => moop+2
console.log(obj.keyRewrite())
obj.keyRewrite = () => moop+3
console.log(obj.keyRewrite())
}

main();