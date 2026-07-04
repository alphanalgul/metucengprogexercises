
#include<iostream>
#include "Restaurant.h"
#include<cstring>
using std::cout;

Restaurant::Restaurant():Business() {
  seat_number = 0;
  type = 0;
}

Restaurant::Restaurant(const char *r_name, int r_size, int num_seats)
: Business(r_name,r_size)
{
    seat_number = num_seats;
    type = 0;
}

void Restaurant::setSeatNum(int seat_num) {
    seat_number = seat_num;
}

int Restaurant::getSeatNum() const {
    return seat_number;
}

bool Restaurant::checkSuitability(int seat_num) const {
    return seat_number >= seat_num;
}

void Restaurant::printBusiness() {
    std::cout<<"\nBusiness Name: "<<getBusinessName()<<std::endl;
    std::cout<<"\nBusiness Size(in m2): "<<getBusinessSize()<<std::endl;
    std::cout<<"\nNumber of Employees: "<<getEmployeeCount()<<std::endl;
    std::cout<<"\nNumber of Seats: "<<seat_number<<std::endl;
    std::cout<<"\nType: Restaurant"<<std::endl;
}

void Restaurant::printBusinessEmployees() {
    std::cout<<"\nBusiness Name: "<<getBusinessName()<<std::endl;
    std::cout<<"\nBusiness Size(in m2): "<<getBusinessSize()<<std::endl;
    std::cout<<"\nNumber of Seats: "<<seat_number<<std::endl;
    std::cout<<"\nType: Restaurant"<<std::endl;
    std::cout<<"\nEmployees: "<<std::endl;
    if(getEmployeeCount()==0)
    {
        std::cout<<"\nNo Employees "<<std::endl;
    }
    int i = 0;
    while(i<getEmployeeCount())
    {
        employees[i].printEmployee();
        i++;
    }
}

int Restaurant::getType() {
    return 0;
}
