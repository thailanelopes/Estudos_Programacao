console.log(Math.ceil(6.1))


//para criar um atributo dentro de um objeto, você pode criar a notação ponto, mesmo que o atributo não esteja no Objeto.
const obj1 = {}
obj1.nome = 'Bola'
//obj1['nome'] = 'Bola2'

console.log(obj1.nome)

//associando o nome ao objeto que for criado.

function Obj(nome){
    this.nome = nome
    this.exec = function(){
        console.log('Exec...')
    }
}

const obj2 = new obj1('Cadeira')
const obj3 = new obj1('Mesa')
console.log(obj2.nome)
console.log(obj3.nome)
obj3.exec()
//os membros de um objeto ou de uma função, são acessados por uma notação ponto.