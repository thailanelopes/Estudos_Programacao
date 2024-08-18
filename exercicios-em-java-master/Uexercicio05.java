package br.com.geekuniversity.secao07;

import java.util.Scanner;

public class Uexercicio05 {
public static void main(String[] args) {
	
	//variáveis
	String nome, senha;
	Scanner teclado = new Scanner(System.in);
	
	
	//entrada
	System.out.println("informe o nome: ");
	nome = teclado.next();
	
	System.out.println("informe a Senha: ");
	senha = teclado.next();
	
	
	//processamento
	while(nome.equals(senha)) { //nome.equals(senha), é a forma de se comparar strings em java. Ou seja, enquando nome for igual a senha, processar entrada.
		System.out.println("Erro: o nome de usuário e a senha devem ser diferentes.");
		//entrada
		System.out.println("informe o nome: ");
		nome = teclado.next();
		
		System.out.println("informe a Senha: ");
		senha = teclado.next();
	}
	teclado.close();
	
	
}
}
