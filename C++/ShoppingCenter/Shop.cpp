
#include<iostream>
#include<cstring>
#include "Shop.h"
using std::cout;

Shop::Shop() {
    char * b_name = new char[strlen("Undefined") + 1];
    strcpy(b_name,"Undefined");
    setBusinessName(b_name);
    delete[] b_name;
    setBusinessSize(-1);
    employeeCount = 0;
    s = None;
}

Shop::Shop(char *s_name, int s_size, int stype) : Business(s_name, s_size) {
    employeeCount = 0;
    type = stype;

    if (stype == 1) {
        s = Clothing;
    }
    else if (stype == 2) {
        s = Technology;
    }
    else if (stype == 3) {
        s = Accessories;
    }
    else if (stype == 4) {
        s = Beauty;
    }
    else {
        s = None;
        type = -1;
    }
}

void Shop::setShopType(int stype) {
    type = stype;
    if(stype == 1)
    {
        s = Clothing;
    }
    if(stype == 2)
    {
        s = Technology;
    }
    if(stype == 3)
    {
        s = Accessories;
    }
    if(stype == 4)
    {
        s = Beauty;
    }
    if(stype == -1)
    {
        s = None;
    }
}

Shop::shopType Shop::getShopType() {
    return s;
}



void Shop::printBusiness() {
    std::cout<<"\nBusiness Name: "<<getBusinessName()<<std::endl;
    std::cout<<"\nBusiness Size: "<<getBusinessSize()<<std::endl;
    std::cout<<"\nNumber of Employees: "<<employeeCount<<std::endl;
    std::cout<<"\nShop Type:"<<std::endl;
    if (getShopType() == Clothing)
        std::cout << "Clothing" << std::endl;
    else if (getShopType() == Technology)
        std::cout << "Technology" << std::endl;
    else  if (getShopType() == Accessories)
        std::cout << "Accessories" << std::endl;
    else if (getShopType() == Beauty)
        std::cout << "Beauty" << std::endl;
    else
        std::cout << "None" << std::endl;
}

void Shop::printBusinessEmployees() {
    std::cout<<"\nBusiness Name: "<<getBusinessName()<<std::endl;
    std::cout<<"\nBusiness Size: "<<getBusinessSize()<<std::endl;
    std::cout<<"\nShop Type:"<<std::endl;
    if (getShopType() == Clothing)
        std::cout << "Clothing" << std::endl;
    else if (getShopType() == Technology)
        std::cout << "Technology" << std::endl;
    else  if (getShopType() == Accessories)
        std::cout << "Accessories" << std::endl;
    else if (getShopType() == Beauty)
        std::cout << "Beauty" << std::endl;
    else
        std::cout << "None" << std::endl;

    std::cout<<"\nEmployees: "<<std::endl;
    int i = 0;
    while(i<employeeCount)
    {
        employees[i].printEmployee();
        i++;
    }
}

int Shop::getType() {
    if(s == None)
    {
        return -1;
    }
    else if(s == Clothing)
    {
       return 1;
    }
    else if(s == Technology)
    {
      return 2;
    }
    else if(s == Accessories)
    {
       return 3;
    }
    else if(s == Beauty)
    {
      return 4;
    }
    else
    {
        return -1;
    }
}
