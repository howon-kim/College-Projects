/*
 * Lab 12
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Huang-Kai Hsu (Kevin)
 * @author Andy Huynh
 */

package lab12;
import java.util.Scanner;


public class TeamD_lab12 {

    public static void main(String[] args) 
    {
        double width;
        double heigth;
        double area;
        double perimeter;
        
        Scanner sc = new Scanner(System.in);
        
        
        System.out.print("Enter the width : ");
        width = sc.nextDouble();
        
        System.out.print("Enter the heigth : ");
        heigth = sc.nextDouble();
        
        area = width * heigth;
        perimeter = 2*(width + heigth);
        
        System.out.printf("Perimeter : %.2f \n", perimeter);
        System.out.printf("Area      : %.2f \n", area); 
    }
    
}
