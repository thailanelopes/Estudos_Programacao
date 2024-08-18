package program2;

import java.awt.BorderLayout;

import javax.swing.JButton;

import javax.swing.JFrame;

import javax.swing.JPanel;

public class program2 {

	public static void main(String[] args) {
	  JFrame frame = new JFrame("Geek university"); //JFrame cria uma tela.
		
	  JPanel panel = new JPanel(); //Jframe agrupa elementos na tela.
	  
	  JButton buton1 = new JButton("Seja bem vindo(a)"); 
		
	  JButton buton2 = new JButton("programação");
	  
	  JButton buton3 = new JButton("Introdução a linguagem Java"); //JButton adiciona elementos a tela (neste caso botões, buton1,buton2, buton3).
	  
	  panel.setLayout(new BorderLayout(1,0)); //define o tipo de layout a ser utilizado(esse tipo de layout define a tela em: norte, sul, leste, oeste).
	  
	  panel.add(buton1, BorderLayout.NORTH); 
	  panel.add(buton2, BorderLayout.CENTER);
	  panel.add(buton3, BorderLayout.SOUTH); //orienta a posição dos botões.
	  
	  frame.setContentPane(panel); //adiciona o painel dentro da tela.
	  frame.pack(); //empacota todos os componetes dentro do frame.
	  frame.setSize(640, 480); //define o tamanho da tela.
	  frame.setVisible(true); //faz com que após a execução do programa, a tela se torne visível.
	   
	}
}
//esta é uma aplicação desktop