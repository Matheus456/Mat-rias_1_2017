package aula3;

public class Aluno{
	int matricula;
	String nome;
	String email;
 	public Aluno(){
	}
	
	public void Aluno(String n, int m, String e){
	System.out.printf("Nome: %s\n", n);
	System.out.printf("Matricula: %d\n", m);
	System.out.printf("Emai: %s\n", e);					
	}
}