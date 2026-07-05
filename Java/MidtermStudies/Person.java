import java.util.Date;

public abstract class Person {
    protected String name;
    protected String surname;
    protected int id;
    protected Date registration_date;
    protected Date birthdate;

    Person()
    {
        name = "unassigned";
        surname = "unassigned";
        id = 0;
        registration_date = new Date();
        birthdate = new Date();
    }
    Person(String n, String sn, int ID)
    {
        name = n;
        surname = sn;
        id = ID;
    }

    public abstract void printDetails();

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

    public Date getBirthdate() {
        return birthdate;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setRegistration_date(Date registration_date) {
        this.registration_date = registration_date;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setBirthdate(Date birthdate) {
        this.birthdate = birthdate;
    }
}
