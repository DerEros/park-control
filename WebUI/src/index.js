function createDocument() {
    const container = document.createElement('div');

    container.innerHTML = "<h1>Hello Park Control!</h1>";
    container.innerHTML += "Whazzup?";

    return container; 
}

document.body.appendChild(createDocument());
