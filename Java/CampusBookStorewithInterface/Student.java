package campusbookstore;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 * Represents a Student (subclass of User, inherits id, name, dateOfBirth). Includes the fields:
 * a reservationDate representing the date that the student has made a reservation on
 * a list of reservation representing all the reservations that the student has made
 * and a hashmap identity check containing the date the check is performed in and their status
 * @author Alphan Algül
 * @version 1.0
 */
public class Student extends User implements Comparable<Student>, StudentLoyalty{
    Date reservationDate;
    ArrayList<TextbookReservation> reservations;
    HashMap<Date,String> identityCheck;

    /**
     * Default constructor for creating a Student Object
     * if no parameters are entered, this constructor will be used
     */
    Student(){
        setId(0);
        setName("Undefined");
        setDateOfBirth(new Date());
        reservationDate = new Date();
        reservations = new ArrayList<TextbookReservation>();
        identityCheck =  new HashMap<Date,String>();
    }

    /**
     * Parametrized constructor for creating a Student Object with the following fields:
     * id, name, surname
     * @param id unique id of the student
     * @param name name of the student
     */
    Student(int id, String name){
        setId(id);
        setName(name);
        setDateOfBirth(new Date());
        reservationDate = new Date();
        reservations = new ArrayList<TextbookReservation>();
        identityCheck =  new HashMap<Date,String>();
    }


    /**
     * Parametrized constructor for creating a Student Object with the following fields:
     * id, name, surname
     * @param id unique id of the student
     * @param name name of the student
     * @param dob date of birth
     */
    Student(int id, String name, String dob){
        setId(id);
        setName(name);
        setDateOfBirth(new Date());
        //Parsing the input String and turning it into date so that it could be stored
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        formatter.setLenient(false);
        try {
            setDateOfBirth(formatter.parse(dob));
        } catch (ParseException error) {
            System.out.println("Invalid date format!");
        }

        reservationDate = new Date();
        reservations = new ArrayList<TextbookReservation>();
        identityCheck =  new HashMap<Date,String>();
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

    public void setReservations(ArrayList<TextbookReservation> reservations) {
        this.reservations = reservations;
    }

    public void setReservationDate(Date reservationDate) {
        this.reservationDate = reservationDate;
    }

    public void setIdentityCheck(HashMap<Date, String> identityCheck) {
        this.identityCheck = identityCheck;
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

    public ArrayList<TextbookReservation> getReservations() {
        return reservations;
    }

    public Date getReservationDate() {
        return reservationDate;
    }

    public HashMap<Date,String> getIdentityCheck() {
        return identityCheck;
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
        while (!input.hasNextBoolean()) {
            System.out.println("\nPlease enter true or false:");
            input.nextLine();
        }
        boolean paymentStatus = input.nextBoolean();
        input.nextLine();

        ArrayList<BookItem> book_list = new ArrayList<BookItem>();
        reservationDate = new Date();

        System.out.println("\nEnter the number of books you want to reserve:");
        int num_books = readPositiveInt(input);

        for(int i=0; i< num_books ; i++)
        {
            System.out.println("\nEnter the book type: (Novel, Physics, Calculus etc.):");
            String book_type = input.nextLine();

            System.out.println("\nEnter quantity:");
            int quantity = readPositiveInt(input);

            System.out.println("\nEnter price:");
            int price = readPositiveInt(input);

            BookItem b = new BookItem(book_type,quantity,price);
            book_list.add(b);
        }
        TextbookReservation r = new TextbookReservation(book_list,paymentStatus,reservationDate);
        reservations.add(r);
    }

    private int readPositiveInt(Scanner input) {
        while (!input.hasNextInt()) {
            System.out.println("\nPlease enter a valid number:");
            input.nextLine();
        }
        int value = input.nextInt();
        input.nextLine();
        return Math.max(0, value);
    }

    /**
     * Method to add a reservation to a student without CLI
     * @param r a reservation
     */
    void makeReservation2(TextbookReservation r){
        reservations.add(r);
    }

    /**
     * Method to calculate the number of books in a reservation
     * @return total number of books in a reservation
     */
    @Override
    public double calculateTotalQuantity() {
        double total = MIN_TOTAL_QUANTITY;
        for(int i = 0; i <reservations.size();i++){
            for(int j = 0; j < reservations.get(i).getBookList().size(); j++){
                total = total + reservations.get(i).getBookList().get(j).getQuantity();
            }
        }
        return total;
    }

    /**
     * Method to compare student loyalty
     * @param o takes an object for comparison
     * @return the loyalty comparison of the students
     */
    @Override
    public int compareTo(Student s) {
        return (Double.compare(this.calculateTotalQuantity(),s.calculateTotalQuantity()));
    }


    /**
     * Method to help display Student details
     * %tF for printing Date data type
     */
    public void printStudent()
    {

        System.out.printf("Student ID: %d%n", getId());
        System.out.printf("Student Name: %s%n", getName());
        System.out.printf("Student Reservation Date: %tF%n", reservationDate);

        for (Map.Entry<Date, String> hashmap : identityCheck.entrySet()) {
            Date date = hashmap.getKey();
            String status = hashmap.getValue();

            System.out.printf("Identity Check Date: %tF , Identity Check Status: %s%n",
                    date, status);
        }

        System.out.println("\n---------------------------");
        System.out.printf("List of Reservations:%n");
        System.out.println("\n-----------------------------------------");
        if(reservations!=null) {
            System.out.printf("\nNumber or reservations: %d",reservations.size());
            System.out.println("\n-----------------------------------------");
            for (int i = 0; i < reservations.size(); i++) {
                reservations.get(i).printReservation();
            }
        }
    }
}
