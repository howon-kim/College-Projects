/*
 * Lab 33
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */

package teamd_lab33;
import java.math.RoundingMode;
import java.math.BigDecimal;

public class TeamD_lab33 {
    public static void main(String[] args) {
        double pounds = 0.0;
        double kilograms = 0.0;
        int pound = 20;
        int kilogram = 1;
        
        System.out.print("Kilograms ");
        System.out.print("Pounds    ");
        System.out.print("Pounds    ");
        System.out.print("Kilograms ");
        System.out.println();

        for(int i = 1; i <= 10; i++)
        {
            pounds = kilogram * 2.2;
            BigDecimal decimalPounds = new BigDecimal(pounds);
            decimalPounds = decimalPounds.setScale(3, RoundingMode.HALF_DOWN);
            System.out.printf("%-10d%-10s",kilogram,decimalPounds);            

            kilograms = pound * 0.454544;
            BigDecimal decimalKilograms = new BigDecimal(kilograms);
            decimalKilograms = decimalKilograms.setScale(3, RoundingMode.HALF_DOWN);
            System.out.printf("%-10d%-10s", pound, decimalKilograms);
            System.out.println();

            pound += 5; 
            kilogram += 2;
        }    
    }  
}
