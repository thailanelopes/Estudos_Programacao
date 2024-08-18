package br.com.geekuniversity.secao07;

import java.util.Scanner;

public class Vexercicio06 {
public static void main(String[] args) {
	
	//Variáveis.
	int numero;
	Scanner teclado = new Scanner(System.in);
	
	//Entradas
	System.out.println("Informe um número entre 1 e 10: ");
    numero = teclado.nextInt();
    
    //Processamento
    while(numero < 1 || numero > 10) {
    	//Entradas
    	System.out.println("Informe um número entre 1 e 10: ");
        numero = teclado.nextInt();
    }
	for(int i = 1; i <= 10; i++) {
		System.out.printf("%d X %d = %d\n", numero, i, (numero * i));
	}
	teclado.close();
}
}
