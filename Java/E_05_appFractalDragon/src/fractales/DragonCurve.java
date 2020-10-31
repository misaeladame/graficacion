package fractales;

/**
 *
 * @author José Misael Adame Sandoval
 */

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsConfiguration;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Random;
import java.util.Scanner;

import javax.imageio.ImageIO;

public final class DragonCurve {

    private BufferedImage img = null;
    private int IMG_WIDTH;
    private int IMG_HEIGHT;

    private GraphicsEnvironment ge = null;
    private GraphicsDevice gd = null;
    private GraphicsConfiguration gc = null;

    public DragonCurve() {
        IMG_WIDTH = 1400;
        IMG_HEIGHT = 1400;

        ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        gd = ge.getDefaultScreenDevice();
        gc = gd.getDefaultConfiguration();

    }

    private void createDragonFractal() {
        Random r = new Random();
                
        Graphics g = null;
        Graphics2D g2d = (Graphics2D) g;

        img = gc.createCompatibleImage(IMG_WIDTH, IMG_HEIGHT);
        g2d = img.createGraphics();
        g2d.setColor(Color.BLACK);    //.black);
        g2d.fillRect(0, 0, IMG_WIDTH, IMG_HEIGHT);
                
        g2d.setColor(new Color(r.nextInt(255),r.nextInt(255),r.nextInt(255)));     //Color.red);
        dragonRecur(300, 500, 1000, 1100,20, g2d);
        g2d.drawImage(img, 0, 0, null);
        g2d.dispose();
        writeImage();
        System.out.println("**DRAGON CREADO**");
    }

    private void writeImage() {
        File file = new File("dragon_1.png");
        try {
            file.createNewFile();
            OutputStream out = new FileOutputStream(file);
            ImageIO.write(img, "png", out);
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void dragonRecur(int x1, int y1, int x2, int y2, int k,
        Graphics2D g2d) {
        if (k > 0) {
            int xn = (x1 + x2) / 2 + (y2 - y1) / 2;
            int yn = (y1 + y2) / 2 - (x2 - x1) / 2;
            dragonRecur(x2, y2, xn, yn, k - 1, g2d);
            dragonRecur(x1, y1, xn, yn, k - 1, g2d);
        } else {
            g2d.drawLine(x1, y1, x2, y2);
        }
    }

    public static void ejecutar() {
        System.out.println("**FRACTAL DEL DRAGON EN JAVA**");
        System.out.println("");
        System.out.println("Ingrese una opción (el número)");
        System.out.println("1. Dragon");
        System.out.println("2. Fractal Comun");
        System.out.println("3. Arbol");
        System.out.println("4. Arbol Pitagoras\n");
        Scanner leer = new Scanner(System.in);
        try {
            int opc = leer.nextInt(); 
            switch(opc) {
                case 1: new DragonCurve().createDragonFractal(); break;
                case 2: new FractalComun().createFractalComun(); break;
                case 3: new Arbol().createArbol(); break;
                case 4: new ArbolPitagoras().createArbolPitagoras(); break;                 
                default: System.out.println("Ingrese una opción valida"); 
            }                                  
        } catch (NumberFormatException e) {
            System.out.println("Ingrese una opción válida");                     
        } 
    }
        
    public static void main(String[] args)  
    {
        ejecutar();                
    }

}
    
