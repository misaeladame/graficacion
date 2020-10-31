package fractales;

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

/**
 *
 * @author José Misael Adame Sandoval
 */
public final class FractalComun {

    private BufferedImage img = null;
    private int IMG_WIDTH;
    private int IMG_HEIGHT;

    private GraphicsEnvironment ge = null;
    private GraphicsDevice gd = null;
    private GraphicsConfiguration gc = null;

    public FractalComun() {
       	IMG_WIDTH = 1100;
	IMG_HEIGHT = 1200;

	ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
	gd = ge.getDefaultScreenDevice();
	gc = gd.getDefaultConfiguration();

    }

    public void createFractalComun() {
        
        Random r = new Random();
        
	Graphics g = null;
	Graphics2D g2d = (Graphics2D) g;

	img = gc.createCompatibleImage(IMG_WIDTH, IMG_HEIGHT);
	g2d = img.createGraphics();
	g2d.setColor(new Color(r.nextInt(255),r.nextInt(255),r.nextInt(255)));    
	g2d.fillRect(0, 0, IMG_WIDTH, IMG_HEIGHT);
               
	g2d.setColor(new Color(r.nextInt(255),r.nextInt(255),r.nextInt(255)));     
	fractalComunRecur(300, 500, 1000, 1100,20, g2d);
	g2d.drawImage(img, 0, 0, null);
	g2d.dispose();
	writeImage();
        System.out.println("**FRACTAL COMUN CREADO**");
    }

    private void writeImage() {
        File file = new File("fractal_comun.png");
        try {
            file.createNewFile();
            OutputStream out = new FileOutputStream(file);
            ImageIO.write(img, "png", out);
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void fractalComunRecur(int x1, int y1, int x2, int y2, int k,
	Graphics2D g2d) {
	if (k > 0) {
            int xn = (x1 + x2) / 2 + (y2 - y1) / 3;
            int yn = (y1 + y2) / 2 - (x2 - x1) / 3;
            fractalComunRecur(x2, y2, xn, yn, k - 1, g2d);
            fractalComunRecur(x1, y1, xn, yn, k - 1, g2d);
	} else {
            g2d.drawLine(x1, y1, x2, y2);
        }
    }
}
