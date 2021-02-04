'use strict';

// 객체의 기초 생성자

function Card(suit,rank){
    this.suit = suit;
    this.rank = rank;
}

const card = new Card("하트","A"); // 생성자 new
console.log(card);

const now = new Date();
console.log(now.toLocaleTimeString());
