import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Instructor extends Person implements PersonThings{
    private ArrayList<String> taught_courses;
    private double salary;

    /**
     * Default constructor for the instructor class
     */
    Instructor()
    {
        name = "undefined";
        surname = "undefined";
        id = 0;
        registration_date = new Date();
        salary = 0;
        taught_courses = new ArrayList<String>();
    }

    /**
     * Parametrized  constructor for the instructor class
     * @param n instructor name
     * @param sn instructor surname
     * @param ID instructor id
     * @param s instructor salary
     * @param birth_date instructor birthdate
     * @throws ParseException exception for simple date formatter sdf
     */
    Instructor(String n, String sn, int ID, double s,String birth_date) throws ParseException {
        name = n;
        surname = sn;
        id = ID;
        salary = s;
        registration_date = new Date();
        taught_courses = new ArrayList<String>();

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        birthdate = sdf.parse(birth_date);
    }

    /**
     * Method for printing out instructor details
     */
    @Override
    public void printDetails() {
        System.out.printf("\nInstructor Name: %s",name);
        System.out.printf("\nInstructor Surname: %s",surname);
        System.out.printf("\nInstructor ID: %d",id);
        System.out.printf("\nInstructor Registration Date: %tF",registration_date);
        System.out.printf("\nInstructor Birthdate: %tF", birthdate);
        System.out.printf("\nInstructor Salary: %.2f",salary);
        for(int i = 0; i < taught_courses.size() ; i++){
            System.out.printf("\nCourse %d: %s",i+1,taught_courses.get(i));
        }
        System.out.println("\n------------------------------------------------------");
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setTaught_courses(ArrayList<String> taught_courses) {
        this.taught_courses = taught_courses;
    }

    public double getSalary() {
        return salary;
    }

    public ArrayList<String> getTaught_courses() {
        return taught_courses;
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
    public Date getRegistration_date() {
        return super.getRegistration_date();
    }

    @Override
    public Date getBirthdate() {
        return super.getBirthdate();
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
