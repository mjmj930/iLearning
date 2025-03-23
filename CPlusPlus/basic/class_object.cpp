#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;

public:
    Student(std::string n, int i) : name(n), id(i) {
        std::cout << "Student object created,name: " << name << ", ID: " << id << std::endl;
    }

    Student(const Student& other) : name(other.name), id(other.id) {}

    void printInfo() const {
        std::cout << "Name: " << name << " ID: " << id << std::endl;
    }

    // 添加 setter 方法用于修改 name
    void setName(const std::string& n) {
        name = n;
    }

    // 添加 setter 方法用于修改 id
    void setId(int i) {
        id = i;
    }

    ~Student() {
    }
};

int main() {
    // 测试用例
    Student s1("Alice", 1001);    // 原始对象
    Student s2(s1);               // 拷贝构造

    std::cout << "Original Student s1:" << std::endl;
    s1.printInfo();

    std::cout << "\nCopied Student s2:" << std::endl;
    s2.printInfo();

    // 修改 s2 的 id 值
    s2.setId(1003);

    std::cout << "\nAfter modifying s2's id:" << std::endl;
    std::cout << "Student s1:" << std::endl;
    s1.printInfo();
    std::cout << "Student s2:" << std::endl;
    s2.printInfo();

    return 0;
}    