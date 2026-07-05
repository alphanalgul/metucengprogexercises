public class Circle extends GeometricObject
{
    private double radius;

    Circle()
    {
        radius = 0;
    }

    Circle(double r)
    {
        radius = r;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double area()
    {
        return  (3.14) * radius * radius;
    }
}
