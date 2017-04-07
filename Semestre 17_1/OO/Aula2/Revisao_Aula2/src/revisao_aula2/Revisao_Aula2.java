/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package revisao_aula2;

import java.util.Scanner;

/**
 *
 * @author matheusroberto
 */
public class Revisao_Aula2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Revisão Aula 2");
        Aluno a1;
        int i;
        String n;
        float nt;
        System.out.println("Qual é o seu nome?");
        n = scanner.nextLine();
        System.out.println("Qual é a sua idade?");
        i = scanner.nextInt();
        System.out.println("Qual foi a sua nota?");
        nt = scanner.nextFloat();
        a1 = new Aluno(i, n, nt);
        System.out.printf("Nome do aluno: %s\nIdade do aluno: %d\nNota do aluno: %.1f\n", a1.nome, a1.idade, a1.nota);
        if(a1.nota > 5){
            System.out.println("Parabéns! Você passou!");
        }
        else{
            System.out.println("Infelizmente você não conseguiu passar.");
        }
    }
    
}
