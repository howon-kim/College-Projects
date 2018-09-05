/**
 * Assignment 8
 * @author HWKIM
 */

/*
Modify the Inventory Program by adding a button to the GUI that allows the user to move to the 
first item, the previous item, the next item, and the last item in the inventory. 
If the first item is displayed and the user clicks on the Previous button, the last item should display. 
If the last item is displayed and the user clicks on the Next button, the first item should display.

Add a company logo to the GUI using Java graphics classes.
*/

import java.awt.*;
import java.awt.event.*;
import java.text.NumberFormat;
import javax.swing.*;

public class inventoryTest
{ 
        public static void main(String[] args) 
        {
            inventoryFrame window = new inventoryFrame();
            window.setVisible(true);
        }
}

class inventoryFrame extends JFrame
{
    public inventoryFrame()
    {
        super("Inventory of DVD Movies");
        setSize(700,400);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        JPanel panel = new inventoryPanel();
        this.add(panel);
        this.pack();
    }
}

class inventoryPanel extends JPanel implements ActionListener
{
    
    public final int TEXT_SIZE = 35;
    
    public NumberFormat currency = NumberFormat.getCurrencyInstance();
    public int count = 0;

    public JLabel itemID = new JLabel("Item ID");
    public JLabel name = new JLabel("Name");
    public JLabel rating = new JLabel("Rating");
    public JLabel stock = new JLabel("# in Stock");
    public JLabel price = new JLabel("Price");
    public JLabel restockingFee = new JLabel("Restocking Fee(5%)");
    public JLabel inventoryValue = new JLabel("Inventory Value with fee");
    public JLabel totalValue = new JLabel("Total Value with fee (for all the items)");
    
    public JTextField itemIDText = new JTextField(TEXT_SIZE);
    public JTextField nameText = new JTextField(TEXT_SIZE);
    public JTextField ratingText = new JTextField(TEXT_SIZE);
    public JTextField stockText = new JTextField(TEXT_SIZE);
    public JTextField priceText = new JTextField(TEXT_SIZE);
    public JTextField restockingFeeText = new JTextField(TEXT_SIZE);
    public JTextField inventoryValueText = new JTextField(TEXT_SIZE);
    public JTextField totalValueText = new JTextField(TEXT_SIZE);
      
    public JPanel button = new JPanel();
    public JButton first = new JButton("First");
    public JButton previous = new JButton("Previous");
    public JButton next = new JButton("Next");
    public JButton last = new JButton("Last");
    public JButton logo = new JButton();
    
    
    public static DVD[] list = new DVD[4];
    static{
    list[0] = new DVD("Superman","PG","111",11,12.99);
    list[1] = new DVD("Batman Returns","PG 13","222",9,11.99);
    list[2] = new DVD("Madagascar","G","333",10,10.99);
    list[3] = new DVD("Cars","G","444",15,13.99);  
    }
    
    inventoryPanel(){
        
        itemID.setFont(new Font("default", Font.BOLD,12));
        name.setFont(new Font("default", Font.BOLD,12));
        rating.setFont(new Font("default", Font.BOLD,12));
        stock.setFont(new Font("default", Font.BOLD,12));
        price.setFont(new Font("default", Font.BOLD,12));
        restockingFee.setFont(new Font("default", Font.BOLD,12));
        inventoryValue.setFont(new Font("default", Font.BOLD,12));
        totalValue.setFont(new Font("default", Font.BOLD,12));
        
        itemIDText.setEditable(false);
        nameText.setEditable(false);
        ratingText.setEditable(false);
        stockText.setEditable(false);
        priceText.setEditable(false);
        restockingFeeText.setEditable(false);
        inventoryValueText.setEditable(false);
        totalValueText.setEditable(false);
        
        
        setLayout(new GridBagLayout());
        add(itemID, getConstraints(0,1,1,1, GridBagConstraints.WEST));
        add(itemIDText, getConstraints(1,1,2,1, GridBagConstraints.EAST));
        add(name, getConstraints(0,2,1,1, GridBagConstraints.WEST));
        add(nameText, getConstraints(1,2,2,1, GridBagConstraints.EAST)); 
        add(rating, getConstraints(0,3,1,1, GridBagConstraints.WEST));
        add(ratingText, getConstraints(1,3,2,1, GridBagConstraints.EAST));        
        add(stock, getConstraints(0,4,1,1, GridBagConstraints.WEST));
        add(stockText, getConstraints(1,4,2,1, GridBagConstraints.EAST));
        add(price, getConstraints(0,5,1,1, GridBagConstraints.WEST));
        add(priceText, getConstraints(1,5,2,1, GridBagConstraints.EAST));
        add(restockingFee, getConstraints(0,6,1,1, GridBagConstraints.WEST));
        add(restockingFeeText, getConstraints(1,6,2,1, GridBagConstraints.EAST));
        add(inventoryValue, getConstraints(0,7,1,1, GridBagConstraints.WEST));
        add(inventoryValueText, getConstraints(1,7,2,1, GridBagConstraints.EAST));
        add(totalValue, getConstraints(0,8,1,1, GridBagConstraints.WEST));
        add(totalValueText, getConstraints(1,8,2,1, GridBagConstraints.EAST));

    
        ImageIcon logoImg = new ImageIcon("/Users/HWKIM/Desktop/CIS35A/inventory/DVD.png");
        logo = new JButton(logoImg);
        
        button.setLayout(new FlowLayout());
        button.add(first);
        button.add(previous);
        button.add(next);
        button.add(last);
        add(logo,getConstraints(0,9,2,1, GridBagConstraints.CENTER));
        add(button,getConstraints(1,9,2,1, GridBagConstraints.WEST));
        
        first.addActionListener(this);
        previous.addActionListener(this);
        next.addActionListener(this);
        last.addActionListener(this);
    }


private GridBagConstraints getConstraints(int gridx, int gridy, int gridwidth, int gridheight, int anchor)
    {
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(-4, 0, -4, 0);
        c.ipadx = 10;
        c.ipady = 10;
        c.gridx = gridx;
        c.gridy = gridy;
        c.gridwidth = gridwidth;
        c.gridheight = gridheight;
        c.anchor = anchor;
        return c;
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        Object source = event.getSource();
		
        if(source == first)
        {
            count = 0;
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list))); 
        }
        else if(source == previous)
        {
            if(count == 0){
            count = list.length - 1;
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list))); 
            }
            else{
            count--; 
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list)));  
            }
        }
        else if(source == next)
        {
            if(count == list.length -1)
            {
            count = 0;
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list)));   
            }
            else{
            count++; 
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list)));  
            }
        }
        else if(source == last)
        {
            count = list.length -1; 
            itemIDText.setText(list[count].getItemNum());
            nameText.setText(list[count].getProductName());
            ratingText.setText(list[count].getRating());
            stockText.setText(String.valueOf(list[count].getUnitStock()));
            priceText.setText(currency.format(list[count].getUnitPrice()));
            restockingFeeText.setText(currency.format(list[count].getRestockingFee()));
            inventoryValueText.setText(currency.format(list[count].calculateInventory()));
            totalValueText.setText(currency.format(DVD.calculateTotalValue(list)));   
        }
    }
}
