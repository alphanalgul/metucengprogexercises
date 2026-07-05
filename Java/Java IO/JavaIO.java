import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;
import java.io.*;

public class JavaIO implements Serializable
{
    public static class Student implements Serializable{
        private int id;
        private String name;
        private Date dob;

        Student(){
            id = 0;
            name = "Undefined";
            dob = new Date();
        }

        Student(int i, String n, String db) throws ParseException {
            id = i;
            name = n;
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            dob = sdf.parse(db);
        }

        public int getId() {
            return id;
        }

        public String getName() {
            return name;
        }

        public Date getDob() {
            return dob;
        }
    }

    public ArrayList <Student> students;

    JavaIO(){
        students = new ArrayList<Student>();
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

    public void addStudent() throws ParseException {
        Scanner user_input = new Scanner(System.in);

        System.out.println("\nEnter student ID:");
        int id = user_input.nextInt();
        user_input.nextLine();

        System.out.println("\nEnter the student name:");
        String name = user_input.nextLine();

        System.out.println("\nEnter student date of birth:");
        String dob = user_input.nextLine();

        Student s = new Student(id, name, dob);
        students.add(s);
    }

    public void printStudents(){
        for(int i = 0; i<students.size(); i++){
            System.out.printf("\nStudent ID: %d",students.get(i).getId());
            System.out.printf("\nStudent Name: %s",students.get(i).getName());
            System.out.printf("\nStudent Date of Birth: %tF\n",students.get(i).getDob());
        }
    }

    public void saveStudentsToFile(ArrayList<Student> s) throws FileNotFoundException {
        File filename = new File("student_no_serial.dat");
        SimpleDateFormat sdf= new SimpleDateFormat("dd/MM/yyyy");
        try(DataOutputStream out = new DataOutputStream(new BufferedOutputStream
                (new FileOutputStream(filename)))){
            for(int i = 0; i < s.size(); i++){
                out.writeInt(s.get(i).getId());
                out.writeUTF(s.get(i).getName());
                out.writeUTF(sdf.format(s.get(i).getDob()));
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void readStudentsFromFile(File filename) throws FileNotFoundException {
        try(DataInputStream in = new DataInputStream(new BufferedInputStream
                (new FileInputStream(filename)))){

            while(true){
                int id = in.readInt();
                String name = in.readUTF();
                String dob = in.readUTF();

                Student s = new Student(id,name,dob);
                students.add(s);
            }

        }catch (EOFException e){

        }catch (IOException | ParseException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveStudentsToFileWithSerialisation(ArrayList<Student> s){

        File filename = new File("student.dat");
        try(ObjectOutputStream out = new ObjectOutputStream
                (new BufferedOutputStream(new FileOutputStream(filename)))){

            for(int i = 0; i < s.size(); i++){
                out.writeObject(s.get(i));
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void readStudentsFromFileWithDeserialisation(File filename){

        students.clear();
        try(ObjectInputStream in = new ObjectInputStream(new BufferedInputStream
                (new FileInputStream(filename)))){

            while(true) {

                Student s = (Student) in.readObject();
                students.add(s);
            }

        } catch (EOFException e) {

        }catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) throws ParseException, IOException {
        Scanner user_input = new Scanner(System.in);
        JavaIO j = new JavaIO();
        int choice = 0;

        File no_serial_file = new File("student_no_serial.dat");
        if(!no_serial_file.exists()){
            no_serial_file.createNewFile();
        }


        File file = new File("student.dat");
        if(!file.exists()){
            file.createNewFile();
        }

        //j.readStudentsFromFileWithDeserialisation(new File("student.dat"));
        j.readStudentsFromFile(new File("student_no_serial.dat"));
        while (choice != 3) {
            System.out.println("\n1.Add Student");
            System.out.println("\n2.Print Students");
            System.out.println("\n3.Exit");
            System.out.println("\nEnter a choice:");
            choice = user_input.nextInt();
            user_input.nextLine();

            if(choice == 1){
                j.addStudent();
                j.saveStudentsToFileWithSerialisation(j.students);
                j.saveStudentsToFile(j.students);
            }

            else if(choice == 2){
                j.printStudents();
            }

            else if (choice == 3){
                System.out.println("\nByeeee");
            }

            else{
                System.out.println("\nPlease enter a valid choice");
            }
        }
    }
}