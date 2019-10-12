import 'materialize-css/dist/css/materialize.css';

function createDocument() {
    const container = document.createElement('div');

    container.innerHTML = "<h1>Hello Park Control!</h1>";
    container.innerHTML += "Whazzup?";
    container.innerHTML += "<a class='waves-effect waves-light btn'>My Button</a>";

    return container; 
}

document.body.appendChild(createDocument());
