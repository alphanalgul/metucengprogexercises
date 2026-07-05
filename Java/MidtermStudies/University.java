
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class University
{
    ArrayList<Student> student_list;
    ArrayList<Instructor> instructor_list;

    /**
     * Default Constructor for the University Class
     */
    University()
    {
        student_list = new ArrayList<Student>();
        instructor_list = new ArrayList<Instructor>();
    }
    public  <E extends Comparable<E>> E min(E[] list){
        E min = list[0];
        for(int i = 0; i < list.length; i++)
        {
            if(min.compareTo(list[i]) > 0)
            {
                min = list[i];
            }
        }
        return min;
    }

    public <E extends Comparable<E>> E max(E[] list)
    {
        E max = list[0];
        for(int i = 0; i < list.length; i++)
        {
            if(max.compareTo(list[i]) < 0)
            {
                max = list[i];
            }
        }
        return max;
    }


    /**
     * Main function that provides the whole functionality of the program to the user
     * @param args arguments from the command line
     * @throws ParseException exception for the simple date formatter (sdf)
     */
    public static void main(String[] args) throws ParseException {
        University u = new University();

        Scanner user_input = new Scanner(System.in);

        int choice = 0;
        while (choice!=10)
        {
            System.out.println("\n-------------------------------------------------------");
            System.out.println("\nWelcome to the University system!");
            System.out.println("\n1. Add a Student");
            System.out.println("\n2. Delete a Student");
            System.out.println("\n3. Add Courses for a Student");
            System.out.println("\n4. Print all student details");
            System.out.println("\n5. Add an Instructor");
            System.out.println("\n6. Delete an Instructor");
            System.out.println("\n7. Add Courses for an instructor");
            System.out.println("\n8. Print all instructor details");
            System.out.println("\n9. Calculate total instructor salary");
            System.out.println("\n10. Exit");
            System.out.println("\n-----------------------------------");

            System.out.println("\nEnter your choice: ");
            choice = user_input.nextInt();
            user_input.nextLine();

            if(choice == 1)
            {
                System.out.println("\nEnter the student name: ");
                String name = user_input.nextLine();

                if(name.matches(".*[A-Za-z].*"))
                {
                    throw new StudentError("\nStudent name should only consist of letters!");
                }

                System.out.println("\nEnter the student surname:");
                String surname = user_input.nextLine();

                System.out.println("\nEnter student id:");
                int id = user_input.nextInt();
                user_input.nextLine();

                System.out.println("\nEnter student birthday:");
                String birthdate = user_input.nextLine();

                Student s = new Student(name,surname,id,birthdate);

                int size = u.getInstructor_list().size();

                if(!u.getInstructor_list().isEmpty()) {
                    Random rand = new Random();
                    int num = rand.nextInt(0, size + 1);
                    s.setAdvisor(u.getInstructor_list().get(num));
                }
                u.getStudent_list().add(s);

                System.out.printf("\nStudent %s successfully added.",name);

            }

            else if (choice == 2)
            {
                int check = 0;

                System.out.println("\nEnter the student id:");
                int id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < u.getStudent_list().size() ; i++)
                {
                    if(id == u.getStudent_list().get(i).getId())
                    {
                        System.out.printf("\nStudent %s successfully deleted.", u.getStudent_list().get(i)
                                .getName());

                        u.getStudent_list().remove(i);
                        check = 1;
                        break;
                    }
                }
                if(check == 0)
                {
                    throw new StudentError("Student Not Found!");
                }
            }

            else if (choice == 3)
            {
                int check = 0;

                System.out.println("\nEnter Student ID: ");
                int id = user_input.nextInt();
                user_input.nextLine();

                for(int j = 0; j < u.getStudent_list().size(); j++) {

                    if(id == u.getStudent_list().get(j).getId())
                    {
                        System.out.println("\nHow many courses? ");
                        int num_courses = user_input.nextInt();
                        user_input.nextLine();

                        for (int i = 0; i < num_courses; i++)
                        {
                            System.out.println("\nEnter the course name:");
                            String course_name = user_input.nextLine();

                            u.getStudent_list().get(j).getTaken_courses().add(course_name);
                        }
                        check = 1;
                        break;
                    }

                }
                if(check == 0)
                {
                    System.out.println("\nStudent Not Found!");
                }
            }

            else if (choice == 4)
            {
                for (int i = 0; i < u.getStudent_list().size(); i++){
                    u.getStudent_list().get(i).printDetails();
                }
            }

            else if (choice == 5)
            {
                System.out.println("\nEnter the instructor name: ");
                String name = user_input.nextLine();

                System.out.println("\nEnter the instructor surname:");
                String surname = user_input.nextLine();

                System.out.println("\nEnter instructor id:");
                int id = user_input.nextInt();
                user_input.nextLine();

                System.out.println("\nEnter instructor birthday:");
                String birthdate = user_input.nextLine();

                System.out.println("\nEnter instructor salary:");
                double salary = user_input.nextDouble();
                user_input.nextLine();

                Instructor i = new Instructor(name,surname,id,salary,birthdate);
                u.getInstructor_list().add(i);

                System.out.printf("\nInstructor %s successfully added.",name);

            }

            else if (choice == 6)
            {
                int check = 0;

                System.out.println("\nEnter the Instructor id:");
                int id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < u.getInstructor_list().size() ; i++)
                {
                    if(id == u.getInstructor_list().get(i).getId())
                    {
                        System.out.printf("\nInstructor %s successfully deleted.", u.getInstructor_list().get(i)
                                .getName());

                        u.getInstructor_list().remove(i);
                        check = 1;
                        break;
                    }
                }
                if(check == 0)
                {
                    System.out.println("\nInstructor Not Found!");
                }
            }

            else if (choice == 7)
            {
                int check = 0;

                System.out.println("\nEnter Instructor ID: ");
                int id = user_input.nextInt();
                user_input.nextLine();

                for(int j = 0; j < u.getInstructor_list().size(); j++) {

                    if(id == u.getInstructor_list().get(j).getId())
                    {
                        System.out.println("\nHow many courses? ");
                        int num_courses = user_input.nextInt();
                        user_input.nextLine();

                        for (int i = 0; i < num_courses; i++)
                        {
                            System.out.println("\nEnter the course name:");
                            String course_name = user_input.nextLine();

                            u.getInstructor_list().get(j).getTaught_courses().add(course_name);
                        }
                        check = 1;
                        break;
                    }

                }
                if(check == 0)
                {
                    System.out.println("\nInstructor Not Found!");
                }
            }

            else if (choice == 8)
            {
                for (int i = 0; i < u.getInstructor_list().size(); i++){
                    u.getInstructor_list().get(i).printDetails();
                }
            }

            else if (choice == 9)
            {
                double total_salary = 0;
                for (int i = 0; i < u.getInstructor_list().size() ; i++)
                {
                    total_salary += u.getInstructor_list().get(i).getSalary();
                }
                System.out.printf("\nTotal Instructor Salary: %.2f",total_salary);
            }

            else if (choice == 10)
            {
                System.out.println("\nByee!");
                break;
            }

            else {
                ;
            }
        }
    }

    public void setInstructor_list(ArrayList<Instructor> instructor_list) {
        this.instructor_list = instructor_list;
    }

    public void setStudent_list(ArrayList<Student> student_list) {
        this.student_list = student_list;
    }

    public ArrayList<Instructor> getInstructor_list() {
        return instructor_list;
    }

    public ArrayList<Student> getStudent_list() {
        return student_list;
    }


}