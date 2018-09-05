/**
 *
 * @author HWKIM
 */

//import java.util.ArrayList;
import java.text.NumberFormat;


public class inventory {

    protected String productName;
    protected String itemNum;
    protected int unitStock;
    protected double unitPrice;
    
    public inventory()
    {
        productName = "";
        itemNum = "";
        unitStock = 0;
        unitPrice = 0.0;
    }
    
    public inventory(String productName, String itemNum, int unitStock, double unitPrice)
    {
        this.productName = productName;
        this.itemNum = itemNum;
        this.unitStock = unitStock;
        this.unitPrice = unitPrice;
    }
    
    public void setItemNum(String itemNum)
    {
        this.itemNum = itemNum;
    }
    
    public String getItemNum()
    {
        return this.itemNum;
    }
    
    public void setProductName(String productName)
    {
        this.productName = productName;
    }
    
    public String getProductName()
    {
        return this.productName;
    }
    
    public void setUnitStock(int unitStock)
    {
        this.unitStock = unitStock;
    }
    
    public int getUnitStock()
    {
        return unitStock;
    }
    
    public void setUnitPrice(double unitPrice)
    {
        this.unitPrice = unitPrice;
    }
    
    public double getUnitPrice()
    {
        return unitPrice;
    }
    

    public double calculateInventory(){
        return unitStock * unitPrice;
    }
    
    public static double calculateTotalValue(inventory[] list){
       
        double sum = 0;
        
        for (inventory list1 : list) {
            sum += list1.calculateInventory();
        }
        
        return sum;
    }

    public static void Sort(inventory[] sort) {
       
        int min;
   
        for (int i = 0; i < sort.length; ++i) {
            min = i;
            for (int j = i + 1; j < sort.length; ++j) {
                if (sort[j].getProductName().compareTo(sort[min].getProductName())<0) {
                    min = j;
                }
            }

            inventory temp = sort[i];
            sort[i] = sort[min];
            sort[min] = temp;
        }
    }
    
    @Override
    public String toString(){
        NumberFormat currency = NumberFormat.getCurrencyInstance();

        return "DVD Title:       " + productName +"\n"
              +"Item #:          " + itemNum +"\n"
              +"Number in stock: " + unitStock +"\n"
              +"Price:           " + currency.format(unitPrice) +"\n"
              +"Inventory Value: " + currency.format(calculateInventory()) +"\n";
    }

}
