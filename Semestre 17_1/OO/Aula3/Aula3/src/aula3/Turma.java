package aula3;


public class Turma{
	int cod_turma;
	String nome_disciplina;
	int codigo;
	int vaga_total;
	int vaga_ocupadas;	
	int vaga_livre;
	public Turma(){		
	}
        public void PreencheTurma(int codigo, String nome, int total, int ocupadas){
                cod_turma = codigo;
                nome_disciplina = nome;
                vaga_total = total;
                vaga_ocupadas = ocupadas;
                vaga_livre = total - ocupadas;
        }
        
        public void ImprimeTurma(){
            System.out.printf("Disciplina: %s\nCódigo: %d\nTotal de Vagas: %d\nVagas Ocupadas: %d\nVagas Disponíveis: %d\n", nome_disciplina, cod_turma, vaga_total, vaga_ocupadas, vaga_livre);
        };
                
}