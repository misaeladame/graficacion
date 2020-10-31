package distanciaentredospuntos;

/**
 *
 * @author José Misael Adame Sandoval
 */
public class Punto {
    
    private double x;
    private double y;
    
    public Punto(){
        x=0;
        y=0;
    }
    
    public Punto(double x, double y){
        this.x = x;
        this.y = y;
    }
    
    public Punto(Punto p){
        x = p.x;
        y = p.y;
    }
    
    
    //metodos get/set
    public double getX(){
        return x;
    }
    
    public double getY(){
        return y;
    }
    
    public void setX(double x){
        this.x = x;
    }
    
    public void setY(double y){
        this.y = y;
    }
    
    public String toString(){
        return "("+x+", "+y+")";
    }
    
    
    //metodo de proceso
    public double distancia(Punto p){
        return Math.sqrt(Math.pow(p.x-x, 2)+Math.pow(p.y-y, 2));
    }
}
