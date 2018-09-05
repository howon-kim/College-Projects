package payroll;

/**
 *
 * @author HWKIM
 */

public class employee {
    
    private String name;
    private double hourlyRate;
    private double hoursWorked;
    
    public employee()
    {
        name = "";
        hourlyRate = 0.0;
        hoursWorked = 0.0;
    }
    
    public employee(String n, double r, double w)
    {
        name = n;
        hourlyRate = r;
        hoursWorked = w;
    }
    
    public String getName()
    {
        return name;
    }
    
    public void setName(String n)
    {
        name = n;
    }
    
    public double getHourlyRate()
    {
        return hourlyRate;
    }
    
    public void setHourlyRate(double r)
    {
        hourlyRate = r;
    }
    
    public double getHoursWorked()
    {
        return hoursWorked;
    }
    
    public void setHoursWorked(double w)
    {
        hoursWorked = w;
    }
    
    public double calculatePay()
    {
        return hourlyRate * hoursWorked;
    }
}
