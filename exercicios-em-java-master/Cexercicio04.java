package br.com.geekuniversity.secao03;

import java.util.Scanner;

public class Cexercicio04 {
  public static void main(String[] args) {
	  
	  //variáveis
	int num1, num2, soma;
	Scanner teclado = new Scanner(System.in);
	
	//entradas
	System.out.println("Informe o primeiro número: ");
	num1 = teclado.nextInt();
	
	System.out.println("Informe o segundo número: ");
    num2 = teclado.nextInt();
    
    //processamento.
    soma = (num1 + num2);
    
    //saída
    System.out.println("A soma é: " + soma);
    
    teclado.close();
}
}
