import 'materialize-css/dist/css/materialize.min.css';
import './material-icons.css';
import 'materialize-css/dist/js/materialize.min.js'

function createDocument() {
    const container = document.createElement('div');

    container.innerHTML = "<h1>Hello Park Control!</h1>";
    container.innerHTML += "Whazzup?";
    container.innerHTML += "<a class='waves-effect waves-light btn'>My Button</a>";
    container.innerHTML += "<br/>";
    container.innerHTML += require('./main-page.html');

    return container; 
}

document.body.appendChild(createDocument());

document.addEventListener('DOMContentLoaded', function() {
    var elems = document.querySelectorAll('.collapsible');
    var instances = M.Collapsible.init(elems, {});
});
