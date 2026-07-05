public class Rectangle extends GeometricObject
{
    private double length;
    private double height;

    Rectangle()
    {
        length = 0;
        height = 0;
    }

    Rectangle(double l, double h)
    {
        length = l;
        height = h;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getHeight() {
        return height;
    }

    public double getLength() {
        return length;
    }

    public double area()
    {
        return length * height;
    }
}
