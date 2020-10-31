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
import javax.imageio.ImageIO;

public class Arbol {
    
    private BufferedImage img = null;
    private int IMG_WIDTH;
    private int IMG_HEIGHT;

    private GraphicsEnvironment ge = null;
    private GraphicsDevice gd = null;
    private GraphicsConfiguration gc = null;

    public Arbol() {
        IMG_WIDTH = 800;
        IMG_HEIGHT = 600;

	ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
	gd = ge.getDefaultScreenDevice();
	gc = gd.getDefaultConfiguration();    
    }
    
    public void createArbol() {
        Random r = new Random();
	Graphics g = null;
	Graphics2D g2d = (Graphics2D) g;

	img = gc.createCompatibleImage(IMG_WIDTH, IMG_HEIGHT);
	g2d = img.createGraphics();
	g2d.setColor(new Color(243, 243, 243));   
	g2d.fillRect(0, 0, IMG_WIDTH, IMG_HEIGHT);
                
	g2d.setColor(new Color(r.nextInt(255),r.nextInt(255),r.nextInt(255)));     
	arbolRecur(g2d, 400, 500, -90, 9);
	g2d.drawImage(img, 0, 0, null);
	g2d.dispose();
	writeImage();
        System.out.println("**ARBOL CREADO**");
    }
 
    private void writeImage() {
	File file = new File("arbol.png");
        try {
            file.createNewFile();
            OutputStream out = new FileOutputStream(file);
            ImageIO.write(img, "png", out);
            out.close();
	} catch (IOException e) {
            e.printStackTrace();
	}
    }
    
    private void arbolRecur(Graphics g, int x1, int y1, double angle, int depth) {
        if (depth == 0) return;
        int x2 = x1 + (int) (Math.cos(Math.toRadians(angle)) * depth * 10.0);
        int y2 = y1 + (int) (Math.sin(Math.toRadians(angle)) * depth * 10.0);
        g.drawLine(x1, y1, x2, y2);
        arbolRecur(g, x2, y2, angle - 20, depth - 1);
        arbolRecur(g, x2, y2, angle + 20, depth - 1);
    }
}