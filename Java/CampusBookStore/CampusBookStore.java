package campusbookstore;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Random;
import java.util.Date;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Represents the whole Campus Book System
 * Has a list storing all the students
 * Has a list storing all the employees
 * It provides a variety of functionalities such as:
 * Adding/Deleting Employees/Students, viewing their details, allowing the students to make reservations etc.
 * @author Alphan Algül
 * @version 1.0
 */
public class CampusBookStore {
    public ArrayList<Employee> empList;
    public ArrayList<Student> studentList;


    /**
     * Default constructor for CampusBookStore Object
     * if no parameters are entered, this method will be used
     */
    CampusBookStore()
    {
        this.empList = new ArrayList<Employee>();
        this.studentList = new ArrayList<Student>();;
    }

    /**
     * Parametrized constructor for creating a CampusBookStore object with the field:
     * a list of employees
     * @param e a list of employees
     */
    CampusBookStore(ArrayList<Employee> e)
    {
        this.empList = e;
    }

    /**
     * Parametrized constructor for creating a CampusBookStore object with the fields:
     * a list  of employees, a list of students
     * @param e a list of employees
     * @param s a list of students
     */
    CampusBookStore(ArrayList<Employee> e,ArrayList<Student> s)
    {
        this.empList = e;
        this.studentList = s;
    }


    //Setters()

    public void setEmpList(ArrayList<Employee> empList) {
        this.empList = empList;
    }

    public void setStudentList(ArrayList<Student> studentList) {
        this.studentList = studentList;
    }

    //Getters()
    public ArrayList<Employee> getEmpList() {
        return empList;
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }


    /**
     * Method for adding an Employee to the list of Employees
     */
    public void addEmployee()
    {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter employee id:");
        int id = input.nextInt();
        input.nextLine();

        System.out.println("\nEnter employee name:");
        String name = input.nextLine();

        System.out.println("\nEnter employee surname:");
        String surname = input.nextLine();

        System.out.println("\nEnter employee date of birth:");
        String dob = input.nextLine();

        System.out.println("\nEnter employee start date:");
        String start = input.nextLine();

        Employee e = new Employee(id,name,surname,dob,start);
        //Checking the id of every employee before adding a new one to prevent duplicates
        for(int i=0; i< empList.size();i++)
        {
            if(empList.get(i).getEmpID() == e.getEmpID())
            {
                System.out.println("\nDuplicate ID! Cannot add this employee");
                return;
            }
        }
        empList.add(e);
    }

    /**
     * Method for deleting an Employee based on the given ID
     * @param empId unique Employee ID
     */
    public void deleteEmployee(int empId)
    {
        int check=0;
        for(int i=0 ; i< empList.size();i++)
        {
            if(empList.get(i).getEmpID() == empId)
            {
                empList.remove(i);
                check=1;
                break;
            }
        }
        if(check==0)
        {
            System.out.println("\nEmployee not found!");
        }
    }

    /**
     * Method for listing the details of the EEmployee with the given ID
     * @param empId unique Employee ID
     */
    public void listEmployeeDetails(int empId)
    {
        int check = 0;
        for(int i=0; i<empList.size();i++)
        {
            if(empList.get(i).getEmpID() == empId)
            {
                empList.get(i).printEmployee();
                check=1;
            }
        }
        if(check==0)
        {
            System.out.println("\nEmployee not found!");
        }
    }


    /**
     * Method for adding a Student Object to the list of Students
     */
    public void addStudent()
    {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter student id:");
        int id = input.nextInt();
        input.nextLine();

        System.out.println("\nEnter student name:");
        String name = input.nextLine();

        System.out.println("\nEnter student surname:");
        String surname = input.nextLine();

        Student s = new Student(id,name,surname);

        //Checking the id of every student before adding a new one to prevent duplicates
        for(int i=0; i< studentList.size();i++)
        {
            if(studentList.get(i).getStudentID() == s.getStudentID())
            {
                System.out.println("\nDuplicate ID! Cannot add this employee");
                return;
            }
        }
        studentList.add(s);
    }

    /**
     * Method for deleting a Student based on the given ID
     * @param id Unique Student ID
     */
    public void deleteStudent(int id)
    {
        int check = 0;
        for(int i = 0; i<studentList.size();i++)
        {
            if(studentList.get(i).getStudentID() == id)
            {
                studentList.remove(i);
                check = 1;
                 break;
            }
        }
        if(check==0)
        {
            System.out.println("\nStudent not found!");
        }
    }

    /**
     * Method for listing the details of aa Student based on the given ID
     * @param id Unique Student ID
     */
    public void getStudentDetails(int id)
    {
        int check = 0;
        for(int i=0; i < studentList.size(); i++)
        {
            if(studentList.get(i).getStudentID() == id)
            {
                studentList.get(i).printStudent();
                check = 1;
            }
        }
        if(check==0)
        {
            System.out.println("\nStudent not found!");
        }
    }

    /**
     * Method for returning a random Employee to be assigned to a Book Item Object
     * @return a random Employee
     */
    Employee randomEmployee()
    {
        Random rand = new Random();
        int random_num = rand.nextInt(empList.size());
        return empList.get(random_num);
    }

    /**
     * Method for creating a Reservation for the Student with the given id
     * Calling the makeReservation() method of the Student class to create a new Reservation Object
     * adds it into the list of Reservations of the Student with the given id and finally assigns a random
     * employee for every Book Item in the newly created Reservation
     * @param id Unique Student ID
     */
    public void makeReservation(int id)
    {
        int check = 0;
        for(int i=0; i< studentList.size(); i++) {
            if (studentList.get(i).getStudentID() == id) {

                    studentList.get(i).makeReservation();

                    ArrayList<TextbookReservation> reservations = studentList.get(i).getReservations();
                    TextbookReservation reservation = reservations.getLast();

                    for (BookItem b : reservation.getBookList()) {
                        b.setAssigned(randomEmployee());
                    }
                    check = 1;
                }
            }
        if(check == 0)
        {
            System.out.println("\nThis Student does not exist!");
        }
    }

    /**
     * Method for listing the details of Reservation(s) made by the Student with a given id
     * on a given date
     * @param id Unique Student ID
     * @param reservationDate Date of the Reservation
     */
    public void getReservationDetails(int id, Date reservationDate)
    {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        int count = 0;
        boolean check = false;

        for (int i = 0; i < studentList.size(); i++)
        {

            if (studentList.get(i).getStudentID() == id)
            {
                check = true;
                ArrayList<TextbookReservation> reservations = studentList.get(i).getReservations();

                for (int j = 0; j < reservations.size(); j++)
                {
                    TextbookReservation r = reservations.get(j);

                    if (sdf.format(r.getReservationDate()).equals(sdf.format(reservationDate)))
                    {
                        count++;
                        r.printReservation();
                    }
                }
            }
        }

        if (!check) {
            System.out.println("\nStudent not found!");
        }
        else if (count == 0) {
            System.out.println("\nNo reservations found for this student on this date!");
        }
        else {
            System.out.println("\nTotal reservations found on " + sdf.format(reservationDate)
                    + ": " + count);
        }
    }

    /**
     * Method for displaying the total cost of a Reservations ( sum of costs of all the Book Items within the
     * Reservation) and list all the details of the Reservations that a Student with a given ID has
     * @param id Unique Student ID
     * @param reservationDate Date of the reservation
     */
    void getStudentReservationTotalCost(int id, Date reservationDate) {

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        double total_reservation_cost = 0;
        for (int i = 0; i < studentList.size(); i++) {

            if (studentList.get(i).getStudentID() == id) {

                ArrayList<TextbookReservation> reservations = studentList.get(i).getReservations();

                for (int j = 0; j < reservations.size(); j++) {

                    TextbookReservation r = reservations.get(j);

                    if (sdf.format(r.getReservationDate()).equals(sdf.format(reservationDate))) {

                        double reservation_cost;

                        reservation_cost = reservations.get(j).totalReservationCost();
                        total_reservation_cost = total_reservation_cost + reservation_cost;

                        r.printReservation();


                        System.out.printf("\nReservation cost: %.2f",reservation_cost);
                        System.out.println("\n-----------------------------------------");
                    }
                }
            }
        }
    }

    /**
     * Method for listing all the employees and their details
     */
    public void  listEmployees()
    {
        for(int i = 0; i< empList.size(); i++){
            empList.get(i).printEmployee();
        }
    }

    /**
     * Method for listing all the students and their details
     */
    public void  listStudents()
    {
        for(int i = 0; i< studentList.size(); i++){
            studentList.get(i).printStudent();
        }
    }

    /**
     * Method to exit the program
     */
    public void exit(){
        System.exit(0);
    }

    /**
     * Menu method that allows the user to interact with the system
     * For example 1. for adding an employee 11. for listing details of all the students etc.
     */
    public void menu()
    {
        int choice=0;
        Scanner input = new Scanner(System.in);
        while(choice!=12)
        {
            System.out.println("\nWelcome to the Campus Book Store");
            System.out.println("\n---------------------------------");
            System.out.println("\n1. Add an Employee");
            System.out.println("\n2. Delete an Employee");
            System.out.println("\n3. List the Details of an Employee");
            System.out.println("\n4. Add a student");
            System.out.println("\n5. Delete a student");
            System.out.println("\n6. Get the Details of a Student");
            System.out.println("\n7. Make a Reservation");
            System.out.println("\n8. Get the Details of a Reservation");
            System.out.println("\n9. Get the Total Cost of Reservations");
            System.out.println("\n10. List Details of All Employees");
            System.out.println("\n11. List Details of All Students");
            System.out.println("\n12. Exit");
            System.out.println("\nEnter a choice:");
            choice = input.nextInt();

            if(choice == 1) {

                addEmployee();
            }

            else if(choice == 2) {

                System.out.println("\nEnter the id of the employee you want to delete:");
                int id = input.nextInt();
                input.nextLine();
                deleteEmployee(id);
            }

            else if(choice == 3) {

                System.out.println("\nEnter the id of the employee you want to view the detail of:");
                int id = input.nextInt();
                input.nextLine();
                listEmployeeDetails(id);
            }

            else if(choice == 4) {

                addStudent();
            }

            else if(choice == 5) {

                System.out.println("\nEnter the id of the student you want to delete:");
                int id = input.nextInt();
                input.nextLine();
                deleteStudent(id);
            }

            else if(choice == 6) {

                System.out.println("\nEnter the id of the student you want to view the detail of:");
                int id = input.nextInt();
                input.nextLine();
                getStudentDetails(id);
            }

            else if(choice == 7) {

                System.out.println("\nEnter a Student id in order to make a reservation:");
                int id = input.nextInt();
                input.nextLine();

                makeReservation(id);
            }

            else if(choice == 8) {
                System.out.println("\nEnter a Student id in order to make a reservation:");
                int id = input.nextInt();
                input.nextLine();

                System.out.println("\nEnter a date to see the reservations made on that " +
                        "date(dd/MM/yyyy):");
                String dateInput = input.nextLine();

                //Parsing the input String and turning it into date so that it could be stored
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                Date date_param;
                try {
                    date_param = formatter.parse(dateInput);
                } catch (ParseException error) {
                    System.out.println("Invalid date format!");
                    return;
                }
                getReservationDetails(id, date_param);
            }

            else if(choice == 9) {
                System.out.println("\nEnter a Student id in order to see the costs of reservations:");
                int id = input.nextInt();
                input.nextLine();

                System.out.println("\nEnter a date to see the costs of reservations made on that " +
                        "date(dd/MM/yyyy):");
                String dateInput = input.nextLine();

                //Parsing the input String and turning it into date so that it could be stored
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                Date date_param;
                try {
                    date_param = formatter.parse(dateInput);
                } catch (ParseException error) {
                    System.out.println("Invalid date format!");
                    return;
                }
                getStudentReservationTotalCost(id,date_param);
            }

            else if(choice == 10) {

                System.out.println("\nDetails of All the Employees:\n");
                listEmployees();
                System.out.println("\n");
            }

            else if(choice == 11) {

                System.out.println("\nDetails of All the Students:\n");
                listStudents();
                System.out.println("\n");
            }

            else if(choice == 12) {
                System.out.println("\nGoodbyee!");
                exit();
            }

            else{
                System.out.println("\nPlease enter a valid option!");
            }
        }
    }

    /**
     * Main method
     * Controls the whole program
     * @param args command line arguments if any are present
     */
    public static void main(String[] args)
    {
        CampusBookStore bookStore = new CampusBookStore();
        PopulateData p = new PopulateData(bookStore);
        bookStore.menu();
    }
}