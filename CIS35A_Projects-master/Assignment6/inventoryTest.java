/**
 * Assignment 6
 * @author HWKIM
 */

/*
Modify the Inventory Program by creating a subclass of the product class that uses one additional unique feature of the product you chose 
(for the DVDs subclass, you could use movie title, for example). 
In the subclass, create a method to calculate the value of the inventory of a product 
with the same name as the method previously created for the product class. 
The subclass method should also add a 5% restocking fee to the value of the inventory of that product.

Modify the output to display this additional feature you have chosen and the restocking fee.

For this part 3, the inventory class remains the same (i.e. use the inventory class in part 2). 
So do not modify the inventory class. 
Create a new class for a specific product which is a subclass of the inventory class,
e.g. a DVD class that has a new feature (e.g. rating). 
This is to show inheritance and polymorphism. 
In the inventoryTest class, the array is now the array of the subclass (e.g. DVD subclass). 
Display non sorted and sorted arrays.

Part 3 has 3 classes: inventory, DVD (can be any name), inventoryTest. 
The DVD class is a subclass of the inventory class. 
The inventoryTest class uses only the DVD class. 
It doesn't use the inventory class. 
Because the DVD class is the subclass of the inventory class, 
when the inventoryTest class uses the DVD class, indirectly it also uses the inventory class. 
But in the inventoryTest class, you don't make any instance of the inventory class. You make only an instance of the DVD class.


For part 2, you must have the method calculateInventory.

For part 3, you must have the same name method calculateInventory in DVD class. 
This method includes the restocking fee. 
Also for part 3, you must have a new feature in DVD such as rating or length of the DVD. 
This is in addition to what you already got for inventory (name, stock, price, item number).


For part 3, the inventoryTest uses the DVD class, 
creates an array of the DVD class (instead of the inventory class) and displays the information.
 */


public class inventoryTest { 
    
    public static void main(String[] args) {

        DVD[] list = new DVD[4];
        list[0] = new DVD("Superman","PG","111",11,12.99);
        list[1] = new DVD("Batman Returns","PG 13","222",9,11.99);
        list[2] = new DVD("Madagascar","G","333",10,10.99);
        list[3] = new DVD("Cars","G","444",15,13.99);

        
        System.out.println("Inventory of DVD Movies:\n");
        for(int i = 0; i < list.length; i++)
        {
            System.out.printf("Item #%d\n",i+1);
            System.out.printf("%s\n\n",list[i].toString());
        }
        
        
        System.out.println("\nSorted Inventory of DVD Movies:\n");
        DVD.Sort(list);
        
        for(int i = 0; i < list.length; i++)
        {
            System.out.printf("Item #%d\n",i+1);
            System.out.printf("%s\n\n",list[i].toString());
        }

        
        System.out.printf("Total Inventory Value:%.4f\n", DVD.calculateTotalValue(list));
    }
}
