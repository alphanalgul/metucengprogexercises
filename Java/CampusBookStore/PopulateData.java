package campusbookstore;

import java.util.ArrayList;
import java.util.Date;

/**
 * Class for creating data for CampusBookStore
 * @author Alphan Algül
 * @version 1.0
 */
public class PopulateData
{
    /**
     * Populating CampusBookStore Object with Student, Employee, BookItem and Reservation data
     * @param c CampusBookStore Object
     */
    PopulateData(CampusBookStore c)
    {
       //Creating Employees
       Employee e1 = new Employee(123456,"John","Doe"
       ,"10/01/1976","27/06/2025");
       Employee e2 = new Employee(2486971,"Isaac","Netero"
       ,"1/1/1915","19/05/1961");
       Employee e3 = new Employee(2526275,"Madara","Uchiha"
       ,"12/03/1654","05/01/1675");

       c.getEmpList().add(e1);
       c.getEmpList().add(e2);
       c.getEmpList().add(e3);

       //Creating BookItems
       BookItem b1 = new BookItem("Manga",5,60,c.randomEmployee());
       BookItem b2 = new BookItem("Novel",8,100,c.randomEmployee());
       BookItem b3 = new BookItem("Calculus",10,300,c.randomEmployee());


       //Creating Reservations
       TextbookReservation r1 = new TextbookReservation(addBookItem(b1),false, new Date());
       TextbookReservation r2 = new TextbookReservation(addBookItem(b2),false, new Date());
       TextbookReservation r3 = new TextbookReservation(addBookItem(b3),true, new Date());



       //Creating Students
       Student s1 = new Student(2455464,"Killua","Zoldyck",addReservation(r1),new Date());
       Student s2 = new Student(2001015,"John","Cena",addReservation(r2),new Date());
       Student s3 = new Student(1990656,"Lelouch","vi Britannia",addReservation(r3),new Date());

       c.getStudentList().add(s1);
       c.getStudentList().add(s2);
       c.getStudentList().add(s3);


    }

    /**
     * Helper function to help create a BookItem list
     * @param b BookItem Object
     * @return list of BookItem(s)
     */
    public ArrayList<BookItem> addBookItem (BookItem b)
    {
        ArrayList<BookItem> books = new ArrayList<BookItem>();
        books.add(b);
        return books;
    }

    /**
     * Helper function to help create a Reservation list
     * @param r Reservation Object
     * @return list of Reservation(s)
     */
    public ArrayList<TextbookReservation> addReservation (TextbookReservation r)
    {
        ArrayList<TextbookReservation> reservations = new ArrayList<TextbookReservation>();
        reservations.add(r);
        return reservations;
    }

}
