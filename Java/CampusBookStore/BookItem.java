package campusbookstore;

/**
 * Represents a Book Item that can be reserved
 * Each book item has a type(Novel, Physics, Calculus etc.)
 * a quantity
 * a price
 * and an assigned employee
 * @author Alphan Algül
 * @version 1.0
 */
public class BookItem {
    private String type;
    private int quantity;
    private int price;
    private Employee assigned;

    /**
     * Default constructor for creating a Book Item Object
     * If no parameters are entered, this constructor will be used
     */
    BookItem()
    {
        this.type = "Undefined";
        this.quantity = 0;
        this.price = 0;
        this.assigned = null;
    }

    /**
     * Parametrized constructor that creates a Book Item Object with the following fields:
     * type, quantity, price
     * @param t type of the Book Item
     * @param q quantity of the Book Item
     * @param p price of the Book Item
     */
    BookItem(String t, int q, int p)
    {
        this.type = t;
        this.quantity = q;
        this.price = p;
    }

    /**
     * Parametrized constructor that creates a Book Item Object with the following fields:
     * type, quantity, price, assigned employee
     * @param t type of the Book Item
     * @param q quantity of the Book Item
     * @param p price of the Book Item
     * @param e which employee was assigned to the Book Item
     */
    BookItem(String t, int q, int p, Employee e)
    {
        this.type = t;
        this.quantity = q;
        this.price = p;
        this.assigned = e;
    }

    //Setters()
    public void setType(String type) {
        this.type = type;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setAssigned(Employee assigned) {
        this.assigned = assigned;
    }

    //Getters()
    public String getType() {
        return type;
    }

    public int getQuantity() {
        return quantity;
    }

    public int getPrice() {
        return price;
    }

    public Employee getAssigned() {
        return assigned;
    }

    /**
     * Method for calculating the total cost of a Book Item
     * @return total cost of the Book Item
     */
    double totalCost()
    {
        return price * quantity;
    }

    /**
     * Method to help display Book Item Details
     */
    void printBookItem()
    {
        System.out.printf("Book Item Type : %s%n", type);
        System.out.printf("Book Item Quantity: %d%n",quantity);
        System.out.printf("Book Item Price: %d%n",price);
        System.out.printf("Book Item Assigned Employee: %s %s%n ", assigned.getName(),assigned.getSurname());
        System.out.println("\n---------------------------");
    }
}
