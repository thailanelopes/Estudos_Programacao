package br.com.geekuniversity.secao02;

import java.util.Scanner; //sintax para se realizar imports de bibliotecas que iremos utilizar no programa.

public class Aexercicio02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//variáveis
		int num1, num2, soma, multiplicacao;
		Scanner teclado = new Scanner(System.in); //"teclado" é o responsável por receber dados via teclado. O equivalente ao "scanf" na linguagem C.
		
		//Entradas
		System.out.println("Informe o primeiro número: "); //"println" é utilizado quando você quer escrever a mensagem e pular uma linha.
		num1 = teclado.nextInt(); //"nextInt" é a função do tipo de dados que receberemos, um tipo de dado inteiro(int). Se a variável fosse float, utilizariamos "nextFloat".
		System.out.println("Informe o segundo número: ");
		num2 = teclado.nextInt();
		
		//processamento
		soma = num1 + num2;
		multiplicacao = soma * num1;
		
		//saída
		System.out.println("O resultatdo da multiplicação é " + multiplicacao);
		
		teclado.close(); //fechar o recurso teclado que está em execussão.
	}

}
