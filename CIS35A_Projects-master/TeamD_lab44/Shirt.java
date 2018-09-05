
/**
Create a class named Shirt with data fields for collar size and sleeve length. 
include a constructor that takes parameters for each field. 
Also include a final, static String named MATERIAL (when declaring a constant in Java) 
and initialize it to "cotton." Write an application named TestShirt to instantioate three Shirt objects with different 
colar szes and sleeve lengths, and then display all the data, including material, for each shirt. 
Save both the Shirt.java and TestShirt.java files.
**/

public class Shirt {
    private int size;
    private int length;
    public static final String MATERIAL = "cotton";
    
    public Shirt()
    {
        size = 0;
        length  = 0;
    }
    
    public Shirt(int s, int l)
    {
        size = s;
        length = l;
    }
    
    public void setSize(int s)
    {
        this.size = s;
    }
    
    public void setLength(int l)
    {
        this.length= l;
    }
    
    public int getSize()
    {
        return size;
    }
    
    public int getLegnth()
    {
        return length;
    }
    
}
