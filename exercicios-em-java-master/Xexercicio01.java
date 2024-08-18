package br.com.geekuniversity.secao08;

import java.util.ArrayList;

public class Xexercicio01 {
public static void main(String[] args) {
	//Variáveis
	ArrayList<Integer> vetor = new ArrayList<Integer>(); //colexions serão ultilizados nesse caso.
	ArrayList<Integer> pares = new ArrayList<Integer>(); //não recebemos o vetor, vamos gerar como uma repetição.

	for (int i = 0; i < 5; i++) {
	   vetor.add(i); //adiciona o valor passado, dentro do vetor.
	   
	   if(i % 2 == 0) {
		   if(i > 0) {
		   pares.add(i);
		   }
	   }
	}
	
	for(Integer n : pares) { //uma outra opção de estrutura for, para utilizar quando se usa colexions.
		System.out.println(n);
		
	}
}
}
