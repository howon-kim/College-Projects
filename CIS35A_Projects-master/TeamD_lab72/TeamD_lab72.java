/*
Design an interface named Colorable with a void method named howToColor().
Every class of a colorable object must implement the Colorable interface.
Design a class named Square that extends GeometricObject and implemnts Colorable.
Implement howToColor to display the message Color all four sides.

Write a test program that creates an array of five GeometricObjects.
For each object in the array, display the area and invoke its howToColor method if it is colorable.
*/


/**
 * Team D
 * Lab 7.2
 * @author HWKIM
 */

public class TeamD_lab72 {


    public static void main(String[] args) {
      
        GeometricObject[] shape = new GeometricObject[5];
        shape[0] = new Square(1);
        shape[1] = new Square(2);
        shape[2] = new GeometricObject();
        shape[3] = new Square(4);
        shape[4] = new GeometricObject();
        
        
        for(int i = 0 ; i < shape.length; i++)
        {
            System.out.printf("\n%d object's properties\n",i);
            System.out.printf("Area : %f\n",shape[i].getArea());
            if(shape[i] instanceof Colorable) {
                Colorable colorable = (Colorable) shape[i];
                colorable.howToColor();
            }
        }
        

                                        
    }
}
