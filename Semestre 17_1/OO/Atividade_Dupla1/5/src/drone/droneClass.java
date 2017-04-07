/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package drone;

/**
 *
 * @author matheusroberto
 */
public class droneClass {
    int n_de_helices;
    String marca;
    String modelo;
    String camera;
    int vel_vert;
    int vel_hor;
    int vel_vert_max;
    int vel_hor_max;
    int autonomia_bateria;
    int distancia_max;
    boolean estado_camera;
            
    public droneClass(){};
    
    public void aumentar_vel_vertical(){
        if(vel_vert<vel_vert_max){
            vel_vert++;
        }
    }
    
    public void diminuir_vel_vertical(){
        if(vel_vert>0){
            vel_vert--;
        }
    }

    public void aumentar_vel_horizontal(){
        if(vel_hor<vel_hor_max){
            vel_hor++;
        }
    }

    public void diminuir_vel_horizontal(){
        if(vel_hor>0){
            vel_hor--;
        }
    }    
    
    public boolean iniciar_interromper_gravacao(){
        estado_camera = !estado_camera;
        return estado_camera;
    }
    
    public void diminuir_vel_max(){
        if(autonomia_bateria < 5){
            vel_hor_max = vel_hor_max/2;
            vel_vert_max = vel_vert_max/2;
        }
    }
        
    public void imprime_estados(){
        System.out.printf("Marca %s\n", marca);
        System.out.printf("Modelo %s\n", modelo);        
        System.out.printf("Número de hélices = %d\n", n_de_helices);
        System.out.printf("Câmera = %s\n", camera);
        System.out.printf("Vel.vertical.atual = %d m/s\n", vel_vert);
        System.out.printf("Vel.vertical.máx = %d m/s\n", vel_vert_max);
        System.out.printf("Vel.horizontal.atual = %d m/s\n", vel_hor);        
        System.out.printf("Vel.horizontal.máx = %d m/s\n", vel_hor_max);
        System.out.printf("Autonomia bateria = %d minutos\n", autonomia_bateria);
        System.out.printf("Distância máxima = %d metros\n", distancia_max);
        if(estado_camera == false){
        System.out.printf("Estado da camera = Desligada\n");            
        }
        else{
        System.out.printf("Estado da camera = Ligada\n");            
        }
        System.out.println("");
    }
    
    public void preenche(String m, String model, int n_hel, String cam, int vel_vert, int vel_hor, int auton, int d){
        marca = m;
        modelo = model;
        n_de_helices = n_hel;
        camera = cam;
        vel_vert_max = vel_vert;
        vel_hor_max = vel_hor;
        autonomia_bateria = auton;
        distancia_max = d;
    }
}
