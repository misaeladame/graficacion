package e_01_sistemasnumericos_p;

import java.util.Scanner;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class E_01_SistemasNumericos_P {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n;
        System.out.println("Numero: ");
        try {
            // n = leer.nextInt();  //nextInt();   //try-catch
            n = Integer.parseInt(leer.next());
        } catch(NumberFormatException e) {
            System.out.println("ERROR ENTRADA NO VALIDA, Mensaje del compilador");
            System.out.println("SE ASIGNARA UN VALOR PO DEFAULT -> 5 ");
            n = 5;
        }
        //int [] binario = dec_bin(n);
        
        int [] binario = new int[32];
        dec_bin(n, binario);
        
        for(int i = binario.length - 1; i >= 0; i--)
            System.out.println(binario[i]);
        System.out.println();
        
    }
    
    static public int [] dec_bin(int num) {
        int i = 0; //, cont = 0;
        int[] resul = new int[32]; // ARREGLO DINAMICO
                            // new RESERVA EMORIA EN EL HEAP
        while(num > 0) {
            resul[i] = num % 2;
            num = num / 2;
            i++;
                //cont++
        }
        int [] aux = new int[resul.length];
        
        for(int ii = resul.length - 1, j = 0; ii >= 0; ii--, j++)
            aux[j] = resul[ii]; //ESCRIBIR EN SENTIDO INVERSO
        return aux;
    }
    
    static public void dec_bin(int num, int aux[]) {
        int i = 0; //, cont = 0;
        while (num > 0) {
            aux[i] = num % 2;
            num = num / 2;
            i++;
        }
    }   
}
