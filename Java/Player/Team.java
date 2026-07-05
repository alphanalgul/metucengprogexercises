
import java.util.Date;

public class Team {
    private String name;
    private String League;
    private String Founder;
    private Date founding_date;

    Team()
    {
        name = "Undefined";
        League = "Undefined";
        Founder = "Undefined";
        founding_date = new Date();
    }

    Team(String n, String l,String f,Date fd)
    {
        name = n;
        League = l;
        Founder = f;
        founding_date = fd;
    }
    public void setName(String name) {
        this.name = name;
    }

    public void setLeague(String league) {
        League = league;
    }

    public void setFounding_date(Date founding_date) {
        this.founding_date = founding_date;
    }

    public void setFounder(String founder) {
        Founder = founder;
    }

    public String getName() {
        return name;
    }

    public String getLeague() {
        return League;
    }

    public String getFounder() {
        return Founder;
    }

    public Date getFounding_date() {
        return founding_date;
    }

    public void printTeamDetails()
    {
        System.out.printf("\nTeam Name: %s",getName());
        System.out.printf("\nTeam League: %s",getLeague());
        System.out.printf("\nTeam Founder: %s",getFounder());
        System.out.printf("\nTeam Founding date: %tF",getFounding_date());
        System.out.println("\n---------------------------------------------------------------------------");
    }
}
