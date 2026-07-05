import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        Generic_List<String> list = new Generic_List<>();

        list.addItem("abc");
        list.addItem("def");

        System.out.printf("First item of the list: %s", list.getItem(0));
    }
}