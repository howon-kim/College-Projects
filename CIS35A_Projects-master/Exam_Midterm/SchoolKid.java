/**
 * Midterm
 * @author Howon Kim
 * May 12
 */

public class SchoolKid {
    protected String name;
    protected int age;
    protected String teacher;
    protected String greeting;
    
    // Default Constructor
    public SchoolKid(){
        name = "";
        age = 0;
        teacher = "";
        greeting = "";
    }
    
    public SchoolKid(String name, int age, String teacher, String greeting){
        this.name = name;
        this.age = age;
        this.teacher = teacher;
        this.greeting = greeting;
    }
    
    
    // Set and Get Methods
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public int getAge(){
        return age;
    }
    public void setAge(int age){
        this.age = age;
    }
    public String getTeacher(){
        return teacher;
    }
    public void setTeacher(String teacher){
        this.teacher = teacher;
    }
    public String getGreeting(){
        return greeting;
    }
    public void setGreeting(String greeting){
        this.greeting = greeting;
    }
    
    
    // Methods
    public void haveBirthday(){
        ++this.age;
    }
    public void changeTeacher(String teacher){
        this.teacher = teacher;
    }
    public void changeGreeting(String greeting){
        this.greeting = greeting;
    }
    
    
    // toString
    @Override
    public String toString(){
        return "Base class data of school kid\n" + "\tName: " + this.name + "\n\tAge: " + this.age + "\n\tTeacher: " + this.teacher + "\n\tGreeting: " + this.greeting;
    }
}
