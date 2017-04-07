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
public class Bicicleta {
    String marca;
    String modelo;
    String cor;
    int n_marchas;
    int vel;
    

    public Bicicleta(){
        marca = "NULL";
        modelo = "NULL";
        cor = "NULL";
        n_marchas = 0;
        vel = -1;
    }
    
    
    public Bicicleta(String marc, String model, String c, int n){
        marca = marc;
        modelo = model;
        cor = c;
        n_marchas = n;
    }
    
    public void Bicicleta(String marc, String model, String c, int n, int v){
        marca = marc;
        modelo = model;
        cor = c;
        n_marchas = n;
        vel = v;    
    }
    
    public void Imprime(){
        System.out.printf("Marca: %s\n", marca);
        System.out.printf("Modelo: %s\n", modelo);
        System.out.printf("Cor: %s\n", cor);
        System.out.printf("Número de marchas: %s\n", n_marchas);
        System.out.printf("Velocidade: %s\n", vel);

    }
    
    /*Destrutor*/
    public void finalize() {
        System.out.println("inicio do método destrutor");
        System.out.println("meio do método destrutor");
        System.out.println("fim do método destrutor");
    
    }
}
