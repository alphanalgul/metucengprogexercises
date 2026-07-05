import java.text.ParseException;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws ParseException {
        Scanner user_input = new Scanner(System.in);

        System.out.println("\nEnter Player name: ");
        String name = user_input.nextLine();

        System.out.println("\nEnter player surname: ");
        String surname = user_input.nextLine();

        System.out.println("\nEnter player age: ");
        int age = user_input.nextInt();
        user_input.nextLine();

        Player p1 = new Player(name,surname,age);

        p1.addCountry();
        p1.addTeam();

        p1.printPlayerDetails();
    }
}