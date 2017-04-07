/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package introduçãoaoo;

/**
 *
 * @author matheusroberto
 */
public class IntroduçãoAOO {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
    System.out.println("Aula de introdução a OO");
    System.out.println("1º Passo: Criar uma classe de Alunos.");
    System.out.println("2º Passo: Criar os objetos");
    System.out.println("");

    Alunos a1, a2; /*Como se fosse um ponteiro, é uma referência.*/
    a1 = new Alunos(13, "Matheus", 21, 'M'); /*Como se fosse um malloc*/
    a2 = new Alunos(13, "André", 34, 'M');
    
    System.out.println("Tipo e endereço de a1:");
    System.out.println(a1); /*Mostra o tipo da variável e mostra a o endereço da
    memória*/
    System.out.println("Nome: " + a1.nome);
    System.out.println("Matricula: " + a1.matricula);
    System.out.println("Idade: " + a1.idade);
    System.out.println("Sexo: " + a1.sexo);

    System.out.println("");
    System.out.println("Tipo e endereço de a2:");
    System.out.println(a2);
    System.out.println("Nome: " + a2.nome);
    System.out.println("Matricula: " + a2.matricula);
    System.out.println("Idade: " + a2.idade);
    System.out.println("Sexo: " + a2.sexo);

    
    }
}
    
