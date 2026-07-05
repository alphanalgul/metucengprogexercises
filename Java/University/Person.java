import java.util.Date;

public class Person
{
    protected String name;
    protected String surname;
    protected int id;
    protected Date registration_date;
    protected Date date_of_birth;

    Person()
    {
        name = "Undefined";
        surname = "Undefined";
        id = 0;
        registration_date = new Date();
        date_of_birth = null;
    }

    Person(String n, String sn, int ID, Date dob)
    {
        name = n;
        surname = sn;
        id = ID;
        registration_date = new Date();
        date_of_birth = dob;
    }

    public void printDetails()
    {
        System.out.printf(" \nPerson Name: %s", name);
        System.out.printf(" \nPerson Surname: %s", surname);
        System.out.printf(" \nPerson ID: %d ", id);
        System.out.printf(" \nPerson Registration Date: %tF",registration_date);
        System.out.printf(" \nPerson Date of Birth: %tF",date_of_birth);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setRegistration_date(Date registration_date) {
        this.registration_date = registration_date;
    }

    public void setDate_of_birth(Date date_of_birth) {
        this.date_of_birth = date_of_birth;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getId() {
        return id;
    }

    public Date getRegistration_date() {
        return registration_date;
    }

    public Date getDate_of_birth() {
        return date_of_birth;
    }
}
