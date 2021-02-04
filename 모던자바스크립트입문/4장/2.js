'use strict';

function f(x) // 함수 선언 
{
    return x*2
}
const hi = function sayHi(){console.log('hi!');}; //함수 리터럴

const x = 2;
hi()
console.log(f(x))

// 객체의 메서드

const circle={
    center:{x:1.0,y:2.0},   // 원의 중점
    radius:2.5,  //반지름
    area: function(){   //객체안 함수 (메서드)
        return Math.PI*this.radius*this.radius;
    }
};

// 나중에 추가 가능 
circle.translate = function(a,b){
    this.center.x += a;
    this.center.y += b; };
console.log(circle.center);
circle.translate(1,2);
console.log(circle.area());
console.log(circle.center);