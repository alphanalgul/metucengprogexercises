import java.util.Scanner;

public class Password
{
    private String password;

    Password()
    {
        password = "Undefined";
    }
    Password(String pwd)
    {
        password = pwd;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPassword() {
        return password;
    }

    public void createPassword()
    {
        int check = 0;
        Scanner user_input = new Scanner(System.in);

        while(check != 1) {
            System.out.println("\nEnter a password:");
            String pwd = user_input.nextLine();

            try {
                if (pwd.length() < 7) {
                    throw new PasswordException("\nPassword is too short!");
                }
                if (!pwd.matches(".*[A-Za-z].*")) {
                    throw new PasswordException("\nPassword does not contain any letters!");
                }
                if (!pwd.matches(".*[0-9].*")) {
                    throw new PasswordException("\nPassword does not contain any numbers!");
                }
                System.out.printf("\nPassword Recorded. Your password is %s", pwd);
                check = 1;
            } catch (PasswordException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args)
    {
        Password p = new Password();
        p.createPassword();
    }
}
