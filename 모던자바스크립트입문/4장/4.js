'use strict';

const array=[1,2,3,4];
const print = console.log; // !!
const a = 5;
print(array.length);
array.length = 10;
print(array);
// new Array 로도 생성 가능
const arr = new Array(1,3,5);
print(arr);

// 요소 맨뒤에 추가
arr.push(6);
print(arr);
// 삭제는 되나 길이가 줄지는 않음
delete arr[2];
print(arr.length); 
print(arr);
arr.pop() // 맨뒤 제거 (길이 줄지는 않네)
print(arr.length);
/*
[ 1, 3, <1 empty item>, 6 ]
3
[ 1, 3, <1 empty item> ]
*/
print(arr);