/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author HWKIM
 */
class Square extends GeometricObject implements Colorable
{
    private double side;

    Square(){
        side = 0;
    }

    Square(double side){
        this.side = side;
    }
    
    Square(String color, boolean filled, double side)
    {
        super(color,filled);
        this.side = side;
    }

    @Override
    public void howToColor()
    {
        System.out.println("Color all four sides");
    }

    @Override
    public double getArea() {
        return side * side;
    }

    public double getSide(){
        return side;
    }

    public void setSide(double side){
        this.side = side;
    }
}