package campusbookstore;

import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Date;

/**
 * Represents an Employee
 * Each employee has a unique ID
 * a name
 * a surname
 * a Date of Birth
 * and a startDate representing when they started working in the Campus Book Store
 * @author Alphan Algül
 * @version 1.0
 */
public class Employee {
    private int empID;
    private String name;
    private String surname;
    private Date dateOfBirth;
    private Date startDate;

    /**
     * Default constructor for the Employee Object
     * If no parameters are entered, this constructor will be used
     */
    Employee()
    {
        this.empID = 0;
        this.name = "Undefined";
        this.surname = "Undefined";
        this.dateOfBirth = null;
        startDate = null;
    }

    /**
     * Parametrized constructor that creates an Employee Object with fields:
     * id, name, surname
     * @param id the unique id of the employee
     * @param n name of the employee
     * @param sname surname of the employee
     */
    Employee(int id, String n, String sname)
    {
        this.empID = id;
        this.name = n;
        this.surname = sname;
    }

    /**
     * Parametrized constructor that creates an Employee Object with fields:
     * id, name, surname, date of birth, start date
     * @param id unique id of the employee
     * @param n name of the employee
     * @param sname surname of the employee
     * @param dob date of birth of the employee
     * @param startdate start date of the employee
     */
    Employee(int id, String n, String sname, String dob,String startdate){

        this.empID = id;
        this.name = n;
        this.surname = sname;
        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        try {
            this.dateOfBirth = formatter.parse(dob);
            this.startDate = formatter.parse(startdate);
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
        }
    }

    //Setters()
    public void setEmpID(int empID)
    {
        this.empID = empID;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setSurname(String surname)
    {
        this.surname = surname;
    }

    public void setDateOfBirth(String dateOfBirth)
    {
        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        try {
            this.dateOfBirth = formatter.parse(dateOfBirth);
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
        }
    }

    public void setStartDate(String startDate)
    {
        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        try {
            this.startDate = formatter.parse(startDate);
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
        }
    }

    //Getters
    public int getEmpID()
    {
        return empID;
    }

    public String getName()
    {
        return name;
    }

    public String getSurname()
    {
        return surname;
    }

    public Date getDateOfBirth()
    {
        return dateOfBirth;
    }

    public Date getStartDate()
    {
        return startDate;
    }

    /**
     * Method to help display Employee details
     * %tF for printing Date data type
     */
    public void printEmployee()
    {

        System.out.printf("Employee ID: %d%n", empID);
        System.out.printf("Employee Name: %s%n", name);
        System.out.printf("Employee Surname: %s%n ", surname);
        System.out.printf("Employee Date of Birth: %tF%n ", dateOfBirth);
        System.out.printf("Employee Start Date: %tF%n", startDate);
        System.out.println("\n-------------------------");
    }
}
