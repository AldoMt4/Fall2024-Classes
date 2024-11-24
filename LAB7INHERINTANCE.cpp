#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string Name;
    int YOB; // Year of Birth
public:
    Person(string name = "Peter", int year = 2000) : Name(name), YOB(year) {}

    virtual ~Person() {} // Virtual destructor for proper cleanup in derived classes

    virtual void Input() {
        cout << "Enter full name: ";
        getline(cin, Name); // Safely read a full line of input
        cout << "Enter year of birth: ";
        cin >> YOB;
        cin.ignore(); // Clear newline from input buffer
    }

    virtual void Output() const {
        cout << "Person, Full name: " << Name << endl;
        cout << "Year of Birth: " << YOB << endl;
    }
};

class Student : public Person {
    string ID;
    float GPA;
public:
    Student(string name = "Peter", string identity = "0000", int year = 2000, int score = 0) 
        : Person(name, year), ID(identity), GPA(score) {}

    void Input()  {
        Person::Input();
        cout << "Enter ID: ";
        getline(cin, ID);
        int x, y, z;
        cout << "Enter score of course 1: ";
        cin >> x;
        cout << "Enter score of course 2: ";
        cin >> y;
        cout << "Enter score of course 3: ";
        cin >> z;
        cin.ignore(); // Clear newline from input buffer
        ComputeGPA(x, y, z);
    }

    void Output() const  {
        cout << "Student, Full name: " << Name << endl;
        cout << "Year of Birth: " << YOB << endl;
        cout << "ID: " << ID << endl;
        cout << "GPA: " << GPA << endl;
    }

    void ComputeGPA(int x, int y, int z) {
        GPA = (x + y + z) / 3.0f; // Compute GPA as a float
    }
};

class Lecturer : public Person {
    string ID;
    float Salary;
public:
    Lecturer(string name = "Peter", string identity = "0000", int year = 2000, float sal = 0.0f) 
        : Person(name, year), ID(identity), Salary(sal) {}

    void Input()  {
        Person::Input();
        cout << "Enter ID: ";
        getline(cin, ID);
        int days;
        cout << "Enter the number of working days: ";
        cin >> days;
        cin.ignore(); // Clear newline from input buffer
        ComputeSalary(days);
    }

    void Output() const {
        cout << "Lecturer, Full name: " << Name << endl;
        cout << "Year of Birth: " << YOB << endl;
        cout << "ID: " << ID << endl;
        cout << "Salary: $" << Salary << endl;
    }

    void ComputeSalary(int days) {
        Salary = 40.0f * days * 8; // $40 per hour, 8 hours per day
    }
};

int main() {
    cout << "---- Student Example ----" << endl;
    Student s1;
    s1.Input();
    s1.Output();

    cout << "\n---- Lecturer Example ----" << endl;
    Lecturer l1;
    l1.Input();
    l1.Output();

    return 0;
}