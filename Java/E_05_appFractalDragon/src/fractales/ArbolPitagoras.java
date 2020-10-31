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
import java.awt.geom.Path2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import javax.imageio.ImageIO;

public class ArbolPitagoras {
    
    private BufferedImage img = null;
    private int IMG_WIDTH;
    private int IMG_HEIGHT;
    
    private GraphicsEnvironment ge = null;
    private GraphicsDevice gd = null;
    private GraphicsConfiguration gc = null;
    
    final int depthLimit = 7;
    float hue = 0.15f;
 
    public ArbolPitagoras() {
        IMG_WIDTH = 630;
        IMG_HEIGHT = 600;

	ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
	gd = ge.getDefaultScreenDevice();
	gc = gd.getDefaultConfiguration();
        
    }
    
    public void createArbolPitagoras() {
	Graphics g = null;
	Graphics2D g2d = (Graphics2D) g;

	img = gc.createCompatibleImage(IMG_WIDTH, IMG_HEIGHT);
	g2d = img.createGraphics();
	g2d.setColor(new Color(240, 240, 240));    
	g2d.fillRect(0, 0, IMG_WIDTH, IMG_HEIGHT);
                 
	dibujarArbolPitagoras((Graphics2D) g2d, 275, 500, 375, 500, 0);
	g2d.drawImage(img, 0, 0, null);
	g2d.dispose();
	writeImage();
        System.out.println("**ARBOL DE PITAGORAS CREADO**");
    }
 
    private void writeImage() {
	File file = new File("arbol_pitagoras.png");
        try {
            file.createNewFile();
            OutputStream out = new FileOutputStream(file);
            ImageIO.write(img, "png", out);
            out.close();
	} catch (IOException e) {
            e.printStackTrace();
	}
    }
    
    private void dibujarArbolPitagoras(Graphics2D g2d, float x1, float y1, float x2, float y2,
            int depth) {
 
        if (depth == depthLimit)
            return;
 
        float dx = x2 - x1;
        float dy = y1 - y2;
 
        float x3 = x2 - dy;
        float y3 = y2 - dx;
        float x4 = x1 - dy;
        float y4 = y1 - dx;
        float x5 = x4 + 0.5F * (dx - dy);
        float y5 = y4 - 0.5F * (dx + dy);
 
        Path2D square = new Path2D.Float();
        square.moveTo(x1, y1);
        square.lineTo(x2, y2);
        square.lineTo(x3, y3);
        square.lineTo(x4, y4);
        square.closePath();
 
        g2d.setColor(Color.getHSBColor(hue + depth * 0.02f, 1, 1));
        g2d.fill(square);
        g2d.setColor(Color.lightGray);
        g2d.draw(square);
 
        Path2D triangle = new Path2D.Float();
        triangle.moveTo(x3, y3);
        triangle.lineTo(x4, y4);
        triangle.lineTo(x5, y5);
        triangle.closePath();
 
        g2d.setColor(Color.getHSBColor(hue + depth * 0.035f, 1, 1));
        g2d.fill(triangle);
        g2d.setColor(Color.lightGray);
        g2d.draw(triangle);
 
        dibujarArbolPitagoras(g2d, x4, y4, x5, y5, depth + 1);
        dibujarArbolPitagoras(g2d, x5, y5, x3, y3, depth + 1);
    }
}
