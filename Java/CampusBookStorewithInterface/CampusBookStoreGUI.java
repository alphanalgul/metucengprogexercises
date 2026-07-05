package campusbookstore;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 * @author Alphan Algül
 * @version 1.0
 * The class that includes all the main functionalities of the assignment.
 * This class is for GUI.
 */
public class CampusBookStoreGUI {
    public ArrayList<Employee> empList;
    public ArrayList<Student> studentList;
    private static final int EMPLOYEE_FILE_MAGIC = 0x43424531;
    private static final int STUDENT_FILE_MAGIC = 0x43425331;

    /**
     * Default Constructor for the Campus Book Store
     */
    CampusBookStoreGUI()
    {
        empList = new ArrayList<Employee>();
        studentList = new ArrayList<Student>();
    }

    /**
     * Parametrized Constructor for the Campus Book Store
     * @param e takes an array list of employees as a parameter and sets empList to it
     */
    CampusBookStoreGUI(ArrayList<Employee> e){
        empList = e;
        studentList = new ArrayList<Student>();
    }

    /**
     * Parametrized Constructor for the Campus Book Store Class
     * @param e takes an array list of employees  as a parameter and sets empList to it
     * @param s takes an array list of students as a parameter and sets studentList to it
     */
    CampusBookStoreGUI(ArrayList<Employee> e, ArrayList<Student> s){
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

    private Integer parseIntInput(JFrame frame, String text, String fieldName) {
        try {
            return Integer.parseInt(text.trim());
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, fieldName + " must be a valid number.");
            return null;
        }
    }

    private SimpleDateFormat dateFormatter() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        sdf.setLenient(false);
        return sdf;
    }

    private Date parseDateInput(JFrame frame, String text, String fieldName) {
        try {
            return dateFormatter().parse(text.trim());
        } catch (ParseException e) {
            JOptionPane.showMessageDialog(frame, fieldName + " must be in dd/MM/yyyy format.");
            return null;
        }
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

    private Employee findEmployeeById(int id) {
        for (Employee employee : empList) {
            if (employee.getId() == id) {
                return employee;
            }
        }
        return null;
    }

    private String assignedEmployeeName(BookItem book) {
        Employee assigned = book.getAssigned();
        return assigned == null ? "Unassigned" : assigned.getName();
    }

    private void addStudentRows(DefaultTableModel tableModel, Student student) {
        SimpleDateFormat sdf = dateFormatter();
        ArrayList<Map.Entry<Date, String>> checks =
                new ArrayList<Map.Entry<Date, String>>(student.getIdentityCheck().entrySet());
        if (checks.isEmpty()) {
            checks.add(null);
        }

        if (student.getReservations().isEmpty()) {
            for (Map.Entry<Date, String> check : checks) {
                tableModel.addRow(new Object[]{
                        student.getId(),
                        student.getName(),
                        sdf.format(student.getDateOfBirth()),
                        sdf.format(student.getReservationDate()),
                        check == null ? "N/A" : sdf.format(check.getKey()),
                        check == null ? "N/A" : check.getValue(),
                        "N/A", "N/A", "N/A", "N/A", "N/A", "N/A"
                });
            }
            return;
        }

        for (Map.Entry<Date, String> check : checks) {
            for (TextbookReservation reservation : student.getReservations()) {
                if (reservation.getBookList().isEmpty()) {
                    tableModel.addRow(new Object[]{
                            student.getId(),
                            student.getName(),
                            sdf.format(student.getDateOfBirth()),
                            sdf.format(student.getReservationDate()),
                            check == null ? "N/A" : sdf.format(check.getKey()),
                            check == null ? "N/A" : check.getValue(),
                            reservation.getPaidStatus(),
                            sdf.format(reservation.getReservationDate()),
                            "N/A", "N/A", "N/A", "N/A"
                    });
                    continue;
                }

                for (BookItem book : reservation.getBookList()) {
                    tableModel.addRow(new Object[]{
                            student.getId(),
                            student.getName(),
                            sdf.format(student.getDateOfBirth()),
                            sdf.format(student.getReservationDate()),
                            check == null ? "N/A" : sdf.format(check.getKey()),
                            check == null ? "N/A" : check.getValue(),
                            reservation.getPaidStatus(),
                            sdf.format(reservation.getReservationDate()),
                            book.getType(),
                            book.getQuantity(),
                            book.getPrice(),
                            assignedEmployeeName(book)
                    });
                }
            }
        }
    }

    /**
     * Menu method that allows the user to interact with the system
     * adding employees, deleting students, making reservations, recording identity checks etc.
     * It creates a menu bar and from the menu bar the user can access all functionalities of the
     * Campus Book Store.
     */
    public void menu(){
        //frame
        JFrame frame = new JFrame("Campus Book Store");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 600);
        frame.setLocationRelativeTo(null);

        //top level container
        Container container= frame.getContentPane();
        container.setLayout(new BorderLayout());

        JOptionPane.showMessageDialog(frame,"Welcome to the Campus Book Store!");

        //CMenu Bar
        JMenuBar menu_bar =  new JMenuBar();
        //Menu
        JMenu menu = new JMenu("Menu");
        //Menu Items
        JMenuItem add_employee = new JMenuItem("1.Add Employee");
        JMenuItem delete_employee = new JMenuItem("2.Delete Employee");
        JMenuItem list_employee_details = new JMenuItem("3.List Employee Details");
        JMenuItem add_student = new JMenuItem("4.Add Student");
        JMenuItem delete_student = new JMenuItem("5.Delete Student");
        JMenuItem get_student_details = new JMenuItem("6.Get Student Details");
        JMenuItem make_reservation = new JMenuItem("7.Make Reservation");
        JMenuItem get_student_reservation = new JMenuItem("8.Get Student Reservation Details");
        JMenuItem get_student_reservation_cost = new JMenuItem("9.Get Student Reservation Total Cost");
        JMenuItem list_all_employees = new JMenuItem("10.List All Employees");
        JMenuItem list_all_students = new JMenuItem("11.List All Students");
        JMenuItem record_identity_check = new JMenuItem("12.Record Identity Check");
        JMenuItem compare_item_fees = new JMenuItem("13.Compare Item Fees");
        JMenuItem exit = new JMenuItem("14.Exit");

        //Configuring the menu
        menu.add(add_employee);
        menu.add(delete_employee);
        menu.add(list_employee_details);
        menu.add(add_student);
        menu.add(delete_student);
        menu.add(get_student_details);
        menu.add(make_reservation);
        menu.add(get_student_reservation);
        menu.add(get_student_reservation_cost);
        menu.add(list_all_employees);
        menu.add(list_all_students);
        menu.add(record_identity_check);
        menu.add(compare_item_fees);
        menu.add(exit);
        menu_bar.add(menu);
        frame.setJMenuBar(menu_bar);

        frame.setVisible(true);

        //Displaying all the options for CampusBookStore methods
        addEmployee(frame,add_employee,container);
        deleteEmployee(frame,delete_employee,container);
        listEmployeeDetails(frame,list_employee_details,container);
        addStudent(frame,add_student,container);
        deleteStudent(frame,delete_student,container);
        getStudentDetails(frame,get_student_details,container);
        makeReservation(frame,make_reservation,container);
        getStudentReservationDetails(frame,get_student_reservation,container);
        getStudentReservationCost(frame,get_student_reservation_cost,container);
        listEmployees(list_all_employees,container);
        listStudents(frame,list_all_students,container);
        exit(frame,exit,container);
        identityCheck(frame,record_identity_check,container);
        compareStudentLoyalty(frame,compare_item_fees,container);
    }

    /**
     * A method which allows the user to enter employee details through a GUI, adds that employee
     * and saves it to a file
     * Each employee should have a unique id
     * @param add_employee when the add employee option is clicked
     * @param container the top level container for the entire gui
     */
    public void addEmployee(JFrame frame,JMenuItem add_employee, Container container) {


        JPanel add_employee_panel = new JPanel(new GridLayout(6, 2));
        JLabel id = new JLabel("Enter Employee ID:");
        JTextField id_field = new JTextField(15);
        JLabel name = new JLabel("Enter Employee Name:");
        JTextField name_field = new JTextField(15);
        JLabel dob = new JLabel("Enter Employee Date of Birth:");
        JTextField dob_field = new JTextField(15);
        JLabel start_date = new JLabel("Enter Employee Start Date:");
        JTextField start_date_field = new JTextField(15);
        JButton add_employee_file_chooser_button = new JButton("Choose a File");
        JButton add_employee_button = new JButton("Submit");



        add_employee_panel.add(id);
        add_employee_panel.add(id_field);
        add_employee_panel.add(name);
        add_employee_panel.add(name_field);
        add_employee_panel.add(dob);
        add_employee_panel.add(dob_field);
        add_employee_panel.add(start_date);
        add_employee_panel.add(start_date_field);
        add_employee_panel.add(add_employee_file_chooser_button);



        JFileChooser add_employee_file_chooser = new JFileChooser();
        add_employee_panel.add(add_employee_button);

        //To prevent the fields from overextending
        JPanel add_employee_wrapper = new JPanel();
        add_employee_wrapper.add(add_employee_panel);

        //I defined it like this because intellij wouldnt allow me to define it normally as a File
        //and use it in both file chooser button and submit button
        final File[] filename = new File[1];

        add_employee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(add_employee_wrapper);
                //To ensure that everything loads correctly
                container.revalidate();
                container.repaint();
            }
        });

        add_employee_file_chooser_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int result = add_employee_file_chooser.showSaveDialog(container);

                //When the user selects a file save it
                if (result == JFileChooser.APPROVE_OPTION) {
                    filename[0] = add_employee_file_chooser.getSelectedFile();
                }

            }
        });

        add_employee_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int check = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Employee ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                String name = name_field.getText();
                String dob = dob_field.getText();
                String start_date = start_date_field.getText();
                if (parseDateInput(frame, dob, "Employee Date of Birth") == null ||
                        parseDateInput(frame, start_date, "Employee Start Date") == null) {
                    return;
                }


                for(int i = 0; i < empList.size(); i++)
                {
                    if(id == empList.get(i).getId()){
                        check = 1;
                    }
                }
                if(check==1) {
                    JOptionPane.showMessageDialog(frame, "Duplicate ID!" +
                            " Cant add this employee");
                    return;
                }

                Employee emp = new Employee(id, name, dob, start_date);
                empList.add(emp);

                //If the user doesnt select any existing files, create it
                if (filename[0] == null) {
                    filename[0] = new File("employee.dat");
                }

                writeEmployeesToFile(frame,empList, filename[0]);
            }
        });

    }

    /**
     * A method which takes an id from the user and deletes the employee from both the employee
     * list and the employee file
     * @param frame frame to display  messages
     * @param delete_employee when the add employee option is clicked
     * @param container the top level container for the entire gui
     */
    public void deleteEmployee(JFrame frame, JMenuItem delete_employee, Container container) {

        JPanel delete_employee_panel = new JPanel(new GridLayout(6, 2));
        JLabel id = new JLabel("Enter Employee ID:");
        JTextField id_field = new JTextField(15);

        JButton delete_employee_file_chooser_button = new JButton("Choose a File");
        JButton delete_employee_button = new JButton("Submit");

        delete_employee_panel.add(id);
        delete_employee_panel.add(id_field);

        delete_employee_panel.add(delete_employee_file_chooser_button);

        JFileChooser delete_employee_file_chooser = new JFileChooser();

        delete_employee_panel.add(delete_employee_button);

        JPanel delete_employee_wrapper = new JPanel();
        delete_employee_wrapper.add(delete_employee_panel);

        //I defined it like this because intellij wouldnt allow me to define it normally as a File
        //and use it in both file chooser button and submit button
        final File[] filename = new File[1];

        delete_employee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(delete_employee_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        delete_employee_file_chooser_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int result = delete_employee_file_chooser.showSaveDialog(container);
                //When the user selects a file save it
                if (result == JFileChooser.APPROVE_OPTION) {
                    filename[0] = delete_employee_file_chooser.getSelectedFile();
                }
            }
        });

        delete_employee_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Employee ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;

                int check = 0;
                for (int i = 0; i < empList.size(); i++) {
                    if (id == empList.get(i).getId()) {
                        empList.remove(i);
                        check = 1;
                    }
                }
                if (check == 0) {
                    JOptionPane.showMessageDialog(frame, "Employee Not Found!!");
                }

                //If the user doesnt select any existing files, create it
                if (filename[0] == null) {
                    filename[0] = new File("employee.dat");
                }

                writeEmployeesToFile(frame,empList, filename[0]);
            }
        });

    }

    /**
     * Takes an id from the user and lists the details of the employee with that id
     * @param frame frame to display messages
     * @param list_employee when the list employee details option is clicked
     * @param container the top level container for the entire gui
     */
    public void listEmployeeDetails(JFrame frame, JMenuItem list_employee, Container container){

        JPanel list_employee_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Employee ID:");
        JTextField id_field = new JTextField(15);

        JButton list_employee_button = new JButton("Submit");

        list_employee_panel.add(id);
        list_employee_panel.add(id_field);


        list_employee_panel.add(list_employee_button);

        JPanel list_employee_wrapper = new JPanel();
        list_employee_wrapper.add(list_employee_panel);

        list_employee.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(list_employee_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        list_employee_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int check = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Employee ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;

                for (int j = 0; j < empList.size(); j++) {
                    if (id == empList.get(j).getId()) {
                        check = 1;
                        JPanel list_employee_panel = new JPanel(new GridLayout(2, 1));

                        JTextArea text_area = new JTextArea("Type something here.");
                        JScrollPane text_area_scroll = new JScrollPane(text_area);

                        String[] columns = {"ID", "Name", "Date of Birth", "Start Date"};
                        DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                        Object[] rows = {empList.get(j).getId(), empList.get(j).getName(),
                                sdf.format(empList.get(j).getDateOfBirth()),
                                sdf.format(empList.get(j).getStartDate())};
                        table_model.addRow(rows);

                        JTable employee_table = new JTable(table_model);
                        JScrollPane table_scroll = new JScrollPane(employee_table);

                        list_employee_panel.add(text_area_scroll);
                        list_employee_panel.add(table_scroll);

                        container.removeAll();
                        container.add(list_employee_panel);
                        container.revalidate();
                        container.repaint();
                    }
                }
                if (check == 0) {
                    JOptionPane.showMessageDialog(frame, "Employee Not Found!!");
                }
            }
        });

    }

    /**
     * Method for adding students. Take student data as input from the user
     * create a student, then save it in both the student array list and the student file
     * @param add_student when the add student option is clicked
     * @param container the top level container for the entire gui
     * @param frame frame to display  messages
     */
    public void addStudent(JFrame frame,JMenuItem add_student, Container container){

        JPanel add_student_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);
        JLabel name = new JLabel("Enter Student Name:");
        JTextField name_field = new JTextField(15);
        JLabel dob = new JLabel("Enter Student Date of Birth:");
        JTextField dob_field = new JTextField(15);

        JButton add_student_file_chooser_button = new JButton("Choose a File");

        JButton add_student_button = new JButton("Submit");

        add_student_panel.add(id);
        add_student_panel.add(id_field);
        add_student_panel.add(name);
        add_student_panel.add(name_field);
        add_student_panel.add(dob);
        add_student_panel.add(dob_field);

        add_student_panel.add(add_student_file_chooser_button);

        JFileChooser add_student_file_chooser = new JFileChooser();

        add_student_panel.add(add_student_button);

        JPanel add_student_wrapper = new JPanel();
        add_student_wrapper.add(add_student_panel);

        //I defined it like this because intellij wouldnt allow me to define it normally as a File
        //and use it in both file chooser button and submit button
        final File[] filename = new File[1];
        add_student.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(add_student_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        add_student_file_chooser_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int result = add_student_file_chooser.showSaveDialog(container);

                if (result == JFileChooser.APPROVE_OPTION) {
                    filename[0] = add_student_file_chooser.getSelectedFile();
                }

            }
        });


        add_student_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int check = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                String name = name_field.getText();
                String dob = dob_field.getText();
                if (parseDateInput(frame, dob, "Student Date of Birth") == null) {
                    return;
                }

                if (filename[0] == null) {
                    filename[0] = new File("student.dat");
                }

                for(int i = 0; i < studentList.size(); i++)
                {
                    if(id == studentList.get(i).getId()){
                        check = 1;
                    }
                }


                if(check==1) {
                    JOptionPane.showMessageDialog(frame, "Duplicate ID!" +
                            " Cant add this student");
                    return;
                }

                Student std = new Student(id,name,dob);
                studentList.add(std);

                writeStudentsToFile(frame,studentList, filename[0]);
            }
        });


    }

    /**
     * Takes an id as input from the user and deletes the student with that id from both the student list
     * and the student file
     * @param frame  frame to display messages
     * @param delete_student when the delete student option is clicked
     * @param container the top level container for the entire gui
     */
    public void deleteStudent(JFrame frame, JMenuItem delete_student, Container container){

        JPanel delete_student_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);

        JButton delete_student_file_chooser_button = new JButton("Choose a File");

        JButton delete_student_button = new JButton("Submit");

        delete_student_panel.add(id);
        delete_student_panel.add(id_field);

        delete_student_panel.add(delete_student_file_chooser_button);

        JFileChooser delete_student_file_chooser = new JFileChooser();

        delete_student_panel.add(delete_student_button);

        JPanel delete_student_wrapper = new JPanel();
        delete_student_wrapper.add(delete_student_panel);

        //I defined it like this because intellij wouldnt allow me to define it normally as a File
        //and use it in both file chooser button and submit button
        final File[] filename = new File[1];

        delete_student.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(delete_student_wrapper);
                container.revalidate();
                container.repaint();
            }
        }
        );

        delete_student_file_chooser_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int result = delete_student_file_chooser.showSaveDialog(container);

                if (result == JFileChooser.APPROVE_OPTION) {
                    filename[0] = delete_student_file_chooser.getSelectedFile();
                }
            }
        });

        delete_student_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                int check = 0;
                for(int i = 0; i < studentList.size();i++){
                    if(id == studentList.get(i).getId()){
                        studentList.remove(i);
                        check = 1;
                    }
                }
                if(check == 0){
                    JOptionPane.showMessageDialog(frame,"Student Not Found!!");
                }
                if (filename[0] == null) {
                    filename[0] = new File("student.dat");
                }

                writeStudentsToFile(frame,studentList, filename[0]);
            }
        });

    }

    /**
     * Takes an id from the user as input from the user
     * then displays all the details(name,dob,reservations etc.) of the student with that id
     * @param frame frame to display messages
     * @param list_student when the get student details option is clicked
     * @param container the top level container for the entire gui
     */
    public void getStudentDetails(JFrame frame, JMenuItem list_student, Container container){

        JPanel list_student_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);

        JButton list_student_button = new JButton("Submit");

        list_student_panel.add(id);
        list_student_panel.add(id_field);

        list_student_panel.add(list_student_button);

        JPanel list_student_wrapper = new JPanel();
        list_student_wrapper.add(list_student_panel);

        list_student.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                container.removeAll();
                container.add(list_student_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        list_student_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                int check = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;


                for(int j =0; j<studentList.size(); j++) {
                    if (id == studentList.get(j).getId()) {
                        check = 1;
                        JPanel list_employee_panel = new JPanel(new GridLayout(2, 1));

                        JTextArea text_area = new JTextArea("Type something here.");
                        JScrollPane text_area_scroll = new JScrollPane(text_area);

                        String[] columns = {"ID", "Name", "Date of Birth","Student Reservation Date",
                                "Identity Check Date", "Identity Check Status","Paid Status",
                                "Reservation Date","Book Type","Quantity","Price", "Assigned Employee"};
                        DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                        addStudentRows(table_model, studentList.get(j));

                        JTable employee_table = new JTable(table_model);
                        JScrollPane table_scroll = new JScrollPane(employee_table);

                        list_employee_panel.add(text_area_scroll);
                        list_employee_panel.add(table_scroll);

                        container.removeAll();
                        container.add(list_employee_panel);
                        container.revalidate();
                        container.repaint();
                    }
                }
                if(check == 0){
                    JOptionPane.showMessageDialog(frame,"Student Not Found!!");
                }
            }
        });
    }

    /**
     * Takes reservation details(payment status , book type, quantity price) and student id from the
     * user, adds the reservation to the list of reservations of the student with the input id
     * @param frame frame to display messages
     * @param make_reservation when the make reservation option is clicked
     * @param container the top level container for the entire gui
     */
    public void makeReservation(JFrame frame, JMenuItem make_reservation, Container container){

        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);

        JPanel make_reservation_panel = new JPanel(new GridLayout(6,2));
        JLabel combo_box = new JLabel("Enter the Payment status(true/false):");
        JComboBox<Boolean> comboBox = new JComboBox<>();
        comboBox.addItem(true);
        comboBox.addItem(false);

        JLabel book_type = new JLabel("Enter the Book Type(Novel,Physics,Calculus etc.):");
        JTextField book_type_field = new JTextField(15);
        JLabel quantity = new JLabel("Enter Quantity:");
        JTextField quantity_field = new JTextField(15);
        JLabel price = new JLabel("Enter Price:");
        JTextField price_field = new JTextField(15);

        JButton add_employee_button = new JButton("Submit");

        make_reservation_panel.add(id);
        make_reservation_panel.add(id_field);
        make_reservation_panel.add(combo_box);
        make_reservation_panel.add(comboBox);
        make_reservation_panel.add(book_type);
        make_reservation_panel.add(book_type_field);
        make_reservation_panel.add(quantity);
        make_reservation_panel.add(quantity_field);
        make_reservation_panel.add(price);
        make_reservation_panel.add(price_field);

        make_reservation_panel.add(add_employee_button);

        JPanel make_reservation_wrapper = new JPanel();
        make_reservation_wrapper.add(make_reservation_panel);

        make_reservation.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(make_reservation_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        add_employee_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                Integer parsedQuantity = parseIntInput(frame, quantity_field.getText(), "Quantity");
                Integer parsedPrice = parseIntInput(frame, price_field.getText(), "Price");
                if (parsedId == null || parsedQuantity == null || parsedPrice == null) {
                    return;
                }
                int id = parsedId;
                boolean status = (boolean) comboBox.getSelectedItem();
                String type = book_type_field.getText();
                int quantity = parsedQuantity;
                int price = parsedPrice;

                BookItem b = new BookItem(type, quantity, price);
                Employee assignedEmployee = randomEmployee();
                if (assignedEmployee == null) {
                    JOptionPane.showMessageDialog(frame,
                            "No employees available to assign to this reservation.");
                    return;
                }
                b.setAssigned(assignedEmployee);
                TextbookReservation r = new TextbookReservation(status);
                r.add_book(b);

                int check = 0;
                for (int i = 0; i < studentList.size(); i++) {
                    if (studentList.get(i).getId() == id) {
                        studentList.get(i).makeReservation2(r);
                        check = 1;
                    }
                }

                if (check == 0) {
                    JOptionPane.showMessageDialog(frame, "Student Not Found!!");
                }

            }
        });
    }

    /**
     * Takes Student ID and Reservation Date as input from the user
     * and displays all the reservations of the student with the given id on that date
     * @param frame frame to display  messages
     * @param get_student_reservation when the get student reservation details option is clicked
     * @param container the top level container for the entire gui
     */
    public void getStudentReservationDetails(JFrame frame, JMenuItem get_student_reservation,
                                          Container container){

        JPanel reservation_details_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);
        JLabel date = new JLabel("Enter Reservation Date:");
        JTextField date_field = new JTextField(15);

        JButton get_reservation_details_button = new JButton("Submit");

        reservation_details_panel.add(id);
        reservation_details_panel.add(id_field);
        reservation_details_panel.add(date);
        reservation_details_panel.add(date_field);

        reservation_details_panel.add(get_reservation_details_button);

        JPanel get_reservation_details_wrapper = new JPanel();
        get_reservation_details_wrapper.add(reservation_details_panel);

        get_student_reservation.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(get_reservation_details_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        get_reservation_details_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                SimpleDateFormat sdf = dateFormatter();
                int check = 0;
                int check2 = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                Date res_date = parseDateInput(frame, date_field.getText(), "Reservation Date");
                if (res_date == null) {
                    return;
                }

                for(int j =0; j<studentList.size(); j++) {
                    if (id == studentList.get(j).getId()) {
                        check = 1;

                        JPanel res_table_panel = new JPanel(new GridLayout(2, 1));
                        JTextArea text_area = new JTextArea("Type something here.");
                        JScrollPane text_area_scroll = new JScrollPane(text_area);

                        if (studentList.get(j).getReservations().isEmpty()) {
                            JOptionPane.showMessageDialog(frame,
                                    "This student has no reservations.\nStudent reservation details cannot be displayed.");
                            return;
                        }

                        String[] columns = {"ID", "Name", "Paid Status", "Reservation Date","Book Type","Quantity",
                                "Price", "Assigned Employee"};
                        DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                        for (int i = 0; i < studentList.get(j).getReservations().size(); i++) {
                            if (sdf.format(studentList.get(j).getReservations().get(i).getReservationDate())
                                    .equals(sdf.format(res_date))){
                                check2 = 1;
                                for(int k = 0; k < studentList.get(j).getReservations().get(i).getBookList().size();
                                    k++){
                                    Object[] rows =
                                            {studentList.get(j).getId(),
                                                    studentList.get(j).getName(),
                                                    studentList.get(j).getReservations().get(i).getPaidStatus(),
                                                    sdf.format(studentList.get(j).getReservations().get(i).
                                                            getReservationDate()),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getType(),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getQuantity(),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getPrice(),
                                                    assignedEmployeeName(studentList.get(j).getReservations().
                                                            get(i).getBookList().get(k))
                                            };

                                    table_model.addRow(rows);
                                }

                            }
                        }

                        if(check2 == 0){
                            JOptionPane.showMessageDialog(frame,"No reservations found on this date!");
                            return;
                        }

                        JTable reservation_details_table = new JTable(table_model);
                        JScrollPane table_scroll = new JScrollPane(reservation_details_table);

                        res_table_panel.add(text_area_scroll);
                        res_table_panel.add(table_scroll);

                        container.removeAll();
                        container.add(res_table_panel);
                        container.revalidate();
                        container.repaint();
                    }
                }

                if(check == 0){
                    JOptionPane.showMessageDialog(frame,"Student Not Found!!");
                }
            }
        });
    }

    /**
     * Takes student id and reservation date as input from the user, then displays all the reservations
     * made by the user on that date
     * @param frame frame to display  messages
     * @param get_student_reservation_cost when the get student reservation details option is clicked
     * @param container the top level container for the entire gui
     */
    public void getStudentReservationCost(JFrame frame, JMenuItem get_student_reservation_cost, Container
            container){

        JPanel reservation_cost_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);
        JLabel date = new JLabel("Enter Reservation Date:");
        JTextField date_field = new JTextField(15);

        JButton reservation_cost_button = new JButton("Submit");

        reservation_cost_panel.add(id);
        reservation_cost_panel.add(id_field);
        reservation_cost_panel.add(date);
        reservation_cost_panel.add(date_field);

        reservation_cost_panel.add(reservation_cost_button);

        JPanel reservation_cost_wrapper = new JPanel();
        reservation_cost_wrapper.add(reservation_cost_panel);

        get_student_reservation_cost.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                container.removeAll();
                container.add(reservation_cost_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        reservation_cost_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                SimpleDateFormat sdf = dateFormatter();
                int check = 0;
                int check2 = 0;
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                Date res_date = parseDateInput(frame, date_field.getText(), "Reservation Date");
                if (res_date == null) {
                    return;
                }

                for(int j =0; j<studentList.size(); j++) {
                    if (id == studentList.get(j).getId()) {
                        check = 1;

                        JPanel res_table_panel = new JPanel(new GridLayout(2, 1));
                        JTextArea text_area = new JTextArea("Type something here.");
                        JScrollPane text_area_scroll = new JScrollPane(text_area);

                        if (studentList.get(j).getReservations().isEmpty()) {
                            JOptionPane.showMessageDialog(frame,
                                    "This student has no reservations.\nStudent reservation details cannot be displayed.");
                            return;
                        }

                        String[] columns = {"ID", "Name", "Paid Status", "Reservation Date","Book Type","Quantity",
                                "Price", "Assigned Employee", "Total Cost"};
                        DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                        for (int i = 0; i < studentList.get(j).getReservations().size(); i++) {
                            if (sdf.format(studentList.get(j).getReservations().get(i).getReservationDate())
                                    .equals(sdf.format(res_date))){
                                check2 = 1;
                                for(int k = 0; k < studentList.get(j).getReservations().get(i).getBookList().size();
                                    k++){
                                    Object[] rows =
                                            {studentList.get(j).getId(),
                                                    studentList.get(j).getName(),
                                                    studentList.get(j).getReservations().get(i).getPaidStatus(),
                                                    sdf.format(studentList.get(j).getReservations().get(i).
                                                            getReservationDate()),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getType(),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getQuantity(),
                                                    studentList.get(j).getReservations().get(i).getBookList().
                                                            get(k).getPrice(),
                                                    assignedEmployeeName(studentList.get(j).getReservations().
                                                            get(i).getBookList().get(k)),
                                                    studentList.get(j).getReservations().get(i).totalReservationCost()
                                            };

                                    table_model.addRow(rows);
                                }

                            }
                        }
                        if(check2 == 0){
                            JOptionPane.showMessageDialog(frame,"No reservations found on this date!");
                            return;
                        }


                        JTable reservation_details_table = new JTable(table_model);
                        JScrollPane table_scroll = new JScrollPane(reservation_details_table);

                        res_table_panel.add(text_area_scroll);
                        res_table_panel.add(table_scroll);

                        container.removeAll();
                        container.add(res_table_panel);
                        container.revalidate();
                        container.repaint();
                    }
                }
                if(check == 0){
                    JOptionPane.showMessageDialog(frame,"Student Not Found!!");
                }
            }
        });
    }


    /**
     * Displays the details of all the employees
     * @param list_all_employees when the list employees option is clicked
     * @param container the top level container for the entire gui
     */
    public void listEmployees(JMenuItem list_all_employees,Container container){
        list_all_employees.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel list_employee_panel = new JPanel(new GridLayout(2, 1));

                JTextArea text_area = new JTextArea("Type something here.");
                JScrollPane text_area_scroll = new JScrollPane(text_area);

                String[] columns = {"ID", "Name", "Date of Birth", "Start Date"};
                DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                for (int i = 0; i < empList.size(); i++) {
                    Object[] rows = {empList.get(i).getId(), empList.get(i).getName(),
                            sdf.format(empList.get(i).getDateOfBirth()),
                            sdf.format(empList.get(i).getStartDate())};

                    table_model.addRow(rows);
                }
                JTable employee_table = new JTable(table_model);
                JScrollPane table_scroll = new JScrollPane(employee_table);

                list_employee_panel.add(text_area_scroll);
                list_employee_panel.add(table_scroll);

                container.removeAll();
                container.add(list_employee_panel);
                container.revalidate();
                container.repaint();
            }
        });
    }

    /**
     * Displays the details of all the students
     * @param frame frame to display  messages
     * @param list_all_students when the list students option is clicked
     * @param container the top level container for the entire gui
     */
    public void listStudents(JFrame frame,JMenuItem list_all_students,Container container){
        list_all_students.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel list_student_panel = new JPanel(new GridLayout(2, 1));

                JTextArea text_area = new JTextArea("Type something here.");
                JScrollPane text_area_scroll = new JScrollPane(text_area);

                String[] columns = {"ID", "Name", "Date of Birth","Student Reservation Date","Identity Check Date",
                        "Identity Check Status","Paid Status", "Reservation Date","Book Type","Quantity","Price",
                        "Assigned Employee"};
                DefaultTableModel table_model = new DefaultTableModel(columns, 0);

                for (int i = 0; i < studentList.size(); i++) {
                    addStudentRows(table_model, studentList.get(i));
                }
                JTable student_table = new JTable(table_model);
                JScrollPane table_scroll = new JScrollPane(student_table);

                list_student_panel.add(text_area_scroll);
                list_student_panel.add(table_scroll);

                container.removeAll();
                container.add(list_student_panel);
                container.revalidate();
                container.repaint();
            }
        });
    }

    /**
     * For exiting the GUI
     * @param frame  frame to display messages
     * @param exit when the list students option is clicked
     * @param container the top level container for the entire gui
     */
    public void exit(JFrame frame, JMenuItem exit,Container container){

        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                JOptionPane.showMessageDialog(frame,"Byeee!!");
                frame.dispose();
            }
        });
    }

    /**
     * Takes the student id and student status from the user as input, then records the identity check
     * for the student with the taken id and that identity check is a hashmap (date performed,status)
     * @param frame frame to display messages
     * @param record_identity_check when the record identity check option is clicked
     * @param container the top level container for the entire gui
     */
    public void identityCheck(JFrame frame,JMenuItem record_identity_check, Container container){

        JPanel identity_check_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student ID:");
        JTextField id_field = new JTextField(15);
        JLabel status = new JLabel("Enter Student Status");
        JTextField status_field = new JTextField(15);

        JButton add_student_button = new JButton("Submit");

        identity_check_panel.add(id);
        identity_check_panel.add(id_field);
        identity_check_panel.add(status);
        identity_check_panel.add(status_field);

        identity_check_panel.add(add_student_button);

        JPanel identity_check_wrapper = new JPanel();
        identity_check_wrapper.add(identity_check_panel);

        record_identity_check.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                container.removeAll();
                container.add(identity_check_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        add_student_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student ID");
                if (parsedId == null) {
                    return;
                }
                int id = parsedId;
                String status = status_field.getText();
                int check = 0;
                for (int i = 0; i <studentList.size(); i++) {
                    if (id == studentList.get(i).getId()) {
                        check = 1;
                    }
                }
                if (check == 0) {
                    JOptionPane.showMessageDialog(frame, "Student Not Found!!");
                    return;
                }

                recordIdentityCheck(id,status);
            }
        });
    }

    /**
     * Takes 2 student ids from the user as input from the user and compares the loyalty of the two students
     * with the input id. Their loyalty is calculated based on the total quantity of their reservations
     * @param frame frame to display messages
     * @param compare_item_fees  when the compare student loyalty option is clicked
     * @param container the top level container for the entire gui
     */
    public void compareStudentLoyalty(JFrame frame, JMenuItem compare_item_fees, Container container){

        JPanel compare_fees_panel = new JPanel(new GridLayout(6,2));
        JLabel id = new JLabel("Enter Student 1 ID:");
        JTextField id_field = new JTextField(15);
        JLabel id2 = new JLabel("Enter Student 2 ID:");
        JTextField id2_field = new JTextField(15);

        JButton compare_fees_button = new JButton("Submit");

        compare_fees_panel.add(id);
        compare_fees_panel.add(id_field);
        compare_fees_panel.add(id2);
        compare_fees_panel.add(id2_field);

        compare_fees_panel.add(compare_fees_button);

        JPanel reservation_cost_wrapper = new JPanel();
        reservation_cost_wrapper.add(compare_fees_panel);

        compare_item_fees.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                container.removeAll();
                container.add(reservation_cost_wrapper);
                container.revalidate();
                container.repaint();
            }
        });
        compare_fees_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Integer parsedId = parseIntInput(frame, id_field.getText(), "Student 1 ID");
                Integer parsedId2 = parseIntInput(frame, id2_field.getText(), "Student 2 ID");
                if (parsedId == null || parsedId2 == null) {
                    return;
                }
                int id = parsedId;
                int id2 = parsedId2;

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
                    JOptionPane.showMessageDialog(frame,"Student 1 Not Found!!");
                    return;
                }
                if(index2 == -1){
                    JOptionPane.showMessageDialog(frame,"Student 2 Not Found!!");
                    return;
                }

                Student s1 = studentList.get(index1);
                Student s2 = studentList.get(index2);

                int c = s1.compareTo(s2);
                if(c > 0){
                    JOptionPane.showMessageDialog(frame,s1.getName() + " " + s1.getId() + " is more loyal");
                }
                else if(c==0){
                    JOptionPane.showMessageDialog(frame,s1.getName() + " " + s1.getId() + " and " +
                            s2.getName() +s2.getId() +  "have equal loyalty");
                }
                else{
                    JOptionPane.showMessageDialog(frame,s2.getName() + " " +
                            s2.getId() + " is more loyal");
                }
            }
        });
    }

    /**
     * Takes an array list of students and writes their data into a binary file
     * @param s array list of students
     * @param filename file that we are going to save our data to
     */
    public void writeStudentsToFile(JFrame frame,ArrayList<Student> s,File filename){
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
            JOptionPane.showMessageDialog(frame,"File cannot be opened!!");
        }
    }

    /**
     * Takes an array list of employees  and writes their data into a binary file
     * @param emp  array list of employees
     * @param filename  file that we are going to save our data to
     */
    public void writeEmployeesToFile(JFrame frame,ArrayList<Employee> emp, File filename){
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
            JOptionPane.showMessageDialog(frame,"File cannot be opened!!");
        }
    }

    /**
     * Reads data from a binary file and stores them into an array list of students
     * @param s array lists of students
     * @param filename the file that we are reading data from
     */
    public void readStudentsFromFile(ArrayList<Student> s, File filename){
        s.clear();
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
     * Reads data from a binary file and stores them into an array list of employees
     * @param emp array lists of employees
     * @param filename the file that we are reading data from
     */
    public void readEmployeesFromFile(ArrayList<Employee> emp, File filename){
        emp.clear();
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

    public static void main(String[] args) {
        CampusBookStoreGUI c = new CampusBookStoreGUI();
        File students = new File("student.dat");
        File employees = new File("employee.dat");
        if (employees.exists()) {
            c.readEmployeesFromFile(c.empList, new File("employee.dat"));
        }
        if(students.exists()){
            c.readStudentsFromFile(c.studentList, new File("student.dat"));
        }
        c.menu();
    }
}
