package sistemas_numericos;

public class SistemasNumericos {
    
    public static String conversionBinario (int num) {
        String binario = "";
        int modulo;
        while(num > 0) {
            modulo = num % 2;
            binario = modulo + "" +binario;
            num = num / 2;                
        }
        return binario;       
    }

    public static String conversionOctal (int num) {
        String octal = "";
        int modulo;
        while(num > 0) {
            modulo = num % 8;
            octal = modulo + "" +octal;
            num = num / 8;                    
        }
        return octal;
    }
    
    public static String conversionHexadecimal (int num) {
        String hexadecimal = "";
        int modulo;
        while(num > 0) {
            modulo = num % 16;
            if(modulo <= 9)
                hexadecimal = modulo + "" +hexadecimal;
            if(modulo == 10)
                hexadecimal = "A" + "" +hexadecimal;
            if(modulo == 11)
                hexadecimal = "B" + "" +hexadecimal;
            if(modulo == 12)
                hexadecimal = "C" + "" +hexadecimal;
            if(modulo == 13)
                hexadecimal = "D" + "" +hexadecimal;
            if(modulo == 14)
                hexadecimal = "E" + "" +hexadecimal;
            if(modulo == 15)
                hexadecimal = "F" + "" +hexadecimal;
            num = num / 16;
        }
        return hexadecimal;
    }
}

