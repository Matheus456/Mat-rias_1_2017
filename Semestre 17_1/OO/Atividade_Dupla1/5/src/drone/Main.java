package drone;

/**
 *
 * @author matheusroberto
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Drone drone1;
        drone1 = new Drone();
        
        drone1.aumentar_vel_horizontal();
        drone1.aumentar_vel_horizontal();
        drone1.aumentar_vel_vertical();
        drone1.iniciar_interromper_gravacao();
        
        drone1.imprime_estados();
    }
    
}
