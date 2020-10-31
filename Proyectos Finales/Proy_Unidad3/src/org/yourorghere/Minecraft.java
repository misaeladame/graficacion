package org.yourorghere;

import javax.media.opengl.GL;

public class Minecraft {
    
  
    public void draw_arm_left(GL gl, int[] texture){
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[13]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 10.0f, 0.0f, 0.0f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 10.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f ); 
	    gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[12]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 10.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 10.0f, -10.0f, 0.0f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f );
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[15]);
            gl.glBegin(GL.GL_QUADS);    
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 10.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 10.0f, -10.0f, 5.0f );
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );  //Parte de atras
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[17]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f );  
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[16]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 10.0f, 0.0f, 0.0f );  
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 10.0f, 0.0f, 5.0f );
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 10.0f, -10.0f, 5.0f );    //Parte de la izquierda 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 10.0f, -10.0f, 0.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();
                
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[14]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 10.0f, -10.0f, 0.0f);  
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 10.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );    //Parte de abajo
            gl.glEnd(); 
        gl.glPopMatrix();
    }
    
    public void draw_arm_right(GL gl, int[] texture){
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[13]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -10.0f, 0.0f, 0.0f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -10.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f ); 
	    gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[12]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -10.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -10.0f, -10.0f, 0.0f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f );
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[15]);
            gl.glBegin(GL.GL_QUADS);    
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -10.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -10.0f, -10.0f, 5.0f );
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );  //Parte de atras
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[17]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f );  
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[16]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -10.0f, 0.0f, 0.0f );  
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -10.0f, 0.0f, 5.0f );
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -10.0f, -10.0f, 5.0f );    //Parte de la izquierda 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -10.0f, -10.0f, 0.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();
                
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[14]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -10.0f, -10.0f, 0.0f);  
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -10.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );    //Parte de abajo
            gl.glEnd(); 
        gl.glPopMatrix();
    }
    
    public void draw_leg_left(GL gl, int[] texture){
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[20]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();		
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[18]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -20.0f, 0.0f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f );
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[21]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -20.0f, 5.0f );
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de atras
            gl.glEnd(); 
        gl.glPopMatrix();

        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[22]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f );  
            gl.glEnd(); 
        gl.glPopMatrix();
       
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[23]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f );  
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -20.0f, 5.0f );    //Parte de la izquierda 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -20.0f, 0.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[19]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f);
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -20.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -20.0f, 5.0f );  
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de abajo
            gl.glEnd();
        gl.glPopMatrix();
    }
    
    public void draw_leg_right(GL gl, int[] texture){
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[20]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();		
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[18]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -20.0f, 0.0f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f );
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[21]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -20.0f, 5.0f );
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de atras
            gl.glEnd(); 
        gl.glPopMatrix();

        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[22]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 0.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f );  
            gl.glEnd(); 
        gl.glPopMatrix();
       
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[23]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f );  
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -20.0f, 5.0f );    //Parte de la izquierda 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -20.0f, 0.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[19]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 0.0f, -20.0f, 0.0f);
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, -20.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -20.0f, 5.0f );  
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 0.0f, -20.0f, 5.0f );  //Parte de abajo
            gl.glEnd();
        gl.glPopMatrix();
    }
    
    public void draw_body(GL gl, int[] texture){
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[7]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f );
            gl.glEnd();
        gl.glPopMatrix();    
                
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[6]);
            gl.glBegin(GL.GL_QUADS);      
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f );
            gl.glEnd();
        gl.glPopMatrix();  
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[11]);
            gl.glBegin(GL.GL_QUADS);   
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );  //Parte de atras
            gl.glEnd();
        gl.glPopMatrix();

        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[10]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 0.0f ); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( -5.0f, 0.0f, 5.0f ); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f );  
            gl.glEnd();
        gl.glPopMatrix();  
       
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[9]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 0.0f );  
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 0.0f, 5.0f );
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f );    //Parte de la izquierda 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f ); 
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[8]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, -10.0f, 0.0f); 
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, -10.0f, 5.0f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, -10.0f, 5.0f );    //Parte de abajo
            gl.glEnd(); 
        gl.glPopMatrix();
    }
    
    public void draw_head(GL gl, int[] texture){
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[1]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0); gl.glVertex3f( -5.0f, 10.0f, -2.5f); 
                gl.glTexCoord2d(1.0, 0.0); gl.glVertex3f( 5.0f, 10.0f, -2.5f);  //Parte Arriba
                gl.glTexCoord2d(1.0, 1.0); gl.glVertex3f( 5.0f, 10.0f, 7.5f ); 
                gl.glTexCoord2d(0.0, 1.0); gl.glVertex3f( -5.0f, 10.0f, 7.5f );
            gl.glEnd(); 
        gl.glPopMatrix();
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[0]);
            gl.glBegin(GL.GL_QUADS);
                gl.glTexCoord2d(0.0, 0.0);  gl.glVertex3f( -5.0f, 10.0f, -2.5f ); 
                gl.glTexCoord2d(1.0, 0.0);  gl.glVertex3f( 5.0f, 10.0f, -2.5f ); 
                gl.glTexCoord2d(1.0, 1.0);  gl.glVertex3f( 5.0f, 0.0f, -2.5f );   //Parte de enfrente
                gl.glTexCoord2d(0.0, 1.0);  gl.glVertex3f( -5.0f, 0.0f, -2.5f );
            gl.glEnd(); 
        gl.glPopMatrix();
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[2]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0);  gl.glVertex3f( -5.0f, 10.0f, 7.5f ); 
                gl.glTexCoord2d(1.0, 0.0);  gl.glVertex3f( 5.0f, 10.0f, 7.5f ); 
                gl.glTexCoord2d(1.0, 1.0);  gl.glVertex3f( 5.0f, 0.0f, 7.5f );
                gl.glTexCoord2d(0.0, 1.0);  gl.glVertex3f( -5.0f, 0.0f, 7.5f );  //Parte de atras
            gl.glEnd(); 
        gl.glPopMatrix();

        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[3]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0);  gl.glVertex3f( -5.0f, 10.0f, -2.5f ); 
                gl.glTexCoord2d(1.0, 0.0);  gl.glVertex3f( -5.0f, 10.0f, 7.5f ); 
                gl.glTexCoord2d(1.0, 1.0);  gl.glVertex3f( -5.0f, 0.0f, 7.5f );  //Parte de la derecha
                gl.glTexCoord2d(0.0, 1.0);  gl.glVertex3f( -5.0f, 0.0f, -2.5f );  
            gl.glEnd(); 
        gl.glPopMatrix();
      
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[4]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0);  gl.glVertex3f( 5.0f, 10.0f, -2.5f ); 
                gl.glTexCoord2d(1.0, 0.0);  gl.glVertex3f( 5.0f, 10.0f, 7.5f ); 
                gl.glTexCoord2d(1.0, 1.0);  gl.glVertex3f( 5.0f, 0.0f, 7.5f );  //Parte de la Izquierda
                gl.glTexCoord2d(0.0, 1.0);  gl.glVertex3f( 5.0f, 0.0f, -2.5f );
            gl.glEnd(); 
        gl.glPopMatrix();
        
        gl.glPushMatrix();
            gl.glBindTexture(GL.GL_TEXTURE_2D, texture[5]);
            gl.glBegin(GL.GL_QUADS); 
                gl.glTexCoord2d(0.0, 0.0);  gl.glVertex3f( -5.0f, 0.0f, -2.5f); 
                gl.glTexCoord2d(1.0, 0.0);  gl.glVertex3f( 5.0f, 0.0f, -2.5f);  
                gl.glTexCoord2d(1.0, 1.0);  gl.glVertex3f( 5.0f, 0.0f, 7.5f ); 
                gl.glTexCoord2d(0.0, 1.0);  gl.glVertex3f( -5.0f, 0.0f, 7.5f );   //Parte de abajo
            gl.glEnd(); 
        gl.glPopMatrix();
    }
    
    public void draw_steve(GL gl, int[] texture){
        draw_arm_left(gl, texture);
        draw_arm_right(gl, texture);
        draw_leg_left(gl, texture);
        draw_leg_right(gl, texture);
        draw_head(gl, texture);
        draw_body(gl, texture);  
    }
}
