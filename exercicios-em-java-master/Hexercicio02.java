package br.com.geekuniversity.secao06;

import java.util.Scanner;

public class Hexercicio02 {
public static void main(String[] args) {
	//variárias.
	int numero, a, b;
	Scanner teclado = new Scanner(System.in);
	
	
	//entradas
	System.out.println("Informe um número: ");
	numero = teclado.nextInt();
	
	//processamento
	if(numero > 0) {
		a = numero;
		//saida
		System.out.println(a);
	}
	else {
		b = numero;
		//saida
		System.out.println(b);
	}
	
	teclado.close();
}
}
