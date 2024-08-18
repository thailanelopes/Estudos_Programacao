console.log('a =', a)
var a = 2
console.log('a =', a)

/*Em teoria a daria um erro, pois a variável só está definida na segunda linha.
 Porém oque acontecerá é que essa variável será içada(ocorrerá o Hoisting).
*/

/**** SAIDA*****/

/*a = undefined
a = 2*/


/* O efeito de içamento utilizando let não ocorrerá*/

console.log('b =', b)
let a = 2
console.log('b =', b)