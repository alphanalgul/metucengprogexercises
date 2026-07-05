package campusbookstore;


import java.util.Date;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Represents a Student
 * Each student has a unique ID
 * a name
 * a surname
 * a reservationDate representing the date that the student has made a reservation on
 * and a list of reservation representing all the reservations that the student has made
 * @author Alphan Algül
 * @version 1.0
 */
public class Student
{
    private int studentID;
    private String name;
    private String surname;
    private Date reservationDate;
    private ArrayList<TextbookReservation> reservations;

    /**
     * Default constructor for creating a Student Object
     * if no parameters are entered, this constructor will be used
     */
    Student()
    {
        this.studentID = 0;
        this.name = "Undefined";
        this.surname = "Undefined";
        reservationDate = null;
        reservations = new ArrayList<TextbookReservation>();
    }

    /**
     * Parametrized constructor for creating a Student Object with the following fields:
     * id, name, surname
     * @param id unique id of the student
     * @param n name of the student
     * @param sname surname of the student
     */
    Student (int id, String n, String sname) {
        this.studentID = id;
        this.name = n;
        this.surname = sname;
        this.reservations = new ArrayList<TextbookReservation>();
    }

    /**
     * Parametrized constructor for creating a Student Object with the following fields:
     * id, name, surname, a list of reservations
     * @param id unique id of the student
     * @param n name of the student
     * @param sname surname of the student
     * @param r list of reservations
     */
    Student(int id,String n,String sname, ArrayList<TextbookReservation> r)
    {
        this.studentID = id;
        this.name = n;
        this.surname = sname;
        this.reservations = r;
    }

    /**
     * Parametrized constructor for creating a Student Object with the following fields:
     * id, name, surname, a list of reservations, reservation date
     * @param id unique id of the student
     * @param n name of the student
     * @param sname surname of the student
     * @param r list of reservations
     * @param rD date of the reservation
     */
    Student(int id,String n,String sname, ArrayList<TextbookReservation> r,Date rD)
    {
        this.studentID = id;
        this.name = n;
        this.surname = sname;
        this.reservations = r;
        this.reservationDate = rD;
    }

    //Setters()
    public void setStudentID(int studentID) {
        this.studentID = studentID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setReservationDate(Date reservationDate) {
        this.reservationDate = reservationDate;
    }

    public void setReservations(ArrayList<TextbookReservation> reservations) {
        this.reservations = reservations;
    }

    //Getters()
    public int getStudentID() {
        return studentID;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public Date getReservationDate() {
        return reservationDate;
    }

    public ArrayList<TextbookReservation> getReservations() {
        return reservations;
    }

    /**
     * A method that allows the students to make a Reservation
     * <p>
     * 1.The method will take the payment status and number of books to be reserved from the user
     * creates an empty Book Item array and sets the date to the current date (which is the date when
     * the reservation was made)
     * </p>
     * <p>
     * 2.Then the method will take the relevant fields needed for creating a Book Item(type,quantity,price)
     * from the user, creates a Book Item Object with the entered fields and stores it into the Book Items
     * array
     * </p>
     * <p>
     * 3. Finally, the method will create a new Reservation Object using the Book Items list created in 2.
     * the payment status taken from the user and the reservation date which is the current date
     * </p>
     */
    void makeReservation()
    {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter the paid status(true/false):");
        boolean paymentStatus = input.nextBoolean();
        input.nextLine();

        ArrayList<BookItem> book_list = new ArrayList<BookItem>();
        reservationDate = new Date();

        System.out.println("\nEnter the number of books you want to reserve:");
        int num_books = input.nextInt();
        input.nextLine();

        for(int i=0; i< num_books ; i++)
        {
            System.out.println("\nEnter the book type: (Novel, Physics, Calculus etc.):");
            String book_type = input.nextLine();

            System.out.println("\nEnter quantity:");
            int quantity = input.nextInt();
            input.nextLine();

            System.out.println("\nEnter price:");
            int price = input.nextInt();
            input.nextLine();

            BookItem b = new BookItem(book_type,quantity,price);
            book_list.add(b);
        }
        TextbookReservation r = new TextbookReservation(book_list,paymentStatus,reservationDate);
        reservations.add(r);


    }

    /**
     * Method to help display Student details
     * %tF for printing Date data type
     */
    public void printStudent()
    {

        System.out.printf("Student ID: %d%n", studentID);
        System.out.printf("Student Name: %s%n", name);
        System.out.printf("Student Surname: %s%n", surname);
        System.out.printf("Student Reservation Date: %tF%n", reservationDate);
        System.out.println("\n---------------------------");
        System.out.printf("List of Reservations:%n");
        if(reservations!=null) {
            for (int i = 0; i < reservations.size(); i++) {
                reservations.get(i).printReservation();
            }
        }
    }
}
