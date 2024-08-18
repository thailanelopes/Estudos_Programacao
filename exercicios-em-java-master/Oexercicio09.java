package br.com.geekuniversity.secao06;

import java.util.Scanner;

public class Oexercicio09 {
public static void main(String[] args) {
	
	//Variáveis
	float indice;
	Scanner teclado = new Scanner(System.in);
	
	//Entrads
	System.out.println("Informe o indice de poluição: ");
	indice = teclado.nextFloat();
	
	//Processamento
	if(indice >= 0.3 && indice < 0.4) {
		System.out.println("Atençãa: Indústrias do primeiro grupo devem suspender as atividades.");
		
	}else if(indice >= 0.4 && indice < 0.5) {
		System.out.println("Atenção: Indústrias do primeiro e segundo grupo devem suspender as atividades.");
	}else if(indice >= 0.5) {
		System.out.println("Atenção: Todos os grupos devem suspender as atividades.");
	}
	
	teclado.close();
	
}
}
