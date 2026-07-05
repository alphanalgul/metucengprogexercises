import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args) throws ParseException {
        Scanner user_input = new Scanner(System.in);

        System.out.println("\nEnter student name:");
        String name = user_input.nextLine();

        System.out.println("\nEnter student surname:");
        String surname = user_input.nextLine();

        System.out.println("\nEnter student age:");
        int age = user_input.nextInt();
        user_input.nextLine();

        System.out.println("\nEnter student Date of Birth:");
        String dob = user_input.nextLine();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date db = sdf.parse(dob);

        System.out.println("\nEnter student university:");
        String university = user_input.nextLine();

        System.out.println("\nEnter student CGPA:");
        double cgpa = user_input.nextDouble();

        Student s1 = new Student(name,surname,age,db,university,cgpa);
        s1.printDetails();

        s1.breathe();
        s1.eat();
        s1.drink();
        s1.walk();
        s1.study();
        s1.fail();
        s1.pass();
    }
}
