/**
 * Assignment 5
 * @author HWKIM
 */

/*
Modify the Inventory Program so the application can handle multiple items. 
Use an array to store the items. 
The output should display the information one product at a time, including the item number, 
the name of the product, the number of units in stock, the price of each unit, 
and the value of the inventory of that product. 
In addition, the output should display the value of the entire inventory.

Create a method to calculate the value of the entire inventory.

Create another method to sort the array items by the name of the product.

For this part 2, the new 2 methods are created in the inventory class. 
They must have a parameter which is an array of the inventory class. 
In the inventoryTest class, create an array of inventory class. 
Populate the array. Display the non sorted array. 
Sort the array by calling the method created in the inventory class. Display the sorted array.
 */


import java.text.NumberFormat;
import java.util.ArrayList;

public class inventoryTest { 
    static NumberFormat currency = NumberFormat.getCurrencyInstance();
    
    public static void main(String[] args) {

        ArrayList<inventory> list = new ArrayList<>();
        list.add(new inventory("Superman","111",11,12.99));
        list.add(new inventory("Batman Returns","222",9,11.99));
        list.add(new inventory("Madagascar","333",10,10.99));
        list.add(new inventory("Cars","444",15,13.99));

        
        for(int i = 0; i < list.size(); i++)
        {
            System.out.printf("Item #%d\n",i+1);
            System.out.printf("%s\n\n",list.get(i).toString());
        }
        
        inventory.Sort(list);
        
        
        for(int i = 0; i < list.size(); i++)
        {
            System.out.printf("Item #%d\n",i+1);
            System.out.printf("%s\n\n",list.get(i).toString());
        }

        System.out.printf("Total Inventory Value:%.2f\n", inventory.calculateTotalValue(list));


    }
}
