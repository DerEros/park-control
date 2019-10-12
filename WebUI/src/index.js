function createDocument() {
    const container = document.createElement('div');

    container.innerHTML = "<h1>Hello Park Control!</h1>";

    return container; 
}

document.body.appendChild(createDocument());
