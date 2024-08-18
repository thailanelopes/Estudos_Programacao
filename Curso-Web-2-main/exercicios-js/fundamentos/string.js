const escola = "Cod3r"


console.log(escola.charAt(4)); //retornando o indice(letra) da quarta posição
console.log(escola.charAt(5)); //retornando o indice(letra) da qquinta posição (que será inexistente).
 
console.log(escola.substring(1)); // A partir do índice 1 ele irá imprimir.
console.log(escola.substring(0, 3));

console.log('Escola '.concat(escola).concat("!")); //concatenando.
console.log('Escola '+ escola + "!"); //outra forma de concatenar.

console.log(escola.replace(3, 'e')); //substituindo pela letra e.

console.log('Ana, Maria, Pedro'.split(',')); //convertendo para array.