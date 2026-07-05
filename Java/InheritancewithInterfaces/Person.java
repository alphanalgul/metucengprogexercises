import java.util.Date;

public class Person implements PersonThings
{
    protected String name;
    protected String surname;
    protected int age;
    protected Date dob;

    Person(){
        name = "Undefined";
        surname = "Undefined";
        age = 0;
        dob = new Date();
    }

    Person(String n, String sn, int a, Date db)
    {
        name = n;
        surname = sn;
        age = a;
        dob = db;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setDob(Date dob) {
        this.dob = dob;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }

    public Date getDob() {
        return dob;
    }

    @Override
    public void breathe() {
        System.out.println("\nPerson is breathing");
    }

    @Override
    public void walk() {
        System.out.println("\nPerson is walking");
    }

    @Override
    public void eat() {
        System.out.println("\nPerson is eating");
    }

    @Override
    public void drink() {
        System.out.println("\nPerson is drinking");
    }
}
