
function * fibonacci(){

    let a = 0;
    let b = 1;

    while(true){
        yield a;

        let c = a + b;
        a = b;
        b = c;
    }
}

const fibGen = fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);