/**
 *
 * @author HWKIM
 */

import java.util.ArrayList;
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
    
    public double calculateValue()
    {
        return unitStock * unitPrice;
    }
    
    public static double calculateTotalValue(ArrayList<inventory> list){
       
        double sum = 0;
        
        for(int i = 0; i < list.size(); i++){
            sum += (list.get(i).getUnitPrice() * list.get(i).getUnitStock());
        }
        
        return sum;
    }

    public static void Sort(ArrayList<inventory> sort) {
       
        int min;
   
        for (int i = 0; i < sort.size(); ++i) {
            min = i;
            for (int j = i + 1; j < sort.size(); ++j) {
                if (sort.get(j).getProductName().compareTo(sort.get(min).getProductName())<0) {
                    min = j;
                }
            }

            inventory temp = sort.get(i);
            sort.set(i, sort.get(min));
            sort.set(min, temp);  
        }
    }
    
    @Override
    public String toString(){
        NumberFormat currency = NumberFormat.getCurrencyInstance();

        return "DVD Title:       " + productName +"\n"
              +"Item #:          " + itemNum +"\n"
              +"Number in stock: " + unitStock +"\n"
              +"Price:           " + currency.format(unitPrice) +"\n"
              +"Inventory Value: " + currency.format(calculateValue()) +"\n";
    }
}
