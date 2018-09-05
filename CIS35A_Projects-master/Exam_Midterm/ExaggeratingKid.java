/**
 * Midterm
 * @author Howon Kim
 * May 12
 */

public class ExaggeratingKid extends SchoolKid {
    public ExaggeratingKid(){
        super();
    }
    public ExaggeratingKid(String name, int age, String teacher, String greeting){
        super(name, age, teacher, greeting);
    }
    
    @Override
    public int getAge(){
        return super.getAge() + 2;
    }
    
    @Override
    public String getGreeting(){
        return super.getGreeting().concat(" I am the smartest.");
    }
    
    @Override
    public String toString(){
        return super.toString() + "\nBut " + name + " should exaggerate his age by 2: " + getAge() + "\nand should add to the greeting: " + getGreeting();
    }
}
