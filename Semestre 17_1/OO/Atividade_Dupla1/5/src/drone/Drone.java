package drone;

/**
 *
 * @author matheusroberto
 */
public class Drone {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        droneClass drone1;
        drone1 = new droneClass();
        
        drone1.aumentar_vel_horizontal();
        drone1.aumentar_vel_horizontal();
        drone1.aumentar_vel_vertical();
        drone1.iniciar_interromper_gravacao();
        
        drone1.imprime_estados();
    }
    
}
