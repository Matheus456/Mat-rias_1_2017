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
        droneClass drone1, drone2, drone3, drone4;
        drone1 = new droneClass("Hubsan", "X4 mini", 4, "SD", 10, 10, 7, 150); 
        drone2 = new droneClass("Hubsan", "H501S X4 FPV", 4, "HD", 12, 12, 20, 1000); 
        drone3 = new droneClass("DJI", "Mavic Pro", 4, "UHD", 16, 16, 27, 13000); 
        drone4 = new droneClass("DJI", "Spreading Wings", 8, "SUHD", 16, 16, 15, 13000); 
      
        drone1.imprime_estados();
        drone2.imprime_estados();
        drone3.imprime_estados();
        drone4.imprime_estados();
    }
    
}
