package evaluacion01_18131209;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class Evaluacion01_18131209 {

    public static void main(String[] args) {
        char opc = 's';
        Scanner entrada = new Scanner(System.in);
        System.out.println("**PROGRAMA PARA ESCRIBIR Y LEER UN ARCHIVO DE UN "
                + "VECTOR UNIDIMENSIONAL DE DIMENSION ENTRE 5 Y 20 ELEMENTOS CON "
                + "DATOS ALEATORIOS** \n");
        do {
            try {
                File archivo = new File("texto.txt");
                try (FileWriter escribir = new FileWriter(archivo,true)) {
                    Random x = new Random();
                    int vec[] = new int[x.nextInt(16)+5];

                    for(int i = 0; i < vec.length; i++) {
                        vec[i] = x.nextInt(90)+10;
                        escribir.write(+i+1 +". Resultado:   " +vec[i] +"\n");
                    }
                    escribir.write("\n");
                }
            } catch(IOException e) {
                System.out.println("Error al escribir");
            }
            System.out.println("¿Desea leer el archivo? (escribe 's' para "
                     + "continuar sino cualquier otro caracter para cancelar)");
            opc = entrada.next().charAt(0);
            if(opc=='s') {
                String texto = "";
                try {            
                    FileReader lector = new FileReader("texto.txt");
                    BufferedReader contenido = new BufferedReader(lector);

                    while((texto = contenido.readLine()) != null) {
                        System.out.print(texto);
                        System.out.println();
                    }
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
