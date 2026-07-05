import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.io.*;

public class Final
{
    public static class Employee implements Serializable{
        int id;
        String name;
        Date dateOfBirth;

        Employee(){
            id = 0;
            name = "undefined";
            dateOfBirth = new Date();
        }

        Employee(int i, String n, String dob) throws ParseException {
            id = i;
            name = n;
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            dateOfBirth = sdf.parse(dob);
        }

        public void setId(int id) {
            this.id = id;
        }

        public void setName(String name) {
            this.name = name;
        }

        public void setDateOfBirth(Date dateOfBirth) {
            this.dateOfBirth = dateOfBirth;
        }

        public int getId() {
            return id;
        }

        public String getName() {
            return name;
        }

        public Date getDateOfBirth() {
            return dateOfBirth;
        }
    }

    public ArrayList<Employee> empList;

    Final(){
        empList = new ArrayList<Employee>();
    }

    Final(ArrayList<Employee> e){
        empList = e;
    }

    public void menu(){
        JFrame frame = new JFrame("Employee Tracking Application");
        JOptionPane.showMessageDialog(frame,"Welcome to the Employee Tracking Application!");

        Container container = frame.getContentPane();
        container.setLayout(new BorderLayout());

        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");

        JMenuItem add_employee = new JMenuItem("1. Add Employee");
        JMenuItem delete_employee = new JMenuItem("2. Delete Employee");
        JMenuItem list_employees = new JMenuItem("3. List All Employees");
        JMenuItem exit = new JMenuItem("4. Exit");

        menu.add(add_employee);
        menu.add(delete_employee);
        menu.add(list_employees);
        menu.add(exit);

        menuBar.add(menu);

        frame.setJMenuBar(menuBar);

        frame.setVisible(true);

        addEmployee(frame,add_employee,container);
        deleteEmployee(frame,delete_employee,container);
        listEmployees(list_employees,container);
        exit(frame,exit);
    }

    public void addEmployee(JFrame frame,JMenuItem add_employee, Container container){
        JPanel add_employee_panel = new JPanel(new GridLayout(6,2));
        JLabel id_label = new JLabel("Enter Employee ID:");
        JTextField id_field= new JTextField(15);
        JLabel name_label = new JLabel("Enter Employee Name:");
        JTextField name_field = new JTextField(15);
        JLabel dob_label = new JLabel("Enter Employee Date of Birth:");
        JTextField dob_field = new JTextField(15);
        JLabel file_label = new JLabel("Enter the name of the file that you want to save this employee to:");
        JTextField file_field = new JTextField(15);
        JButton add_employee_button = new JButton("Submit");

        add_employee_panel.add(id_label);
        add_employee_panel.add(id_field);
        add_employee_panel.add(name_label);
        add_employee_panel.add(name_field);
        add_employee_panel.add(dob_label);
        add_employee_panel.add(dob_field);
        add_employee_panel.add(file_label);
        add_employee_panel.add(file_field);
        add_employee_panel.add(add_employee_button);

        JPanel add_employee_wrapper = new JPanel();
        add_employee_wrapper.add(add_employee_panel);

        add_employee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(add_employee_wrapper);
                container.revalidate();
                container.repaint();
            }
        });

        add_employee_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int id = Integer.parseInt(id_field.getText());
                String name = name_field.getText();
                String dob = dob_field.getText();
                String filename = file_field.getText();

                Employee emp;
                try {
                    emp = new Employee(id, name, dob);
                } catch (ParseException ex) {
                    throw new RuntimeException(ex);
                }

                empList.add(emp);
                printEmployees();
                File file = new File(filename);
                if(!file.exists()){
                    try {
                        file.createNewFile();
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                }
                try {
                    saveEmployees(empList,file);
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
    }

    public void deleteEmployee(JFrame frame,JMenuItem delete_employee, Container container){
        JPanel delete_employee_panel = new JPanel();
        JLabel id_label = new JLabel("Enter Employee ID:");
        JTextField id_field = new JTextField(15);
        JButton delete_employee_button = new JButton("Submit");

        delete_employee_panel.add(id_label);
        delete_employee_panel.add(id_field);
        delete_employee_panel.add(delete_employee_button);

        JPanel delete_employee_wrapper = new JPanel();
        delete_employee_wrapper.add(delete_employee_panel);

        delete_employee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                container.removeAll();
                container.add(delete_employee_wrapper);
                container.revalidate();
                container.repaint();
            }
        });
    }

    public void listEmployees(JMenuItem list_employees, Container container){
        list_employees.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel list_employee_panel = new JPanel(new GridLayout(1,1));

                String[] columns = {"ID","Name","Date of Birth"};
                DefaultTableModel table_model = new DefaultTableModel(columns,0);
                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                for(int i = 0; i< empList.size();i++){
                    Object[] rows = {empList.get(i).getId(),
                    empList.get(i).getName(),sdf.format(empList.get(i).getDateOfBirth())};
                    table_model.addRow(rows);
                }
                JTable employee_table = new JTable(table_model);
                JScrollPane table_scroll = new JScrollPane(employee_table);

                list_employee_panel.add(table_scroll);

                container.removeAll();
                container.add(list_employee_panel);
                container.revalidate();
                container.repaint();
            }
        });
    }

    public void exit (JFrame frame,JMenuItem exit){
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame,"Goodbye!");
                frame.dispose();
            }
        });
    }

    public void printEmployees(){
        for(int i = 0; i<empList.size(); i++){
            System.out.printf("\nEmployee ID: %d",empList.get(i).getId());
            System.out.printf("\nEmployee Name: %s",empList.get(i).getName());
            System.out.printf("\nEmployee Date of Birth: %tF",empList.get(i).getDateOfBirth());
            System.out.println("\n-------------------------------------------------------------------------");
        }
    }

    public void saveEmployees(ArrayList<Employee> empList,File file) throws IOException {
        try(ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream
                (new FileOutputStream(file)))){
            for(int i = 0; i < empList.size();i++){
                out.writeObject(empList.get(i));
            }
        }catch (Exception e){
        }
    }

    public void readEmployees(File file){
        empList.clear();
        try(ObjectInputStream in = new ObjectInputStream(new BufferedInputStream
                (new FileInputStream(file)))) {
            while(true){
                empList.add((Employee) in.readObject());
            }
        }catch(EOFException | FileNotFoundException e){

        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
    public static void main(String[] args){
        Final f = new Final();
        File file = new File("employee.dat");
        if(!file.exists()){
            try {
                file.createNewFile();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        }
        f.readEmployees(file);
        f.printEmployees();
        f.menu();
    }
}