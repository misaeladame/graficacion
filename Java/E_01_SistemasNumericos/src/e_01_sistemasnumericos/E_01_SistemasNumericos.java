package e_01_sistemasnumericos;

import java.util.Scanner;

/**
 *
 * @author José Misael Adame Sandoval 
 */
public class E_01_SistemasNumericos {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        System.out.println("**PROGRAMA CON UN METODO PARA CONVERTIR UN NUMERO "
                + "DECIMAL EN SU REPRESENTACION BINARIA**\n");
        System.out.println("Ingrese su numero decimal: ");
        int num = leer.nextInt();        
        System.out.println("El numero en binario es: " +ConversionBinario(num));
    }
    
    public static String ConversionBinario (int num) {
        String binario = "";
        int modulo;
        while(num > 0) {
            modulo = num % 2;
            binario = modulo + "" +binario;
            num = num / 2;                
        }
        return binario;       
    }    
}
