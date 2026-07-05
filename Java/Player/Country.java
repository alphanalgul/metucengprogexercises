import java.util.Date;

public class Country {
    private String name;
    private String Founder;
    private String form_of_government;
    private String continent;
    private Date founding_date;

    Country()
    {
        name = "Undefined";
        Founder = "Undefined";
        form_of_government = "Undefined";
        continent = "Undefined";
        founding_date = new Date();
    }
    Country(String n, String f, String fog, String c, Date fd)
    {
        name = n;
        Founder = f;
        form_of_government = fog;
        continent = c;
        founding_date = fd;
    }

    public String getName() {
        return name;
    }

    public String getFounder() {
        return Founder;
    }

    public String getForm_of_government() {
        return form_of_government;
    }

    public Date getFounding_date() {
        return founding_date;
    }

    public String getContinent() {
        return continent;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setFounder(String founder) {
        Founder = founder;
    }

    public void setForm_of_government(String form_of_government) {
        this.form_of_government = form_of_government;
    }

    public void setContinent(String continent) {
        this.continent = continent;
    }

    public void setFounding_date(Date founding_date) {
        this.founding_date = founding_date;
    }

    public void printCountryDetails()
    {
        System.out.printf("\nCountry name: %s",getName());
        System.out.printf("\nCountry founder: %s",getFounder());
        System.out.printf("\nCountry form of government: %s", getForm_of_government());
        System.out.printf("\nCountry continent: %s", getContinent());
        System.out.printf("\nCountry founding date: %tF", getFounding_date());
        System.out.println("\n----------------------------------------------------------");
    }
}
