public class Main
{
    public static void main(String[] args)
    {
        Rectangle r = new Rectangle(10,5);
        Circle c = new Circle(5);

        System.out.printf("\nArea of the Rectangle: %.2f",r.area());
        System.out.printf("\nArea of the Circle: %.2f",c.area());
    }
}
