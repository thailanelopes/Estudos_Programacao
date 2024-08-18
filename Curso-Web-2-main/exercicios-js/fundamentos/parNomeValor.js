// par nome/valor

const saudacao = 'Opa' //contexto léxico 1 (ou seja: em que local físico do seu código a variável/ par/ chave ou valor foi definido.)

function exec(){
    const saudacao = 'Falaaa' //contexto léxico 2 (par/chave/vlor está no contexto de uma função.)
    return saudacao
}

//Objetos são grupos aninhados de pares nome/valor.
const cliente = {
    nome: 'Pedro',
    idade: 32,
    peso: 90,
    endereco: {
        logradouro: 'Rua Muito Legal',
        numero: 123
    }
}

console.log(saudacao)
console.log(exec())
console.log(cliente)