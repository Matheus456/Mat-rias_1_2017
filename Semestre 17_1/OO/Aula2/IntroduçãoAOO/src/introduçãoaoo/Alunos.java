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
public class Alunos {
    /*Atributos*/
    int matricula;
    String nome;
    int idade;
    char sexo;
    
    /*Método Principal(Construtor)*/
    public Alunos(){
        matricula = 13;
        nome = "Matheus Roberto";
        idade = 21;
        sexo = 'M';
    }

    /*Sobrecarga de função, um tipo de polimorfismo.*/
    public Alunos(int m, String n, int i, char s){
        matricula = m;
        nome = n;
        idade = i;
        sexo = s;
    }
    
    /*Métodos*/  
}
