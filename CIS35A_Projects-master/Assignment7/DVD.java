
import java.text.NumberFormat;
import java.util.ArrayList;

/**
 *
 * @author HWKIM
 */

public class DVD extends inventory{
    protected String rating;
    
    public DVD(){
        rating = "";
    }
    
    public DVD(String rating){
        this.rating = rating;
    }
    
    public DVD(String productName, String rating, String itemNum, int unitStock, double unitPrice){
        super(productName,itemNum,unitStock,unitPrice);
        this.rating = rating;
    }

    public void setRating(String rating){
        this.rating = rating;
    }
    
    public String getRating(){
        return rating;
    }
    
    @Override
    public double calculateInventory(){
        return (unitStock * unitPrice) * 1.05;
    }
        
    @Override
    public String toString(){
    NumberFormat currency = NumberFormat.getCurrencyInstance();

    return "DVD Title:                  " + productName + "\n"
          +"Rating:                       " + rating +"\n"
          +"Item #:                       " + itemNum +"\n"
          +"Number in stock:       " + unitStock +"\n"
          +"Price:                          " + currency.format(unitPrice) +"\n"
          +"Restocking fee<5%>: " + currency.format((unitPrice) *0.05) +"\n"
          +"Inventory Value:         " + currency.format(calculateInventory()) +"\n";
    }
} 
