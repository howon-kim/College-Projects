/*
 * Lab 43
 * Team D
 * @author Howon Kim
 * @author Young Kim
 */

package teamd_lab43;

/**
Design a class named Rectangle to represent a rectangle. The class contains:

Two double data fields named width and height that specify the width and height of the rectangle. 
The default values are 1 for both width and height.
A no-arg constructor that creates a default rectangle.
A constructor that creates a rectangle with the specified width and height.
A method named getArea() that returns the area of this rectangle.
A method named getPerimeter() that returns the perimeter.
**/
public class TeamD_lab43 {

    public static void main(String[] args) {
        
        Rectangle a = new Rectangle(4,40);
        Rectangle b = new Rectangle(3.5,35.9);
        
        System.out.printf("The area of a rectangle with width %.1f and height %.1f is %.1f",a.getWidth(),a.getHeight(),a.getArea());
        System.out.printf("\nThe perimeter of a rectangle is %.1f\n",a.getPerimeter());
        
        System.out.printf("The area of a rectangle with width %.1f and height %.1f is %.4f",b.getWidth(),b.getHeight(),b.getArea());
        System.out.printf("\nThe perimeter of a rectangle is %.1f\n",b.getPerimeter());
    }
    
}

class Rectangle {
    private double width;
    private double height;
    
    public Rectangle()
    {
       this.width = 1;
       this.height = 1;
    }
    
    public Rectangle(double w, double h)
    {
        this.width = w;
        this.height = h;
    }
    
    public double getArea()
    {
        return width*height;
    }
    
    public double getPerimeter()
    {
        return 2*(width+height);
    }
    
    public double getWidth()
    {
        return width;
    }
    
    public double getHeight()
    {
        return height;
    }
    
    public void setWidth(double w)
    {
        this.width = w;
    }
    
    public void setHeight(double h)
    {
        this.height = h;
    }
    
    
    
}
