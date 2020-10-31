package distanciaentredospuntos;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class PuntoPrueba {
    
    public static void main(String[] args) {
        Punto a = new Punto(3,5);
        Punto b = new Punto(7,8);
    
        System.out.println("La distancia entre "+a+" y "+b+" = "+a.distancia(b));  
    }
    
}
