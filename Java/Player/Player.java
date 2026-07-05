import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Player {
    private String name;
    private String surname;
    private int age;
    private Country country;
    private Team team;

    Player()
    {
        name = "Undefined";
        surname = "Undefined";
        age = 0;
        country = new Country();
        team = new Team();
    }

    Player(String n, String sn, int a)
    {
        name = n;
        surname = sn;
        age = a;
        country = new Country();
        team = new Team();
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setCountry(Country country) {
        this.country = country;
    }

    public void setTeam(Team team) {
        this.team = team;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }

    public Country getCountry() {
        return country;
    }

    public Team getTeam() {
        return team;
    }

    public void addCountry() throws ParseException {
        Scanner user_input = new Scanner(System.in);

        System.out.println("\nEnter country name:");
        String c_name = user_input.nextLine();

        System.out.println("\nEnter country Founder:");
        String c_founder = user_input.nextLine();

        System.out.println("\nEnter country form of government:");
        String c_government = user_input.nextLine();

        System.out.println("\nEnter country continent:");
        String c_continent = user_input.nextLine();

        System.out.println("\nEnter country founding date:");
        String founding_date = user_input.nextLine();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date fd = sdf.parse(founding_date);

        country = new Country(c_name,c_founder,c_government,c_continent,fd);

    }

    public void addTeam() throws ParseException {
        Scanner user_input = new Scanner(System.in);

        System.out.println("\nEnter the team name:");
        String t_name = user_input.nextLine();

        System.out.println("\nEnter the league:");
        String t_league = user_input.nextLine();

        System.out.println("\nEnter the team founder:");
        String t_founder = user_input.nextLine();

        System.out.println("\nEnter team founding date:");
        String t_founding_date = user_input.nextLine();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date fd = sdf.parse(t_founding_date);

        team = new Team(t_name,t_league,t_founder,fd);
    }

    public void printPlayerDetails(){
        System.out.println("\nPersonal Information:");
        System.out.printf("\nPlayer Name: %s", getName());
        System.out.printf("\nPlayer Surname: %s",getSurname());
        System.out.printf("\nPlayer Age: %d",getAge());;
        System.out.println("\n----------------------------------------------------------");

        System.out.println("\nCountry Information:");
        country.printCountryDetails();

        System.out.println("\nTeam Information:");
        team.printTeamDetails();
    }
}
