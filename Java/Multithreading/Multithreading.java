
public class Multithreading
{
    public static class Addition extends Thread{
        @Override
        public void run() {
            int result = 3 + 5;
            System.out.printf("\nAddition result is %d",result);
        }
    }

    public static class Subtraction extends Thread{
        @Override
        public void run() {
            int result = 3 -5;
            System.out.printf("\nSubtraction result is %d",result);
        }
    }

    public static class Multiplication implements Runnable{

        @Override
        public void run() {
            int multiplication = 3 * 5;
            System.out.printf("\nThe multiplication result is %d",multiplication);
        }
    }

    public static class Division implements Runnable{

        @Override
        public void run() {
            double division = (double) 3 / 5;
            System.out.printf("\nThe division result is %.2f",division);
        }
    }

    public static void main(String[] args){

        //Extend Thread Threads
        Thread t1 = new Addition();
        Thread t2 = new Subtraction();

        t2.setPriority(Thread.NORM_PRIORITY);
        t1.setPriority(Thread.MIN_PRIORITY);


        //Implement Runnable Threads
        Thread t3 = new Thread(new Multiplication());
        t3.setPriority(Thread.MAX_PRIORITY);
        Thread t4 = new Thread(new Division());
        t4.setPriority(Thread.NORM_PRIORITY);

        t1.start();
        t2.start();
        t3.start();
        t4.start();

    }
}