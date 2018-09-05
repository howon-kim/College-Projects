/**
 * Assignment 4
 * @author HWKIM
 */

/**
Choose a product that lends itself to an inventory (for example, products at your workplace, office supplies, music CDs, DVD movies, or software).

Create a product class that holds the item number, the name of the product, the number of units in stock, and the price of each unit.

Create a Java application that displays the product number, 
the name of the product, the number of units in stock, the price of each unit, 
and the value of the inventory (the number of units in stock multiplied by the price of each unit). 
Pay attention to the good programming practices in the text to ensure your source code is readable and well documented.

For this inventory part 1, you need to create 2 classes: inventory and inventoryTest 
(you can give any names you want. It�s similar to the employee class and payroll class).

The inventory class contains the item number, the name of the product, the number of units in stock, and the price of each unit. 
They are properties of the Inventory class. 
Create the set and get methods similar to the methods in the Employee class. 
You also create a method to calculate the value of the inventory.

The inventoryTest instantiates the inventory class to do the display.

For the inventoryTest class, you instantiate the inventory class by passing 4 parameters. 
The difference between this program and the Payroll part 3 is that you don't have to ask the user to input the data. 
You can use the constructor the pass the values of the parameters. 
This way it's easier on you (In this case you don't use the set methods because you don't ask for the user to input the data.). 
So once you do that, you got the values for the 4 items of the Inventory. 
You can then print the inventory information and the value of the inventory by calling the get methods.
**/

import java.text.NumberFormat;
public class inventoryTest { 
    static NumberFormat currency = NumberFormat.getCurrencyInstance();
    public static void main(String[] args) {

    inventory DVD1 = new inventory("Superman","001",11,12.99);
    inventory DVD2 = new inventory("Avengers","002",20,22.67);
    inventory DVD3 = new inventory("Batman","003",50,24.45);
    inventory DVD4 = new inventory("Ironman","004",10,30.15);
    
    System.out.printf("\nInventory of DVD Movies: \n\n");
    System.out.printf("DVD Title :       %s\n",DVD1.getProductName());
    System.out.printf("Item # :          %s\n",DVD1.getItemNum());
    System.out.printf("Number in Stock : %d\n",DVD1.getUnitStock());
    System.out.printf("Price :           %s\n",currency.format(DVD1.getUnitPrice()));
    System.out.printf("Inventory Value : %s\n\n",currency.format(DVD1.calculateValue()));
    
    System.out.printf("DVD Title :       %s\n",DVD2.getProductName());
    System.out.printf("Item # :          %s\n",DVD2.getItemNum());
    System.out.printf("Number in Stock : %d\n",DVD2.getUnitStock());
    System.out.printf("Price :           %s\n",currency.format(DVD2.getUnitPrice()));
    System.out.printf("Inventory Value : %s\n\n",currency.format(DVD2.calculateValue()));

    System.out.printf("DVD Title :       %s\n",DVD3.getProductName());
    System.out.printf("Item # :          %s\n",DVD3.getItemNum());
    System.out.printf("Number in Stock : %d\n",DVD3.getUnitStock());
    System.out.printf("Price :           %s\n",currency.format(DVD3.getUnitPrice()));
    System.out.printf("Inventory Value : %s\n\n",currency.format(DVD3.calculateValue()));

    System.out.printf("DVD Title :       %s\n",DVD4.getProductName());
    System.out.printf("Item # :          %s\n",DVD4.getItemNum());
    System.out.printf("Number in Stock : %d\n",DVD4.getUnitStock());
    System.out.printf("Price :           %s\n",currency.format(DVD4.getUnitPrice()));
    System.out.printf("Inventory Value : %s\n\n",currency.format(DVD4.calculateValue()));   
           
    }
}
