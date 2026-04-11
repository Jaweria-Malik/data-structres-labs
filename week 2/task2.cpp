#include<iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;   
};

class FullTimeEmployee : public Employee {
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary)
    {
        fixedSalary = salary;
    }

    double calculateSalary()
    {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int hours, double rate)
    {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{
    FullTimeEmployee fullEmp(50000);
    PartTimeEmployee partEmp(20, 500);

    cout << "FullTime EmployeeSalary: " <<
        fullEmp.calculateSalary() << endl;
    cout << "PartTime Employee alary: " <<
        partEmp.calculateSalary() << endl;

    return 0;
}
