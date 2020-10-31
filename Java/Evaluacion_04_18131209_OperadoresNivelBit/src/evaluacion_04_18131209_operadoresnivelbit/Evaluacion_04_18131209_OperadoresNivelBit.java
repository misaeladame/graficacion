/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evaluacion_04_18131209_operadoresnivelbit;

/**
 *
 * @author terry
 */
public class Evaluacion_04_18131209_OperadoresNivelBit {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int n1 = 3265;
        int n2 = 16386;
              
        int n1_and = n1 & 425;
        int n1_or = n1 | 425;
        int n1_xor = n1 ^ 425;
        int n1_not = ~n1;
        
        int n2_and = n2 & 425;
        int n2_or = n2 | 425;
        int n2_xor = n2 ^ 425;
        int n2_not = ~n2;
        
        
        System.out.println("n1 = 3265");
        System.out.println("Operador AND " +n1_and);
        System.out.println("Operador OR " +n1_or);
        System.out.println("Operador XOR " +n1_xor);
        System.out.println("Operador NOT " +n1_not);
        System.out.println("");
        System.out.println("n2 = 16386");
        System.out.println("Operador AND " +n2_and);
        System.out.println("Operador OR " +n2_or);
        System.out.println("Operador XOR " +n2_xor);
        System.out.println("Operador NOT " +n2_not);
        
        int n3 = 17454;
        int n4 = 8432593;
        int n5 = 65280;
        
        int n3_and_n5 = n3 & n5;
        int n4_and_n5 = n4 & n5;
        
        System.out.println("\n\nOperador AND ");
        System.out.println(n3_and_n5);
        System.out.println(n4_and_n5);
        
        
        
    }
    
}
