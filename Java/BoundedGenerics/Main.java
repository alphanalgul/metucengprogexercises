public class Main
{
    public static <E extends Comparable<E>> E min(E[] list)
    {
        E min = list[0];
        for(int i = 0; i< list.length; i++)
        {
            if(list[i].compareTo(min) < 0)
            {
                min = list[i];
            }
        }
        return min;
    }
    public static <E extends Comparable<E> > E max(E[] list)
    {
        E max = list[0];
        for(int i = 0; i< list.length; i++)
        {
            if(list[i].compareTo(max) > 0)
            {
                max = list[i];
            }
        }
        return max;
    }
    public static void main(String[] args)
    {
        Integer[] list = {1,2,3,4,5};
        System.out.printf("\nThe minimum element in the list is: %d", min(list));
        System.out.printf("\nThe minimum element in the list is: %d", max(list));
    }
}