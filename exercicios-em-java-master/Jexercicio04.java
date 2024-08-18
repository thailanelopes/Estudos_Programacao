package br.com.geekuniversity.secao06;

import java.util.Scanner;

public class Jexercicio04 {
public static void main(String[] args) {
	
	//variáveis
	float altura, peso_ideal;
	char sexo;
	Scanner teclado = new Scanner(System.in);
	
	//entradas
	System.out.println("Informe sua altura: ");
	altura = teclado.nextFloat();
	
	System.out.println("Informe o seu sexo m/f: ");
	sexo = teclado.next().charAt(0); //para se receber char usamos next, porém ele só pega uma string, para pegar mais escrevemos nextLine.
                                     //	.charAt(0), devolvel um caractere M ou F.
	
	//processamento
	if(sexo == 'm') { // m está com aspas simples poque é um caractere, em java caracteres levam aspas simples(''), enquanto Strings levam aspas duplas("").
		peso_ideal = (float)(72.7 * altura) - 58; //colocamos o cast (float) para que o programa retorne o resultado do tipo float e não double.
		System.out.printf("Seu peso ideal é %.2f",peso_ideal);
	}
	if(sexo == 'f') {
		peso_ideal = (float)(62.1 * altura) - (float)44.7;
		System.out.printf("Seu peso ideal é %.2f",peso_ideal);
	}
	if(sexo != 'm' && sexo != 'f') {
		System.out.println("Sexo não identificado");
		peso_ideal = 0;
		
	}
	teclado.close();
}
   
}
