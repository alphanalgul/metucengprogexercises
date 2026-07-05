import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Instructor extends Person
{
    private double salary;
    private ArrayList<String> Given_Courses;

    Instructor()
    {
        name = "Undefined";
        surname = "Undefined";
        id = 0;
        registration_date = new Date();
        date_of_birth = null;
        salary = 0;
        Given_Courses = new ArrayList<String>();
    }

    Instructor(String n, String sn, int ID, Date dob, double s)
    {
        name = n;
        surname = sn;
        id = ID;
        registration_date = new Date();
        date_of_birth = dob;
        salary = s;
        Given_Courses = new ArrayList<String>();
    }

    public void printDetails()
    {
        System.out.printf(" \nInstructor Name: %s", name);
        System.out.printf(" \nInstructor Surname: %s", surname);
        System.out.printf(" \nInstructor ID: %d ", id);
        System.out.printf(" \nInstructor Registration Date: %tF",registration_date);
        System.out.printf(" \nInstructor Date of Birth: %tF",date_of_birth);
        System.out.printf(" \nInstructor Salary: %.2f",salary);
        if(!Given_Courses.isEmpty()) {
            System.out.println(" \nInstructor Courses: ");
            for (int i = 0; i < Given_Courses.size(); i++) {
                System.out.printf(" \n Course %d: %s", i + 1, Given_Courses.get(i));
            }
        }
    }
    public void addCourse()
    {
        Scanner course_input = new Scanner(System.in);
        int num_courses;
        String course_name;

        System.out.println(" \nHow many courses is the instructor teaching this semester:");
        num_courses = course_input.nextInt();
        course_input.nextLine();

        for(int i = 0; i < num_courses ; i++)
        {

            System.out.println(" \nEnter the course name:");
            course_name = course_input.nextLine();

            Given_Courses.add(course_name);
        }
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
    public void setDate_of_birth(Date date_of_birth) {
        super.setDate_of_birth(date_of_birth);
    }

    public void setGiven_Courses(ArrayList<String> given_Courses) {
        Given_Courses = given_Courses;
    }

    public void setSalary(double salary) {
        this.salary = salary;
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
    public Date getDate_of_birth() {
        return super.getDate_of_birth();
    }

    public double getSalary() {
        return salary;
    }

    public ArrayList<String> getGiven_Courses() {
        return Given_Courses;
    }
}
