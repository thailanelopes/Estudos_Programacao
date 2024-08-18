package br.com.geekuniversity.secao06;

import java.util.Scanner;

public class Lexercicio06 {
public static void main(String[] args) {
	
	//Variáveis
	int codigo;
	float numero_horas_trabalhadas, excedente = 0, salario, valor_hora = (float) 10.00;
	Scanner teclado = new Scanner(System.in);
	
	//entradas
	System.out.println("Informe o código: ");
	codigo = teclado.nextInt();
	System.out.println("Informe a quantidade de horas trabalhadas: ");
	numero_horas_trabalhadas = teclado.nextFloat();
	
	//processamento
	if(numero_horas_trabalhadas > 50) {
		excedente = (float)(numero_horas_trabalhadas - 50) * (float)20.00;
		salario = (50 * valor_hora) + excedente;
		System.out.printf("Salário total R$ %.2f\n", salario);
		System.out.printf("Salário excedente R$ %.2f\n", excedente);
	}else {
		salario = numero_horas_trabalhadas * valor_hora;
		System.out.printf("Salário total R$ %.2f\n", salario);
		System.out.printf("Salário excedente R$ %.2f\n", excedente);
		
	}
	
	teclado.close();
	
}
}
