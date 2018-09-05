/*
 * Lab 44
 * Team D
 * @author Howon Kim
 * @author Young Kim
 */

/**
Create a class named Shirt with data fields for collar size and sleeve length. 
include a constructor that takes parameters for each field. 
Also include a final, static String named MATERIAL (when declaring a constant in Java) 
and initialize it to "cotton." Write an application named TestShirt to instantioate three Shirt objects with different 
colalr szes and sleeve lengths, and then display all the data, including material, for each shirt. 
Save both the Shirt.java and TestShirt.java files.
**/

public class TestShirt {
    
    public static void main(String args[])
    {
        Shirt a = new Shirt(100,30);
        Shirt b = new Shirt(105,25);
        Shirt c = new Shirt(90,35);
        
        System.out.printf("Shirt a's size : %d\nShirt a's length : %d\nShirt a's Material : %s\n\n",a.getSize(),a.getLegnth(),Shirt.MATERIAL);
        System.out.printf("Shirt b's size : %d\nShirt b's length : %d\nShirt b's Material : %s\n\n",b.getSize(),b.getLegnth(),Shirt.MATERIAL);
        System.out.printf("Shirt c's size : %d\nShirt c's length : %d\nShirt c's Material : %s\n\n",c.getSize(),c.getLegnth(),Shirt.MATERIAL);

    
    }
    
}
