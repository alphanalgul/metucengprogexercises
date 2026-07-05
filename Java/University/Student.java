import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Student extends Person
{
        private double cgpa;
        private ArrayList<String> Taken_Courses;

        Student()
        {
            cgpa = 0;
            Taken_Courses = new ArrayList<String>();
            name = "Undefined";
            surname = "Undefined";
            id = 0;
            registration_date = new Date();
            date_of_birth = null;
        }

        Student(String n, String sn, int ID, Date dob, double c)
        {
            name = n;
            surname = sn;
            id = ID;
            registration_date = new Date();
            date_of_birth = dob;
            cgpa = c;
            Taken_Courses = new ArrayList<String>();
        }

        public void printDetails()
        {
            System.out.printf(" \nStudent Name: %s", name);
            System.out.printf(" \nStudent Surname: %s", surname);
            System.out.printf(" \nStudent ID: %d ", id);
            System.out.printf(" \nStudent Registration Date: %tF",registration_date);
            System.out.printf(" \nStudent Date of Birth: %tF",date_of_birth);
            System.out.printf(" \nStudent CGPA: %.2f", cgpa);
            if(!Taken_Courses.isEmpty()) {
                System.out.println(" \nStudent Courses: ");
                for (int i = 0; i < Taken_Courses.size(); i++) {
                    System.out.printf("  \nCourse %d: %s", i + 1, Taken_Courses.get(i));
                }
            }
        }

        public void addCourse()
        {
            Scanner course_input = new Scanner(System.in);
            int num_courses;
            String course_name;

            System.out.println(" \nHow many courses is the student taking this semester:");
            num_courses = course_input.nextInt();
            course_input.nextLine();

            for(int i = 0; i < num_courses ; i++)
            {

                System.out.println(" \nEnter the course name:");
                course_name = course_input.nextLine();

                Taken_Courses.add(course_name);
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

    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }

    public void setTaken_Courses(ArrayList<String> taken_Courses) {
        Taken_Courses = taken_Courses;
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

    public ArrayList<String> getTaken_Courses() {
        return Taken_Courses;
    }

    public double getCgpa() {
        return cgpa;
    }
}
