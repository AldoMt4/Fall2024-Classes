#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string fullName;
    string dob;
    double baseSalary;
    double salary;

public:
    Employee(string name = "Unknown", string dateOfBirth = "01/01/2000", double base = 0.0)
        : fullName(name), dob(dateOfBirth), baseSalary(base), salary(0.0) {}

    virtual ~Employee() {}

    virtual void input() {
        cout << "Enter full name: ";
        getline(cin, fullName);
        cout << "Enter date of birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Enter base salary: ";
        cin >> baseSalary;
    }

    virtual void computeSalary() = 0; // Pure virtual function

    virtual void output() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Total Salary: $" << salary << endl;
    }

    // Getter for salary
    double getSalary() const {
        return salary;
    }
};

// Derived class: Office Employee
class OfficeEmployee : public Employee {
private:
    int workingDays;
    double allowance;

public:
    OfficeEmployee(string name = "Unknown", string dateOfBirth = "01/01/2000", double base = 0.0, int days = 0, double allow = 0.0)
        : Employee(name, dateOfBirth, base), workingDays(days), allowance(allow) {}

    void input() {
        Employee::input();
        cout << "Enter number of working days: ";
        cin >> workingDays;
        cout << "Enter allowance: ";
        cin >> allowance;
    }

    void computeSalary()  {
        salary = baseSalary + (workingDays * 150) + allowance;
    }

    void output() const {
        cout << "--- Office Employee ---" << endl;
        Employee::output();
        cout << "Working Days: " << workingDays << endl;
        cout << "Allowance: $" << allowance << endl;
    }
};

// Derived class: Management Employee
class ManagementEmployee : public Employee {
private:
    double positionCoefficient;
    double bonus;

public:
    ManagementEmployee(string name = "Unknown", string dateOfBirth = "01/01/2000", double base = 0.0, double coeff = 1.0, double bon = 0.0)
        : Employee(name, dateOfBirth, base), positionCoefficient(coeff), bonus(bon) {}

    void input() {
        Employee::input();
        cout << "Enter position coefficient: ";
        cin >> positionCoefficient;
        cout << "Enter bonus: ";
        cin >> bonus;
    }

    void computeSalary()  {
        salary = (baseSalary * positionCoefficient) + bonus;
    }

    void output() const  {
        cout << "--- Management Employee ---" << endl;
        Employee::output();
        cout << "Position Coefficient: " << positionCoefficient << endl;
        cout << "Bonus: $" << bonus << endl;
    }
};

// Derived class: Production Employee
class ProductionEmployee : public Employee {
private:
    int numProducts;

public:
    ProductionEmployee(string name = "Unknown", string dateOfBirth = "01/01/2000", double base = 0.0, int products = 0)
        : Employee(name, dateOfBirth, base), numProducts(products) {}

    void input()  {
        Employee::input();
        cout << "Enter number of products: ";
        cin >> numProducts;
    }

    void computeSalary()  {
        salary = baseSalary + (numProducts * 3);
    }

    void output() const  {
        cout << "--- Production Employee ---" << endl;
        Employee::output();
        cout << "Number of Products: " << numProducts << endl;
    }
};

// Main function
int main() {
    const int MAX_EMPLOYEES = 50;
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    while (true) {
        int choice;
        cout << "\n--- Employee Management System ---" << endl;
        cout << "1. Add Office Employee" << endl;
        cout << "2. Add Management Employee" << endl;
        cout << "3. Add Production Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Find Highest Salary and Lowest Salary" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        if (choice == 0) break;

        if (choice >= 1 && choice <= 3 && numEmployees < MAX_EMPLOYEES) {
            Employee* emp = nullptr;
            if (choice == 1) emp = new OfficeEmployee();
            else if (choice == 2) emp = new ManagementEmployee();
            else if (choice == 3) emp = new ProductionEmployee();

            emp->input();
            emp->computeSalary();
            employees[numEmployees++] = emp;
        } else if (choice == 4) {
            for (int i = 0; i < numEmployees; ++i) {
                employees[i]->output();
                cout << endl;
            }
        } else if (choice == 5) {
            double maxSalary = 0, minSalary = 1e9;
            Employee* highest = nullptr;
            Employee* lowest = nullptr;

            for (int i = 0; i < numEmployees; ++i) {
                double currentSalary = employees[i]->getSalary();
                if (currentSalary > maxSalary) {
                    maxSalary = currentSalary;
                    highest = employees[i];
                }
                if (currentSalary < minSalary) {
                    minSalary = currentSalary;
                    lowest = employees[i];
                }
            }

            cout << "\n--- Employee with Highest Salary ---" << endl;
            if (highest) highest->output();

            cout << "\n--- Employee with Lowest Salary ---" << endl;
            if (lowest) lowest->output();
        } else {
            cout << "Invalid choice or employee limit reached!" << endl;
        }
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < numEmployees; ++i) {
        delete employees[i];
    }

    return 0;
}
