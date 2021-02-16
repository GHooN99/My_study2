const todoForm = document.querySelector('.js-todoForm'),
    todoInput = todoForm.querySelector('input'),
    todoList = document.querySelector('.js-todoList');

let todosArray = [];

function deleteTodo(event){
    const li = event.target.parentNode;
    todoList.removeChild(li);
    const cleanedTodos = todosArray.filter(function(todo){
        return parseInt(li.id) !== todo.id;
    });
    console.log(cleanedTodos);
    todosArray = cleanedTodos;
    saveTodos();
}
function saveTodos(){
    console.log(todosArray);
    localStorage.setItem('toDos',JSON.stringify(todosArray));
}
function paintTodo(text){
    console.log(text);
    const li = document.createElement('li');
    const deleteBtn = document.createElement('button');
    const span = document.createElement('span');
    const newId = Date.now();
    const todosObj = {
        id:newId,
        text:text,  
    };
    deleteBtn.addEventListener('click', deleteTodo);
    deleteBtn.innerHTML = "X";
    span.innerText = text;
    li.id = newId;
    li.appendChild(span);
    li.appendChild(deleteBtn);
    todoList.appendChild(li);

    todosArray.push(todosObj);
    saveTodos();
}
function handleSubmit(event){
    event.preventDefault();
    const currentValue = todoInput.value;
    paintTodo(currentValue);
    todoInput.value = "";
}

function loadTodos(){
    const loadTodos = localStorage.getItem("toDos");
    if (loadTodos!==null){ 
        const parsedTodos =JSON.parse(loadTodos);
        parsedTodos.forEach(function(todo){
            paintTodo(todo.text);
        });
    }
}

function init(){
    loadTodos();
    todoForm.addEventListener("submit",handleSubmit);

}   
init();