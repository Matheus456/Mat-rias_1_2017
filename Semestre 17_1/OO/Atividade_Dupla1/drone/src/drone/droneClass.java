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
    String camera;
    int vel_vert_max;
    int vel_hor_max;
    int autonomia_bateria;
    int distancia_max;
    boolean estado_camera;
            
    public droneClass(){};
    
    public void aumentar_vel_vertical(){
        vel_vert_max++;
    }
    
    public void diminuir_vel_vertical(){
        vel_vert_max--;
    }

    public void aumentar_vel_horizontal(){
        vel_hor_max++;
    }

    public void diminuir_vel_horizontal(){
        vel_hor_max--;
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
        System.out.printf("Número de hélices = %d", n_de_helices);
        System.out.printf("Câmera = %s", camera);
        System.out.printf("Vel.vert.máx = %d", vel_vert_max);
        System.out.printf("Vel.hor.máx = %d", vel_hor_max);
        System.out.printf("Autonomia bateria = %d", autonomia_bateria);
        System.out.printf("Distância máxima = %d", distancia_max);
        System.out.printf("Estado da camera = %b", estado_camera);
    }
}
