// Symbol 의 사용 

// ES6 부터 가능

// let none = 1;
// let black = 2;
// let white = 3;
// if(test == none)
// if(test == 1)  둘다 사용가능

let none = Symbol("none");
let black = Symbol("black");
console.log(none.toString());   // 설명 확인 
let test = black
console.log(test == none)