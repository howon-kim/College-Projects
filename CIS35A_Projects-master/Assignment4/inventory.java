/**
 *
 * @author HWKIM
 */

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
}
