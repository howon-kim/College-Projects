/**
 * Assignment 7
 * @author HWKIM
 */

/*
Modify the Inventory Program to use a GUI. 
The GUI should display the information one product at a time, including the item number, the name of the product, the number of units in stock, the price of each unit, and the value of the inventory of that product. 
In addition, the GUI should display the value of the entire inventory, the additional attribute, and the restocking fee.

You don't touch the Inventory class and the subclass that you created for part 3. You only modify the InventoryTest to add the GUI.
 */

import javax.swing.*;

public class inventoryTest extends JFrame{ 

    public JPanel content = new JPanel();   
    public JTextArea inventory = new JTextArea(31,33);
    public JScrollPane scroll = new JScrollPane(inventory,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    
    public static DVD[] list = new DVD[4];
    
    static{
    list[0] = new DVD("Superman","PG","111",11,12.99);
    list[1] = new DVD("Batman Returns","PG 13","222",9,11.99);
    list[2] = new DVD("Madagascar","G","333",10,10.99);
    list[3] = new DVD("Cars","G","444",15,13.99);  
    }
    
    inventoryTest(){
        super("Inventory of DVD Movies");
        setSize(430,550);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);         

        
        content.setSize(430,550);
        inventory.setLineWrap(true);
        inventory.setWrapStyleWord(true);


        inventory.append("Non sorted DVD inventory\n\n");
        
        for(int i = 0; i < list.length; i++)
        {
            inventory.append("Item #" + (i+1) + "\n");
            inventory.append(list[i].toString() +"\n\n");
        }
        
        inventory.append("\nSorted DVD inventory\n\n");
        DVD.Sort(list);
        
        for(int i = 0; i < list.length; i++)
        {
            inventory.append("Item #" + (i+1) + "\n");
            inventory.append(list[i].toString() +"\n\n");
        }

        inventory.append(String.format("Total Inventory Value: $%.2f\n", DVD.calculateTotalValue(list)));
        
        content.add(scroll);
        add(content);
        setVisible(true);

    }
    
    public static void main(String[] args) {
        inventoryTest window = new inventoryTest();
    }
    
}
