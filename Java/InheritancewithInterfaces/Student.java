import java.util.Date;

public class Student extends Person implements PersonThings,StudentThings
{
    private String University;
    private double CGPA;

    Student()
    {
        name = "Undefined";
        surname = "Undefined";
        age = 0;
        dob = new Date();
        University = "Undefined";
        CGPA = 0;
    }
    Student(String n, String sn, int a, Date db, String uni, double cgpa)
    {
        name = n;
        surname = sn;
        age = a;
        dob = db;
        University = uni;
        CGPA =cgpa;
    }

    @Override
    public void setName(String name) {
        super.setName(name);
    }

    @Override
    public void setSurname(String surname) {
        super.setSurname(surname);
    }

    @Override
    public void setAge(int age) {
        super.setAge(age);
    }

    @Override
    public void setDob(Date dob) {
        super.setDob(dob);
    }

    public void setCGPA(double CGPA) {
        this.CGPA = CGPA;
    }

    public void setUniversity(String university) {
        University = university;
    }

    @Override
    public String getName() {
        return super.getName();
    }

    @Override
    public String getSurname() {
        return super.getSurname();
    }

    public double getCGPA() {
        return CGPA;
    }

    @Override
    public Date getDob() {
        return super.getDob();
    }

    @Override
    public int getAge() {
        return super.getAge();
    }

    public String getUniversity() {
        return University;
    }

    public void printDetails()
    {
        System.out.printf("\nStudent Name: %s",getName());
        System.out.printf("\nStudent Surname: %s",getSurname());
        System.out.printf("\nStudent Age: %d",getAge());
        System.out.printf("\nStudent Date of Birth: %tF",getDob());
        System.out.printf("\nStudent University: %s",getUniversity());
        System.out.printf("\nStudent CGPA: %.2f",getCGPA());
    }

    @Override
    public void breathe() {
        System.out.printf("\n%s is breathing",getName());
    }

    @Override
    public void eat() {
        System.out.printf("\n%s is eating",getName());
    }

    @Override
    public void drink() {
        System.out.printf("\n%s is drinking",getName());
    }

    @Override
    public void walk() {
        System.out.printf("\n%s is walking",getName());
    }

    @Override
    public void study() {
        System.out.printf("\n%s is studying",getName());
    }

    @Override
    public void fail() {
        System.out.printf("\n%s is failing from a course",getName());
    }

    @Override
    public void pass() {
        System.out.printf("\n%s is passing a course",getName());
    }
}
