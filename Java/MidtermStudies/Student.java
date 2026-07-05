import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Student extends Person implements PersonThings {
    private ArrayList<String> taken_courses;
    private Instructor advisor;

    /**
     * Default constructor for the Student Class
     */
    Student()
    {
        name = "undefined";
        surname = "undefined";
        id = 0;
        registration_date = new Date();
        taken_courses = new ArrayList<String>();
    }

    /**
     * Parametrized constructor for the student class
     * @param n student name
     * @param sn student surname
     * @param ID student ID
     * @param birth_date student birthday
     * @throws ParseException exception for simple date formatter
     */
    Student(String n, String sn, int ID,String birth_date) throws ParseException {
        name = n;
        surname = sn;
        id = ID;
        registration_date = new Date();
        taken_courses = new ArrayList<String>();

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        birthdate = sdf.parse(birth_date);
    }

    /**
     * Function for printing out student details
     */
    @Override
    public void printDetails() {
        System.out.printf("\nStudent Name: %s",name);
        System.out.printf("\nStudent Surname: %s",surname);
        System.out.printf("\nStudent ID: %d",id);
        System.out.printf("\nStudent Registration Date: %tF",registration_date);
        System.out.printf("\nStudent Birthdate: %tF", birthdate);
        for(int i = 0; i < taken_courses.size() ; i++){
            System.out.printf("\nCourse %d: %s",i+1,taken_courses.get(i));
        }
        System.out.printf("\nStudent Advisor: %s %s",advisor.getName(),advisor.getSurname());
        System.out.println("\n----------------------------------------------------");
    }

    public void setTaken_courses(ArrayList<String> taken_courses) {
        this.taken_courses = taken_courses;
    }

    public ArrayList<String> getTaken_courses() {
        return taken_courses;
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
    public void setId(int id) {
        super.setId(id);
    }

    @Override
    public void setRegistration_date(Date registration_date) {
        super.setRegistration_date(registration_date);
    }

    @Override
    public void setBirthdate(Date birthdate) {
        super.setBirthdate(birthdate);
    }

    public void setAdvisor(Instructor advisor) {
        this.advisor = advisor;
    }

    @Override
    public String getName() {
        return super.getName();
    }

    @Override
    public String getSurname() {
        return super.getSurname();
    }

    @Override
    public int getId() {
        return super.getId();
    }

    @Override
    public Date getBirthdate() {
        return super.getBirthdate();
    }

    @Override
    public Date getRegistration_date() {
        return super.getRegistration_date();
    }

    public Instructor getAdvisor() {
        return advisor;
    }

    @Override
    public void Eat() {
        System.out.printf("\n%s is eating.",name);
    }

    @Override
    public void Breathe() {
        System.out.printf("\n%s is breathing.",name);
    }

    @Override
    public void Drink() {
        System.out.printf("\n%s is drinking.",name);
    }

    @Override
    public void Walk() {
        System.out.printf("\n%s is walking.",name);
    }
}
