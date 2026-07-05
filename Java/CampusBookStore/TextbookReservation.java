package campusbookstore;

import java.util.ArrayList;
import java.util.Date;

/**
 * Represents a reservation that a student has made
 * Each reservation has a reservationDate( the date that the reservation has been made on)
 * a list of BookItems reserved
 * and a payment status representing whether the reservation has been paid or not
 * @author Alphan Algül
 * @version 1.0
 */
public class TextbookReservation {
    private Date reservationDate;
    private ArrayList<BookItem> bookList;
    private boolean paidStatus;


    /**
     * Default constructor for creating a Reservation Object
     * if no parameters are entered, this constructor will be used
     */
    TextbookReservation()
    {
        this.reservationDate = null;
        this.bookList = new ArrayList<BookItem>();
        this.paidStatus = false;
    }


    /**
     * Parametrized constructor for creating a Reservation Object with the following fields:
     * a list of Book Items and a payment status for storing whether a payment has been made for a
     * Reservation or not
     * @param b list of Book Items that the Reservation was made for
     * @param pS payment status of the Reservation
     */
    TextbookReservation(ArrayList<BookItem> b,boolean pS)
    {
        this.bookList = b;
        this.paidStatus = pS;
    }

    /**
     * Parametrized constructor for creating a Reservation Object with the following fields:
     * a list of Book Items and a payment status for storing whether a payment has been made for a
     * reservation or not and the reservation date
     * @param b list of Book Items that the Reservation was made for
     * @param pS payment status of the Reservation
     * @param rD for storing the date of the Reservation
     */
    TextbookReservation(ArrayList<BookItem> b,boolean pS,Date rD)
    {
        this.reservationDate = rD;
        this.bookList = b;
        this.paidStatus = pS;
    }

    //Setters()
    public void setReservationDate(Date reservationDate) {
            this.reservationDate = reservationDate;
        }


    public void setBookList(ArrayList<BookItem> bookList) {
        this.bookList = bookList;
    }

    public void setPaidStatus(boolean paidStatus) {
        this.paidStatus = paidStatus;
    }

    //Getters()
    public Date getReservationDate() {
        return reservationDate;
    }

    public ArrayList<BookItem> getBookList() {
        return bookList;
    }

    public boolean getPaidStatus()
    {
        return paidStatus;
    }

    /**
     * Method that calculates the total cost of the Reservation
     * (sum of the costs of all the Book Items within the Reservation)
     * @return total cost of the reservation
     */
    public double totalReservationCost()
    {
        double total = 0;
        for(int i = 0; i < bookList.size();i++)
        {
            total = total + bookList.get(i).totalCost();
        }
        return total;
    }

    /**
     * Method to help display Reservation details
     */
    void printReservation()
    {

        System.out.printf("%nReservation Date: %tF%n", reservationDate);

        if(paidStatus) {
            System.out.printf("Payment Status: Paid%n");
        }
        if(!paidStatus) {
            System.out.printf("Payment Status: Not Paid%n");
        }
        System.out.println("\n-----------------------------------------");
        System.out.printf("Book Items Reserved:%n");
        for(int i = 0; i < bookList.size(); i++)
        {
            bookList.get(i).printBookItem();
        }
    }
}
