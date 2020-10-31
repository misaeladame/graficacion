package repaso;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class Repaso {

    public static void main(String[] args) {
        char opc = 's';
        do {
           // Random x = new Random();
            //int[] m = new int[x.nextInt(16)+5];;

            Scanner entrada = new Scanner(System.in);
            System.out.print("¿Cuántos elementos? ");

            // VALIDAR LA ENTRADA, QUE SEA UN ENTERO 
            int n;
            try {
                //int n = entrada.nextInt(); 
                n = Integer.parseInt(entrada.next());
            }
            catch(NumberFormatException e) {
                System.out.println("ERROR, ENTRADA NO VALIDA");
                System.out.println("SE USARA COMO VALOR POR DEFAULT : 5");
                n = 5;
            }

            int [] m = new int[n];
            Random r;
            for(int i = 0; i < m.length; i++) {
                r = new Random();
                m[i] = r.nextInt(90)+10;
                System.out.println(+i+1 +". RESULTADO: " +m[i]);
            }

            System.out.println("¿Generar nuevos números");
            opc = entrada.next().charAt(0);
            
        } while(opc == 's');       
    }     
}
