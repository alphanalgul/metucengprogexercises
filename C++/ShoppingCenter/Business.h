
#ifndef INC_2584639_BUSINESS_H
#define INC_2584639_BUSINESS_H
#include "Employee.h"
class Business
{
private:
    char *name;
    int size;
protected:
    int employeeCount;
    Employee employees[20];
    int type;
public:
    Business();
    Business(const char *name,int size);
    Business(const Business &b);
    virtual ~Business();
    Business& operator=(const Business &b);
    void setBusinessName(char const *name);
    void setBusinessSize(int size);
    char * getBusinessName();
    int getBusinessSize();
    int  getEmployeeCount();
    void addEmployee(Employee e);
    virtual void printBusiness();
    virtual void printBusinessEmployees();
    void searchByName(char *keyword);
    virtual int getType();
};
#endif //INC_2584639_BUSINESS_H
