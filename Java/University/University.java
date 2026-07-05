import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class University
{
    public ArrayList<Student> Student_List;
    public ArrayList<Instructor> Instructor_List;

    University()
    {
        Student_List = new ArrayList<Student>();
        Instructor_List = new ArrayList<Instructor>();
    }

    public void main(String[] args) throws ParseException {
        University u = new University();
        int choice = 0;
        Scanner user_input = new Scanner(System.in);
        while (choice!=12)
        {
            System.out.println("\n--------------------------------------------------------");
            System.out.println(" \nWelcome to the University System!");
            System.out.println(" \n1. Add a Student");
            System.out.println(" \n2. Delete a Student");
            System.out.println(" \n3. Add Student Courses");
            System.out.println(" \n4. Print Student Details");
            System.out.println(" \n5. Display All Students");
            System.out.println(" \n6. Add an Instructor");
            System.out.println(" \n7. Delete an Instructor");
            System.out.println(" \n8. Assign an Instructor to a Course");
            System.out.println(" \n9. Print Instructor Details");
            System.out.println(" \n10. Display All Instructors");
            System.out.println(" \n11. Calculate the Total Instructor Salary");
            System.out.println(" \n12. Exit");
            System.out.println("\n--------------------------------------------------------\n");

            System.out.println(" Enter a choice:");
            choice = user_input.nextInt();
            user_input.nextLine();

            if(choice == 1)
            {
                System.out.println(" Enter Student Name:");
                String name = user_input.nextLine();

                System.out.println(" Enter Student Surname:");
                String surname = user_input.nextLine();

                System.out.println(" Enter Student ID:");
                int id = user_input.nextInt();
                user_input.nextLine();

                System.out.println(" Enter Student CGPA:");
                double cgpa = user_input.nextDouble();
                user_input.nextLine();

                System.out.println(" Enter the Student Date of Birth: ");
                String dob = user_input.nextLine();
                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                Date birthdate = sdf.parse(dob);

                Student s = new Student(name,surname,id,birthdate,cgpa);
                Student_List.add(s);

            }
            else if (choice == 2)
            {
                int id;
                int check = 0;

                System.out.println("Enter the student id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Student_List.size() ; i++)
                {
                    if(Student_List.get(i).id == id)
                    {
                        Student_List.remove(i);
                        check = 1;
                        break;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Student Not Found!");
                }
            }
            else if (choice == 3)
            {
                int id;
                int check = 0;

                System.out.println("Enter the student id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Student_List.size() ; i++)
                {
                    if(Student_List.get(i).id == id)
                    {
                        Student_List.get(i).addCourse();
                        check = 1;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Student Not Found!");
                }
            }
            else if (choice == 4)
            {
                int check = 0;
                int id;
                System.out.println(" Enter the student id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Student_List.size(); i++)
                {
                    if(Student_List.get(i).id == id)
                    {
                        Student_List.get(i).printDetails();
                        check = 1;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Student Not Found!");
                }

            }
            else if (choice == 5)
            {
                System.out.println(" All the Students in this University:");
                for(int i = 0; i < Student_List.size(); i++)
                {
                    System.out.printf(" \nStudent %d: ",i+1);
                    Student_List.get(i).printDetails();
                }
            }
            else if (choice == 6)
            {
                System.out.println(" Enter Instructor Name:");
                String name = user_input.nextLine();

                System.out.println(" Enter Instructor Surname:");
                String surname = user_input.nextLine();

                System.out.println(" Enter Instructor ID:");
                int id = user_input.nextInt();
                user_input.nextLine();

                System.out.println(" Enter Instructor Salary:");
                double salary = user_input.nextDouble();
                user_input.nextLine();

                System.out.println(" Enter the Instructor Date of Birth: ");
                String dob = user_input.nextLine();
                SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
                Date birthdate = sdf.parse(dob);

                Instructor i = new Instructor(name,surname,id,birthdate,salary);
                Instructor_List.add(i);
            }
            else if (choice == 7)
            {
                int id;
                int check = 0;

                System.out.println("Enter the instructor id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Instructor_List.size() ; i++)
                {
                    if(Instructor_List.get(i).id == id)
                    {
                        Instructor_List.remove(i);
                        check = 1;
                        break;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Instructor Not Found!");
                }
            }
            else if (choice == 8)
            {
                int id;
                int check = 0;

                System.out.println("Enter the instructor id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Instructor_List.size() ; i++)
                {
                    if(Instructor_List.get(i).id == id)
                    {
                        Instructor_List.get(i).addCourse();
                        check = 1;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Instructor Not Found!");
                }
            }
            else if (choice == 9)
            {
                int check = 0;
                int id;
                System.out.println(" Enter the instructor id:");
                id = user_input.nextInt();
                user_input.nextLine();

                for(int i = 0; i < Instructor_List.size(); i++)
                {
                    if(Instructor_List.get(i).id == id)
                    {
                        Instructor_List.get(i).printDetails();
                        check = 1;
                    }
                }
                if(check == 0)
                {
                    System.out.println(" Instructor Not Found!");
                }
            }
            else if (choice == 10)
            {
                System.out.println(" All the Instructors in this University:");
                for(int i = 0; i < Instructor_List.size(); i++)
                {
                    System.out.printf(" \nInstructor %d: ",i+1);
                    Instructor_List.get(i).printDetails();
                }
            }
            else if (choice == 11)
            {
                double total_salary = 0;
                for(int i = 0; i < Instructor_List.size(); i++)
                {
                    total_salary = total_salary + Instructor_List.get(i).getSalary();

                }
                System.out.printf("\nTotal Salary of the instructors in this university is: %.2f",
                        total_salary);
            }
            else if (choice == 12)
            {
                System.out.println("\nByeeee!");
            }
            else
            {
                System.out.println("\nPlease enter a valid option!");
            }
        }
    }
}