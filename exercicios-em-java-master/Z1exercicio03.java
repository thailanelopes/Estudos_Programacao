package br.com.geekuniversity.secao08;

import java.util.Scanner;

public class Zexercicio03 {
public static void main(String[] args) {
	
	//Variáveis
	int[] vetor = new int[10] ;
	Scanner teclado = new Scanner(System.in);
	
	//Entrada
	for (int i = 0; i < 10; i++) {
	System.out.println("Informe o valor para o vetor");
	vetor[i] = teclado.nextInt();
	}
	
	for (int i = (vetor.length -1); i >= 0; i--) { //(vetor.length -1) faz a inversão do vetor do ultimo vetor para o primeiro.
		System.out.println(vetor[i]);
	}
	teclado.close();
} 
}
