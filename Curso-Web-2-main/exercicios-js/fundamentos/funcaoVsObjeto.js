console.log(typeof Object) //isso é uma função
console.log(typeof new Object) //um objeto criado a partir de uma função. Seria como a chamada de um construtor, como ocorre no Java.

const Cliente = function() {}
console.log(typeof Cliente)
console.log(typeof new Cliente)

class Produto {}
console.log(typeof Produto)
console.log(typeof new Produto())

/*A forma de criar objeto em javaScript é apartir de função*/