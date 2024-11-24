#include <iostream>
#include <cstring>
using namespace std;

// Base class Person
class Person {
protected:
    char *Name;
    int YOB;
public:
    Person(const char *name = "Unnamed", int year = 2000) {
        Name = strdup(name);
        YOB = year;
    }
    virtual ~Person() {
        delete[] Name;
    }
    virtual void Input() = 0; // Pure virtual method
    virtual void Output() const = 0; // Pure virtual method
};

// Derived class Student
class Student : public Person {
private:
    char *ID;
    float GPA;
public:
    Student(const char *name = "Unnamed", const char *Identity = "0000", int year = 2000, float gpa = 0.0)
        : Person(name, year) {
        ID = strdup(Identity);
        GPA = gpa;
    }
    ~Student() {
        delete[] ID;
    }
    void Input()  {
        char buffer[100];
        cout << "Enter student's full name: ";
        cin.ignore();
        cin.getline(buffer, 100);
        delete[] Name;
        Name = strdup(buffer);

        cout << "Enter year of birth: ";
        cin >> YOB;

        cout << "Enter student ID: ";
        cin.ignore();
        cin.getline(buffer, 100);
        delete[] ID;
        ID = strdup(buffer);

        int x, y, z;
        cout << "Enter score of course 1: ";
        cin >> x;
        cout << "Enter score of course 2: ";
        cin >> y;
        cout << "Enter score of course 3: ";
        cin >> z;
        GPA = (x + y + z) / 3.0;
    }
    void Output() const {
        cout << "Student Name: " << Name << "\nYear of Birth: " << YOB
             << "\nID: " << ID << "\nGPA: " << GPA << endl;
    }
    float getGPA() const {
        return GPA;
    }
};

// Derived class Lecturer
class Lecturer : public Person {
private:
    char *ID;
    long Salary;
public:
    Lecturer(const char *name = "Unnamed", const char *Identity = "0000", int year = 2000, long salary = 0)
        : Person(name, year) {
        ID = strdup(Identity);
        Salary = salary;
    }
    ~Lecturer() {
        delete[] ID;
    }
    void Input() {
        char buffer[100];
        cout << "Enter lecturer's full name: ";
        cin.ignore();
        cin.getline(buffer, 100);
        delete[] Name;
        Name = strdup(buffer);

        cout << "Enter year of birth: ";
        cin >> YOB;

        cout << "Enter lecturer ID: ";
        cin.ignore();
        cin.getline(buffer, 100);
        delete[] ID;
        ID = strdup(buffer);

        int days;
        cout << "Enter number of working days: ";
        cin >> days;
        Salary = days * 40 * 8;
    }
    void Output() const {
        cout << "Lecturer Name: " << Name << "\nYear of Birth: " << YOB
             << "\nID: " << ID << "\nSalary: $" << Salary << endl;
    }
    long getSalary() const {
        return Salary;
    }
};

// Main program
int main() {
    const int MAX_PEOPLE = 50;
    Person* people[MAX_PEOPLE];
    int count = 0;

    char choice;
    do {
        if (count >= MAX_PEOPLE) {
            cout << "Maximum number of people reached.\n";
            break;
        }

        cout << "Enter 'S' for student or 'L' for lecturer: ";
        cin >> choice;

        if (choice == 'S' || choice == 's') {
            people[count] = new Student();
        } else if (choice == 'L' || choice == 'l') {
            people[count] = new Lecturer();
        } else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        people[count]->Input();
        count++;

        cout << "Do you want to add another person? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Finding student with highest GPA and lecturer with lowest salary
    Student* bestStudent = nullptr;
    Lecturer* lowestPaidLecturer = nullptr;

    for (int i = 0; i < count; i++) {
        if (Student* s = dynamic_cast<Student*>(people[i])) {
            if (bestStudent == nullptr || s->getGPA() > bestStudent->getGPA()) {
                bestStudent = s;
            }
        }
        if (Lecturer* l = dynamic_cast<Lecturer*>(people[i])) {
            if (lowestPaidLecturer == nullptr || l->getSalary() < lowestPaidLecturer->getSalary()) {
                lowestPaidLecturer = l;
            }
        }
    }

    // Output results
    cout << "\n--- Results ---\n";
    if (bestStudent) {
        cout << "Student with the highest GPA:\n";
        bestStudent->Output();
    } else {
        cout << "No students were entered.\n";
    }

    if (lowestPaidLecturer) {
        cout << "Lecturer with the lowest salary:\n";
        lowestPaidLecturer->Output();
    } else {
        cout << "No lecturers were entered.\n";
    }

    // Cleanup
    for (int i = 0; i < count; i++) {
        delete people[i];
    }

    return 0;
}
