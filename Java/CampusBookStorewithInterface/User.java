package campusbookstore;

import java.util.Date;

/**
 * @author Alphan Algül
 * @version 1.0
 * User abstract class that stores id, name and dateOfBirth
 */
public abstract class User {
    private int id;
    private String name;
    private Date dateOfBirth;

    //Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDateOfBirth(Date dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    //Getters
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
