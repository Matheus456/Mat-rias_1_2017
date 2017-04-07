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
        droneClass d1;
        d1 = new droneClass(); 
        d1.aumentar_vel_horizontal();
        d1.aumentar_vel_vertical();
        
        d1.imprime_estados();
    }
    
}
