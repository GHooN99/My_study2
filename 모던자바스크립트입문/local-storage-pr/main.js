const form = document.querySelector(".js-form");
const input = form.querySelector("input");
const greeingText = document.querySelector(".greeting");
const changeBtn = document.querySelector(".js-delete");
const btn = changeBtn.querySelector("input");

function deleteName(){
    localStorage.removeItem();
}
function handleChange(event){
    event.preventDefault();
    deleteName();
    changeBtn.classList.remove("showing");
    handleSubmit();
}

function saveName(name){
    localStorage.setItem("currentUser",name);
}

function paintName(user){
    changeBtn.classList.add("showing");
    form.classList.remove("showing");
    greeingText.classList.add("showing");
    greeingText.innerHTML = `Welcome ${user}!`;
}
function handleSubmit(event){
    event.preventDefault();
    console.log(input.value);
    const name = input.value;

    paintName(name);
    saveName(name);
}
function getName(){
    form.classList.add("showing");
    form.addEventListener("submit",handleSubmit);
}

function loadName(){
    const currentUser = localStorage.getItem("currentUser");
    if (currentUser === null)
        getName();
    else 
        paintName(currentUser);
}

function changeName(){
    changeBtn.addEventListener("submit",handleChange);
}

function init() {
    loadName();
    changeName();
}

init();