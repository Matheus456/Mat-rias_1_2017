/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4;

/**
 *
 * @author matheusroberto
 */
public class Aula4 {
    public static void main(String[] args)throws InterruptedException {
        Bicicleta bic1, bic2, bic3, bic4;
        bic1 = new Bicicleta();
        bic3 = bic2 = new Bicicleta("Monark", "Barra circular", "Azul", 1);

        System.out.println("Endereço de bic1: " + bic1 + " ");
        bic1.Bicicleta("Monark", "Barra circular", "Azul", 1, 0);
        bic1.Imprime();

        System.out.println("");

        System.out.println("Endereço de bic2: " + bic2 + " ");
        bic2.Bicicleta("Caloi", "Barra circular", "Preta", 3, 60);
        bic2.cor = "Rosa";
        bic2.Imprime();
     
        System.out.println("");
        bic2 = null;
        
        System.out.println("Endereço de bic3: " + bic3 + " ");
        bic3.Imprime();
        bic1 = null;
        //Thread.sleep(50000); /*Tentativa para esperar o garbage collector passar*/
        System.out.println("");
        System.gc(); /*Forçando a passagem doGarbage collector*/
        bic3.marca = "Monark";

    }
    
}
