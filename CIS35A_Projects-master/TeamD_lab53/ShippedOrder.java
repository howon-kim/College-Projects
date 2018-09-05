/*
 * Lab 53
 * Team D
 * @author Howon Kim
 */

public class ShippedOrder extends Order{
    @Override
    public void computeTotalPrice()
    {
        super.computeTotalPrice();
        totalPrice += 400;
    }
}
