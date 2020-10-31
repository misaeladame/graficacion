package org.yourorghere;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.texture.Texture;
import com.sun.opengl.util.texture.TextureIO;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.GLException;
import javax.media.opengl.glu.GLU;


public class Proy_Unidad3 implements GLEventListener, KeyListener, MouseListener, MouseMotionListener  {
    
    private float view_rotx = 0.01f;
    private float view_roty = 0.01f;
    
    private int oldMousex;
    private int oldMousey;
    
    private Texture[] tex = new Texture[24];
    private int[] texture = new int[24];
    private File[] file = new File[24];

    boolean[] keys = new boolean[256];
    
    private static final float X_POSITION = 0f;
    private static final float Y_POSITION = 0f;
    private static final float Z_POSITION = 0f;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Proyecto Unidad 3");
        GLCanvas canvas = new GLCanvas();

        canvas.addGLEventListener(new Proy_Unidad3());
        frame.add(canvas);
        frame.setSize(800, 600);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {

                    public void run() {
                        animator.stop();
                        System.exit(0);
                    }
                }).start();
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        animator.start();
    }

    public void init(GLAutoDrawable drawable) {
        GL gl = drawable.getGL();
        System.err.println("INIT GL IS: " + gl.getClass().getName());
        
        // Enable VSync
        gl.setSwapInterval(1);
        
        float light_ambient[] = {0.9f, 0.9f, 0.9f, 1.0f};
        float light_diffuse[] = {0.3f, 0.3f, 0.3f, 1.0f};
        float light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
        float light_position[] = {1.0f, 1.5f, 1.0f, 0.0f};
        
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, light_ambient, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, light_diffuse, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, light_specular, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, light_position, 0);
        
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_DEPTH_TEST);
        

        // Setup the drawing area and shading mode
        gl.glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
        gl.glShadeModel(GL.GL_SMOOTH); // try setting this to GL_FLAT and see what happens.
        
        
        drawable.addMouseListener(this);
        drawable.addMouseMotionListener(this);
        drawable.addKeyListener(this);
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        GL gl = drawable.getGL();
        GLU glu = new GLU();

        if (height <= 0) { // avoid a divide by zero error!       
            height = 1;
        }
        final float h = (float) width / (float) height;
        gl.glViewport(0, 0, width, height);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluPerspective(45.0f, h, 1.0, 20.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
    }
    
    //@Override 
    public void display(GLAutoDrawable drawable) {
        GL gl = drawable.getGL();
        GLU glu = new GLU();

        // Clear the drawing area
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        // Reset the current matrix to the "identity"
        gl.glLoadIdentity();
       

        // Move the "drawing cursor" around
        glu.gluLookAt(0.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
        
        gl.glTranslatef(X_POSITION, Y_POSITION, Z_POSITION);
        gl.glRotatef(view_rotx, 1.0f, 0.0f, 0.0f);
        gl.glRotatef(view_roty, 0.0f, 1.0f, 0.0f);
        //gl.glRotatef(90, 0.0f, 0.0f, 1.0f);
        //gl.glRotatef(0.0f, 360.0f, 0.0f, 1.0f);
        
        gl.glScalef(0.25f, 0.25f, 0.25f);
        
        gl.glEnable(GL.GL_TEXTURE_2D);
        try {
            
            for(int i = 0; i < 6; i++){
                
                file[i] = new File("/home/ricardo/Imágenes/face" +  (i+1)  + ".bmp"); // 0 - 5
                file[i+6] = new File("/home/ricardo/Imágenes/body" +  (i+1)  + ".bmp"); // 6 - 11
                file[i+12] = new File("/home/ricardo/Imágenes/arm" +  (i+1)  + ".bmp"); // 12 - 17
                file[i+18] = new File("/home/ricardo/Imágenes/leg" +  (i+1)  + ".bmp");  // 18 - 23
                
                tex[i] = TextureIO.newTexture(file[i], true); // 0 - 5
                tex[i+6] = TextureIO.newTexture(file[i+6], true);  // 6 - 11
                tex[i+12] = TextureIO.newTexture(file[i+12], true); // 12 - 17
                tex[i+18] = TextureIO.newTexture(file[i+18], true); // 18 - 23
                
                texture[i] =  tex[i].getTextureObject(); // 0 - 5
                texture[i+6] =  tex[i+6].getTextureObject(); // 6 - 11
                texture[i+12] =  tex[i+12].getTextureObject(); // 12 - 17
                texture[i+18] =  tex[i+18].getTextureObject(); // 18 - 23
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (GLException ex) {
            ex.printStackTrace();
        }
        
        Minecraft m = new Minecraft();
        m.draw_steve(gl, texture);
        
        // Flush all drawing operations to the graphics card
        gl.glFlush();
    }
    
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() > 250   &&   keys[e.getKeyCode()] == false){
            keys['W']=false;
            keys['J']=false;
            keys[e.getKeyCode()]=true;
        } else{
            keys[e.getKeyCode()]=false;
            System.out.println();
        }
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }
    
    public void mousePressed(MouseEvent e) {
        oldMousex = e.getX();
        oldMousey = e.getY();
    }
    
    public void mouseDragged(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();
        Dimension size = e.getComponent().getSize();
        float thetaX = 360.0f * ((float) (x - oldMousex) / (float) size.width);
        float thetaY = 360.0f * ((float) (oldMousey - y) / (float) size.width);
        oldMousex = x;
        oldMousey = y;
        view_rotx += thetaX;
        view_roty += thetaY;
    }

    public void mouseClicked(MouseEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void mouseReleased(MouseEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void mouseEntered(MouseEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void mouseExited(MouseEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void mouseMoved(MouseEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyTyped(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyReleased(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}

