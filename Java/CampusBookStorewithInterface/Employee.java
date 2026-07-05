package campusbookstore;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


/**
 * Represents an Employee (subclass of User, inherits id, name, dateOfBirth). Includes the fields:
 * and a startDate representing when they started working in the Campus Book Store
 * @author Alphan Algül
 * @version 1.0
 */
public class Employee extends User {
    Date startDate;

    /**
     * Default constructor for the Employee Object
     * If no parameters are entered, this constructor will be used
     */
    Employee(){
        setId(0);
        setName("Undefined");
        setDateOfBirth(new Date());
        startDate = new Date();
    }

    /**
     * Parametrized constructor that creates an Employee Object with fields:
     * id, name, surname
     * @param id the unique id of the employee
     * @param name name of the employee
     * @param dob employees date of birth
     */
    Employee(int id, String name, String dob){

        setId(id);
        setName(name);
        startDate = new Date();

        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        formatter.setLenient(false);
        try {
            setDateOfBirth(formatter.parse(dob));
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
            setDateOfBirth(new Date());
        }
    }

    /**
     * Parametrized constructor that creates an Employee Object with fields:
     * id, name, surname, date of birth, start date
     * @param id unique id of the employee
     * @param name name of the employee
     * @param dob date of birth of the employee
     * @param start_date start date of the employee
     */
    Employee(int id, String name, String dob,String start_date){

        setId(id);
        setName(name);
        setDateOfBirth(new Date());
        startDate = new Date();

        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        formatter.setLenient(false);
        try {
            setDateOfBirth(formatter.parse(dob));
            startDate = formatter.parse(start_date);
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
        }
    }

    //Setters
    @Override
    public void setId(int id) {
        super.setId(id);
    }

    @Override
    public void setName(String name) {
        super.setName(name);
    }

    @Override
    public void setDateOfBirth(Date dateOfBirth) {
        super.setDateOfBirth(dateOfBirth);
    }

    public void setStartDate(Date startDate) {
        this.startDate = startDate;
    }

    //Getters
    @Override
    public int getId() {
        return super.getId();
    }

    @Override
    public String getName() {
        return super.getName();
    }

    @Override
    public Date getDateOfBirth() {
        return super.getDateOfBirth();
    }


    public Date getStartDate() {
        return startDate;
    }

    /**
     * Method to help display Employee details
     * %tF for printing Date data type
     */
    public void printEmployee()
    {

        System.out.printf("Employee ID: %d%n", getId());
        System.out.printf("Employee Name: %s%n", getName());
        System.out.printf("Employee Date of Birth: %tF%n ", getDateOfBirth());
        System.out.printf("Employee Start Date: %tF%n", startDate);
        System.out.println("\n-------------------------");
    }
}
