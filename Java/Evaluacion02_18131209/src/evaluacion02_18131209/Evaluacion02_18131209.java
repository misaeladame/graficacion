package evaluacion02_18131209;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class Evaluacion02_18131209 {

    public static void main(String[] args) {
        char opc = 's';
        Scanner entrada = new Scanner(System.in);
        System.out.println("**PROGRAMA PARA ESCRIBIR Y LEER UN ARCHIVO BINARIO DE UN "
                + "VECTOR UNIDIMENSIONAL DE DIMENSION ENTRE 5 Y 20 ELEMENTOS CON "
                + "DATOS ALEATORIOS** \n");
        do {
            try {
                FileOutputStream archivobinario = new FileOutputStream(new File("texto.dat"));
                BufferedOutputStream escribir = new BufferedOutputStream(archivobinario);
                Random x = new Random();
                int vec[] = new int[x.nextInt(16)+5];
                for(int i = 0; i < vec.length; i++) {
                    vec[i] = x.nextInt(90)+10;
                    escribir.write(+vec[i]);
                }
                escribir.flush();
                escribir.close();
                
            } catch(IOException e) {
                System.out.println("Error al escribir");
            }
            
            if(opc=='s') {
                try {            
                    FileInputStream fis = new FileInputStream(new File("texto.dat"));
                    BufferedInputStream leer = new BufferedInputStream(fis);
                    int texto;
                    while((texto = leer.read()) != -1) {
                        System.out.print(texto);
                        System.out.println();
                    }
                    leer.close();
                    
                } catch(IOException e) {
                    System.out.println("Error al leer");
                }
            }
            System.out.println("¿Generar nuevos números? (escribe 's' para "
                     + "continuar sino cualquier otro caracter para cancelar)");
            opc = entrada.next().charAt(0);
        } while(opc == 's');
    }       
}
