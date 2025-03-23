#include<iostream>
#include<string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string n, int a): name(n), age(a) {}
    void displayInfo() {
        std::cout<< "Name: " << name << ", age: " << age <<std::endl;
    }
};

class Student : public Person {
private:
    std::string studentId;

public:
    Student(std::string n, int a,std::string id) : Person(n, a), studentId(id) {}
    void displayStudentInfo() {
        displayInfo();
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Person person("jack", 20);
    person.displayInfo();
  
    Student student("Chale", 23, "108420");
    student.displayStudentInfo();

    return 0;

}