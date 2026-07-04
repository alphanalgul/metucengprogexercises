#include<iostream>
#include<cstring>
#include "student.h"
using std::cout;

Student::Student(){
    int size_name = strlen("Mot Provided");
    strncpy(name,"Not Provided",size_name);
    name[size_name] = '\0';

    student_number = 0;
    cgpa = 0.0;
};

void Student::createStudent(const char *sname, int student_no, float scgpa) {
    strncpy(name, sname, 49);
    name[49] = '\0';

    student_number = student_no;
    cgpa = scgpa;
}

void Student::printStudent() {
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Student Number: "<<student_number<<std::endl;
    std::cout<<"CGPA: "<<cgpa<<std::endl;
}
