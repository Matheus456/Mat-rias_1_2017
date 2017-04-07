
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author matheusroberto
 */
public class introducao {
    public static void main(String[] ags){
        
        /*JOptionPane.showMessageDialog(null, "Hello Word!"); 
        Já aparece com uma janela.
        */
        
        String nome, resposta = "", Speso;
        float peso, imc, stringpeso;
        double altura;
       
        nome = JOptionPane.showInputDialog("Qual eh o seu nome?");
        peso = 82.0f;
        altura = Double.parseDouble(JOptionPane.showInputDialog("Qual é a sua altura?"));
        imc = peso/(float)(altura * altura);
        Speso = "50";
        resposta += "O imc do " + nome;
        stringpeso = Float.parseFloat(Speso); //Passa para float
        
        JOptionPane.showMessageDialog(null, "O imc do " + nome + " é " + imc);
        
        System.out.printf("String para float: %.2f\n", Float.valueOf(Speso));
        System.out.printf("O imc do %s é %.2f\n", nome, imc);
        System.out.printf("Teste: %s\n", resposta);
        
    }
}
