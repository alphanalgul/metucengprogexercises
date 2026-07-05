package campusbookstore;

import javax.swing.*;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

/**
 * @author Alphan Algül
 * @version 1.0
 * The class that includes all the main functionalities of the assignment.
 * This class is for CLI.
 */
public class CampusBookStore {
    public ArrayList<Employee> empList;
    public ArrayList<Student> studentList;
    private static final int EMPLOYEE_FILE_MAGIC = 0x43424531;
    private static final int STUDENT_FILE_MAGIC = 0x43425331;

    /**
     * Default Constructor for the Campus Book Store
     */
    CampusBookStore()
    {
        empList = new ArrayList<Employee>();
        studentList = new ArrayList<Student>();
    }

    /**
     * Parametrized Constructor for the Campus Book Store
     * @param e takes an array list of employees as a parameter and sets empList to it
     */
    CampusBookStore(ArrayList<Employee> e){
        empList = e;
        studentList = new ArrayList<Student>();
    }

    /**
     * Parametrized Constructor for the Campus Book Store Class
     * @param e takes an array list of employees  as a parameter and sets empList to it
     * @param s takes an array list of students as a parameter and sets studentList to it
     */
    CampusBookStore(ArrayList<Employee> e, ArrayList<Student> s){
        empList = e;
        studentList = s;
    }

    public void setStudentList(ArrayList<Student> studentList) {
        this.studentList = studentList;
    }

    public void setEmpList(ArrayList<Employee> empList) {
        this.empList = empList;
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }

    public ArrayList<Employee> getEmpList() {
        return empList;
    }

    private int readInt(Scanner input) {
        while (!input.hasNextInt()) {
            System.out.println("\nPlease enter a valid number:");
            input.nextLine();
        }
        int value = input.nextInt();
        input.nextLine();
        return value;
    }

    private SimpleDateFormat dateFormatter() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        sdf.setLenient(false);
        return sdf;
    }

    private String formatDate(Date date) {
        return dateFormatter().format(date == null ? new Date() : date);
    }

    private Date parseStoredDate(String dateText) {
        try {
            return dateFormatter().parse(dateText);
        } catch (ParseException e) {
            return new Date();
        }
    }

    private boolean isValidDate(String dateText) {
        try {
            dateFormatter().parse(dateText);
            return true;
        } catch (ParseException e) {
            return false;
        }
    }

    private Employee findEmployeeById(int id) {
        for (Employee employee : empList) {
            if (employee.getId() == id) {
                return employee;
            }
        }
        return null;
    }

    /**
     * Method for adding an Employee to the list of Employees
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void addEmployee() throws IOException {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter employee id:");
        int id = readInt(input);

        System.out.println("\nEnter employee name:");
        String name = input.nextLine();

        System.out.println("\nEnter employee date of birth:");
        String dob = input.nextLine();

        System.out.println("\nEnter employee start date:");
        String start = input.nextLine();
        if (!isValidDate(dob) || !isValidDate(start)) {
            System.out.println("\nInvalid date format! Use dd/MM/yyyy.");
            return;
        }

        Employee e = new Employee(id,name,dob,start);
        //Checking the id of every employee before adding a new one to prevent duplicates
        for(int i=0; i< empList.size();i++)
        {
            if(empList.get(i).getId() == e.getId())
            {
                System.out.println("\nDuplicate ID! Cannot add this employee");
                return;
            }
        }
        empList.add(e);
        writeEmployeesToFile(empList);
    }

    /**
     * Method for deleting an Employee based on the given ID
     * @param empId unique Employee ID
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void deleteEmployee(int empId) throws IOException {
        int check=0;
        for(int i=0 ; i< empList.size();i++)
        {
            if(empList.get(i).getId() == empId)
            {
                empList.remove(i);
                check=1;
                writeEmployeesToFile(empList);
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
            if(empList.get(i).getId() == empId)
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
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void addStudent() throws IOException {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter student id:");
        int id = readInt(input);

        System.out.println("\nEnter student name:");
        String name = input.nextLine();

        System.out.println("\nEnter student date of birth:");
        String dob = input.nextLine();
        if (!isValidDate(dob)) {
            System.out.println("\nInvalid date format! Use dd/MM/yyyy.");
            return;
        }

        Student s = new Student(id,name,dob);

        //Checking the id of every student before adding a new one to prevent duplicates
        for(int i=0; i< studentList.size();i++)
        {
            if(studentList.get(i).getId() == s.getId())
            {
                System.out.println("\nDuplicate ID! Cannot add this employee");
                return;
            }
        }
        studentList.add(s);
        writeStudentsToFile(studentList);
    }

    /**
     * Method for deleting a Student based on the given ID
     * @param id Unique Student ID
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void deleteStudent(int id) throws IOException {
        int check = 0;
        for(int i = 0; i<studentList.size();i++)
        {
            if(studentList.get(i).getId() == id)
            {
                studentList.remove(i);
                check = 1;
                writeStudentsToFile(studentList);
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
            if(studentList.get(i).getId() == id)
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
        if (empList.isEmpty()) {
            return null;
        }
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
            if (studentList.get(i).getId() == id) {

                if (empList.isEmpty()) {
                    System.out.println("\nNo employees available to assign to this reservation!");
                    return;
                }
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

            if (studentList.get(i).getId() == id)
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

            if (studentList.get(i).getId() == id) {

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
     * CLI Menu method that allows the user to interact with the system
     * For example 1. for adding an employee 11. for listing details of all the students etc.
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void menu() throws IOException {
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
            System.out.println("\n13. Record Identity Check");
            System.out.println("\n14. Compare Student Loyalty");
            System.out.println("\nEnter a choice:");
            choice = readInt(input);

            if(choice == 1) {

                addEmployee();
            }

            else if(choice == 2) {

                System.out.println("\nEnter the id of the employee you want to delete:");
                int id = readInt(input);
                deleteEmployee(id);
            }

            else if(choice == 3) {

                System.out.println("\nEnter the id of the employee you want to view the detail of:");
                int id = readInt(input);
                listEmployeeDetails(id);
            }

            else if(choice == 4) {

                addStudent();
            }

            else if(choice == 5) {

                System.out.println("\nEnter the id of the student you want to delete:");
                int id = readInt(input);
                deleteStudent(id);
            }

            else if(choice == 6) {

                System.out.println("\nEnter the id of the student you want to view the detail of:");
                int id = readInt(input);
                getStudentDetails(id);
            }

            else if(choice == 7) {

                System.out.println("\nEnter a Student id in order to make a reservation:");
                int id = readInt(input);

                makeReservation(id);
            }

            else if(choice == 8) {
                System.out.println("\nEnter a Student id in order to display the details of a reservation:");
                int id = readInt(input);

                System.out.println("\nEnter a date to see the reservations made on that " +
                        "date(dd/MM/yyyy):");
                String dateInput = input.nextLine();

                //Parsing the input String and turning it into date so that it could be stored
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                Date date_param;
                try {
                    formatter.setLenient(false);
                    date_param = formatter.parse(dateInput);
                } catch (ParseException error) {
                    System.out.println("Invalid date format!");
                    continue;
                }
                getReservationDetails(id, date_param);
            }

            else if(choice == 9) {
                System.out.println("\nEnter a Student id in order to see the costs of reservations:");
                int id = readInt(input);

                System.out.println("\nEnter a date to see the costs of reservations made on that " +
                        "date(dd/MM/yyyy):");
                String dateInput = input.nextLine();

                //Parsing the input String and turning it into date so that it could be stored
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                Date date_param;
                try {
                    formatter.setLenient(false);
                    date_param = formatter.parse(dateInput);
                } catch (ParseException error) {
                    System.out.println("Invalid date format!");
                    continue;
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

            else if(choice == 13) {
                System.out.println("\nEnter a Student id for an identity check:");
                int id = readInt(input);
                System.out.println("\nEnter the Student status for an identity check:");
                String status = input.nextLine();

                recordIdentityCheck(id,status);
            }

            else if(choice == 14) {
                System.out.println("\nEnter a Student id 1 for loyalty comparison:");
                int id = readInt(input);

                System.out.println("\nEnter a Student id 2 for loyalty comparison:");
                int id2 = readInt(input);
                int index1 = -1;
                int index2 = -1;


                for(int i = 0; i < studentList.size(); i++){
                    if(id == studentList.get(i).getId()){
                        index1 = i;
                    }
                }
                for(int i = 0; i < studentList.size(); i++){
                    if(id2 == studentList.get(i).getId()){
                        index2 = i;
                    }
                }

                if(index1 == -1){
                    System.out.println("\nStudent 1 Not Found!!");
                    continue;
                }

                if(index2 == -1){
                    System.out.println("\nStudent 2 Not Found!!");
                    continue;
                }

                Student s1 = studentList.get(index1);
                Student s2 = studentList.get(index2);

                int c = s1.compareTo(s2);
                if(c > 0){
                    System.out.printf("%s %d is more loyal than %s %d",s1.getName(),s1.getId()
                    ,s2.getName(),s2.getId());
                }
                else if(c==0){
                    System.out.printf("%s %d and %s %dhas equal loyalty",s1.getName(),s1.getId(),
                            s2.getName(),s2.getId());
                }
                else{
                    System.out.printf("%s %d is more loyal than %s %d",s2.getName(),s2.getId(),
                            s1.getName(),s1.getId());
                }
            }

            else{
                System.out.println("\nPlease enter a valid option!");
            }
        }
    }

    /**
     * Records the identity check (hashmap(date,status)) for a student with the given ID
     * @param studentID student ID
     * @param status student status (for example on Probation etc.)
     */
    public void recordIdentityCheck(int studentID, String status){
        for(int i = 0; i <studentList.size(); i++){
            if(studentID == studentList.get(i).getId()){
                studentList.get(i).getIdentityCheck().put(new Date(),status);
            }
        }
    }


    /**
     * Takes an array list of students and writes their data into a binary file
     * @param s array list of students
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void writeStudentsToFile(ArrayList<Student> s) throws IOException {
        Scanner file_name = new Scanner(System.in);
        System.out.println("\nEnter the name of the file to write student data to:");
        String file = file_name.nextLine();
        File filename = new File(file);

        if(!filename.exists()){
            filename.createNewFile();
        }

        try(DataOutputStream out = new DataOutputStream(new BufferedOutputStream(
                new FileOutputStream(filename)))){
            out.writeInt(STUDENT_FILE_MAGIC);
            out.writeInt(s.size());
            for(int i = 0; i < s.size(); i++){
                Student student = s.get(i);
                out.writeInt(student.getId());
                out.writeUTF(student.getName());
                out.writeUTF(formatDate(student.getDateOfBirth()));
                out.writeUTF(formatDate(student.getReservationDate()));

                out.writeInt(student.getIdentityCheck().size());
                for (Map.Entry<Date, String> check : student.getIdentityCheck().entrySet()) {
                    out.writeUTF(formatDate(check.getKey()));
                    out.writeUTF(check.getValue());
                }

                out.writeInt(student.getReservations().size());
                for (TextbookReservation reservation : student.getReservations()) {
                    out.writeUTF(formatDate(reservation.getReservationDate()));
                    out.writeBoolean(reservation.getPaidStatus());
                    out.writeInt(reservation.getBookList().size());
                    for (BookItem book : reservation.getBookList()) {
                        out.writeUTF(book.getType());
                        out.writeInt(book.getQuantity());
                        out.writeInt(book.getPrice());
                        Employee assigned = book.getAssigned();
                        out.writeInt(assigned == null ? -1 : assigned.getId());
                    }
                }

            }
        }catch (IOException e){
            System.out.println("\nFile cannot be opened!");
        }
    }

    /**
     * Takes an array list of employees  and writes their data into a binary file
     * @param emp array list of employees
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void writeEmployeesToFile(ArrayList<Employee> emp) throws IOException {
        Scanner file_name = new Scanner(System.in);
        System.out.println("\nEnter the name of the file to write employee data to:");
        String file = file_name.nextLine();
        File filename = new File(file);

        if(!filename.exists()){
            filename.createNewFile();
        }

        try(DataOutputStream out = new DataOutputStream(new BufferedOutputStream(
                new FileOutputStream(filename)))){
            out.writeInt(EMPLOYEE_FILE_MAGIC);
            out.writeInt(emp.size());
            for(int i = 0; i < emp.size(); i++){
                out.writeInt(emp.get(i).getId());
                out.writeUTF(emp.get(i).getName());
                out.writeUTF(formatDate(emp.get(i).getDateOfBirth()));
                out.writeUTF(formatDate(emp.get(i).getStartDate()));
            }
        }catch(IOException e){
            System.out.println("\nFile cannot be opened!");
        }
    }

    /**
     * Reads data from a binary file and stores them into an array list of students
     * @param s array lists of students
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void readStudentsFromFile(ArrayList<Student> s) throws IOException {
        s.clear();
        Scanner file_name = new Scanner(System.in);
        System.out.println("\nEnter the name of the file to read student data from:");
        String file = file_name.nextLine();
        File filename = new File(file);

        if(!filename.exists()){
            filename.createNewFile();
        }

        try(DataInputStream in = new DataInputStream(new BufferedInputStream(
                new FileInputStream(filename)))){

            in.mark(Integer.BYTES);
            int marker = in.readInt();
            if (marker == STUDENT_FILE_MAGIC) {
                int studentCount = in.readInt();
                for (int i = 0; i < studentCount; i++) {
                    int id = in.readInt();
                    String name = in.readUTF();
                    String dob = in.readUTF();

                    Student std = new Student(id,name,dob);
                    std.setReservationDate(parseStoredDate(in.readUTF()));

                    HashMap<Date, String> identityCheck = new HashMap<Date, String>();
                    int identityCount = in.readInt();
                    for (int j = 0; j < identityCount; j++) {
                        identityCheck.put(parseStoredDate(in.readUTF()), in.readUTF());
                    }
                    std.setIdentityCheck(identityCheck);

                    ArrayList<TextbookReservation> reservations =
                            new ArrayList<TextbookReservation>();
                    int reservationCount = in.readInt();
                    for (int j = 0; j < reservationCount; j++) {
                        Date reservationDate = parseStoredDate(in.readUTF());
                        boolean paidStatus = in.readBoolean();
                        TextbookReservation reservation =
                                new TextbookReservation(paidStatus, reservationDate);
                        int bookCount = in.readInt();
                        for (int k = 0; k < bookCount; k++) {
                            BookItem book = new BookItem(in.readUTF(), in.readInt(), in.readInt());
                            book.setAssigned(findEmployeeById(in.readInt()));
                            reservation.add_book(book);
                        }
                        reservations.add(reservation);
                    }
                    std.setReservations(reservations);
                    s.add(std);
                }
                return;
            }

            in.reset();
            while(true){
                int id = in.readInt();
                String name = in.readUTF();
                String dob = in.readUTF();

                Student std = new Student(id,name,dob);
                s.add(std);
            }
        }catch (EOFException e) {

        }catch(IOException e){
            System.out.println("\nFile cannot be opened!");
        }
    }

    /**
     * Reads data from a binary file and stores them into an array list of students
     * @param emp array list of employees
     * @throws IOException the method throws an IO Exception since files are used
     */
    public void readEmployeesFromFile(ArrayList<Employee> emp) throws IOException {
        emp.clear();
        Scanner file_name = new Scanner(System.in);
        System.out.println("\nEnter the name of the file to read employee data from:");
        String file = file_name.nextLine();
        File filename = new File(file);


        if(!filename.exists()){
            filename.createNewFile();
        }

        try(DataInputStream in = new DataInputStream(new BufferedInputStream(
                new FileInputStream(filename)))){

            in.mark(Integer.BYTES);
            int marker = in.readInt();
            if (marker == EMPLOYEE_FILE_MAGIC) {
                int employeeCount = in.readInt();
                for (int i = 0; i < employeeCount; i++) {
                    int id = in.readInt();
                    String name = in.readUTF();
                    String dob = in.readUTF();
                    String start_date = in.readUTF();

                    Employee E = new Employee(id,name,dob,start_date);
                    emp.add(E);
                }
                return;
            }

            in.reset();
            while(true){
                int id = in.readInt();
                String name = in.readUTF();
                String dob = in.readUTF();
                String start_date = in.readUTF();

                Employee E = new Employee(id,name,dob,start_date);
                emp.add(E);
            }
        }catch (EOFException e) {

        }catch(IOException e){
            System.out.println("\nFile cannot be opened!");
        }
    }


    public static void main(String[] args) throws IOException {
        CampusBookStore c = new CampusBookStore();
        c.readEmployeesFromFile(c.empList);
        c.readStudentsFromFile(c.studentList);
        c.menu();
    }
}
