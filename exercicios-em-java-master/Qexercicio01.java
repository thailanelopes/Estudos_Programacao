package br.com.geekuniversity.secao07;

import java.util.Scanner;

public class Qexercicio01 {
public static void main(String[] args) {
	
	//Variáveis
	int numero, maior = 0;
	Scanner teclado = new Scanner(System.in);
	
	//entradas
	System.out.println("Informe um número: ");
	numero = teclado.nextInt();
	
	while(numero != 0) {
		if(numero > maior) {
			maior = numero;
		}
		System.out.println("Informe um número: ");
		numero = teclado.nextInt();
		
	}
	System.out.printf("O maior número é %d", maior);
	teclado.close();
}
}
