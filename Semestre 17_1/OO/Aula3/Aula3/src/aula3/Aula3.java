/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula3;

import java.util.Scanner;

public class Aula3{
	public static void main(String [] args){
		Scanner teclado;			
		Turma A, B;
		Aluno a1;
		teclado = new Scanner(System.in);
		A = new Turma();
                B = new Turma();   
                a1 = new Aluno();	

                A.PreencheTurma(13, "Desenvolvimento Avançado de Software", 30, 30);
                B.PreencheTurma(25, "Orientação por Objetos", 45, 35);
	 	A.ImprimeTurma();
                System.out.println("");
                B.ImprimeTurma();
                
								
	}
}