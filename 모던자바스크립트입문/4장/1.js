// 객체 리터럴

var card = { suit : "하트",rank : "A"};
console.log(card);
//두개 같음
console.log(card.rank);
console.log(card["rank"]);
// 프로퍼티 추가 
card.val = 14 ;
console.log(card);
// 프로퍼티 삭제
delete card.suit;
console.log(card);
console.log("suit" in card);

// 실험
const a  ={x:5,y:7};
a = {z:5,w:50};     //얘는 안됨
a.z = 5;
a.x = 10;
console.log(a);