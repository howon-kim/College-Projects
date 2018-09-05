/*
Create a class named Person and its two subclasses named Student and Employee. 
Make Faculty and Staff subclasses of Employee. 
A person has a name, address, phone number, and email address. 
A student has a class status (freshman, sophomore, junior, or senior). 
Define the status as a constant. 
An employee has an office and salary. 
A faculty member has office hours and a rank. 
A staff member has a title. 
Override the toString method method in each class to display the class name and the person's name.

Write a test program that creates a Person, Student, Employee, Faculty, and Staff, and invokes their toString() methods.
 */

package teamd_lab54;
import java.lang.String;

/*
 * Lab 54
 * Team D
 * @author Howon Kim
 */

public class TeamD_lab54 {

    public static void main(String[] args) {
        Person person = new Person("Person Michael", "21250 Stevens Creek", "123-456-7890", "michael@person.com");
        Person student = new Student("Student Ryan", "514 El Camino Real", "408-111-1111", "ryan@student.com","Freshman");
        Person employee = new Employee("Employee Tyler", "410 Fremont Ave", "669-222-3333","tyler@employee.com","ATC204",3000);
        Person faculty = new Faculty("Faculty Andrea", "580 Remington", "408-343-1234", "andrea@faculty.com","0830AM-0930AM",3);
        Person staff = new Staff("Staff Logan", "402 Stevens Creek","408-848-3435","logan@staff.com","Co-Director");
        
        System.out.println(person.toString()+"\n");
        System.out.println(student.toString()+"\n");
        System.out.println(employee.toString()+"\n");
        System.out.println(faculty.toString()+"\n");
        System.out.println(staff.toString());
    }
    
}

class Person{

    protected String name;
    protected String address;
    protected String phone;
    protected String email;
    
    public Person()
    {
        name = "";
        address = "";
        phone = "";
        email = "";
    }
    public Person(String name, String address, String phone, String email)
    {
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.email = email;
    }
    
    public String getName()
    {
        return name;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public String getAddress()
    {
        return address;
    }
    public void setAddress(String address)
    {
        this.address = address;
    }
    public String getPhone()
    {
        return phone;
    }
    public void setPhone(String phone)
    {
        this.phone = phone;
    }
    public String getEmail()
    {
       return email;
    }
    public void setEmail(String email)
    {
        this.email = email; 
    }
    
    @Override
    public String toString()
    {
        return getClass().getName() + "\nName : " + name;
    }

}
class Student extends Person{ 

    private final String STATUS;
    public Student(String STATUS) 
    {
        super();
        this.STATUS = STATUS;
    }
    public Student(String name, String address, String phone, String email, String STATUS)
    {
        this.setName(name);
        this.setAddress(address);
        this.setPhone(phone);
        this.setEmail(email);
        this.STATUS = STATUS;
    }
    public String getStatus()
    {
        return STATUS;
    }
    
    @Override // Not neccessary
    public String toString()
    {
        return getClass().getName() + "\nName : " + name;
    }
}

class Employee extends Person{
    protected String office;
    protected double salary;
    
    public Employee(){
        super();
        office = "";
        salary = 0.0;
    }
    
    public Employee(String name, String address, String phone, String email, String office, double salary)
    {
        this.setName(name);
        this.setAddress(address);
        this.setPhone(phone);
        this.setEmail(email);
        this.office = office;
        this.salary = salary;
    }
    
    public String getOffice()
    {
        return office;
    }
    public void setOffice(String office)
    {
        this.office = office;
    }
    public double getSalary()
    {
        return salary;
    }
    public void setSalary(double salary)
    {
        this.salary = salary;
    }
    
    @Override // Not neccessary
    public String toString()
    {
        return getClass().getName() + "\nName : " + name;
    }
}

class Faculty extends Employee{
    protected String hours;
    protected int rank;
    public Faculty(){
        super();
        hours = "";
        rank = 0;
    }
    public Faculty(String name, String address, String phone, String email, String hours, int rank)
    {
        this.setName(name);
        this.setAddress(address);
        this.setPhone(phone);
        this.setEmail(email);
        this.hours = hours;
        this.rank = rank;
    }
    public String getHours()
    {
        return hours;
    }
    public void setHours(String hours)
    {
        this.hours = hours;
    }
    public int getRank()
    {
        return rank;
    }
    public void setRank(int rank)
    {
        this.rank = rank;
    }
    @Override // Not neccessary
    public String toString()
    {
        return getClass().getName() + "\nName : " + name;
    }
}
class Staff extends Employee{
    protected String title;
    
    public Staff(){
        super();
        title = "";
    }
    public Staff(String name, String address, String phone, String email, String title)
    {
        this.setName(name);
        this.setAddress(address);
        this.setPhone(phone);
        this.setEmail(email);
        this.title = title;
    }
    public String getTitle()
    {
        return title;
    }
    public void setTitle(String title)
    {
        this.title = title;
    }
    @Override // Not neccessary
    public String toString()
    {
        return getClass().getName() + "\nName : " + name;
    }
}