以下是根据你要学习的内容设计的一系列算法题：

### 函数与作用域相关题目

#### 题目 1：值传递与引用传递

**题目描述**：
编写一个函数 `swap`，用于交换两个整数的值。分别实现值传递和引用传递的版本，并在 `main` 函数中调用这两个版本，观察交换结果。










**代码示例**：

```cpp
#include <iostream>

// 值传递交换函数
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 引用传递交换函数
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Before swap by value: x = " << x << ", y = " << y << std::endl;
    swapByValue(x, y);
    std::cout << "After swap by value: x = " << x << ", y = " << y << std::endl;

    std::cout << "Before swap by reference: x = " << x << ", y = " << y << std::endl;
    swapByReference(x, y);
    std::cout << "After swap by reference: x = " << x << ", y = " << y << std::endl;

    return 0;
}
```

#### 题目 2：static 关键字的使用

**题目描述**：
编写一个函数 `countCalls`，该函数使用 `static` 变量来记录函数被调用的次数，并在每次调用时输出调用次数。

**代码示例**：

```cpp
#include <iostream>

void countCalls() {
    static int callCount = 0;
    callCount++;
    std::cout << "This function has been called " << callCount << " times." << std::endl;
}

int main() {
    for (int i = 0; i < 5; i++) {
        countCalls();
    }
    return 0;
}
```

### 面向对象编程相关题目

#### 题目 3：类的基本使用

**题目描述**：
设计一个 `Rectangle` 类，包含两个成员变量 `length` 和 `width`，以及成员函数 `getArea` 用于计算矩形的面积，构造函数用于初始化矩形的长和宽。在 `main` 函数中创建 `Rectangle` 对象并调用 `getArea` 函数。









**代码示例**：

```cpp
#include <iostream>

class Rectangle {
private:
    double length;
    double width;
public:
    // 构造函数
    Rectangle(double l, double w) : length(l), width(w) {}

    // 计算面积的成员函数
    double getArea() {
        return length * width;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "The area of the rectangle is: " << rect.getArea() << std::endl;
    return 0;
}
```

#### 题目 4：封装与访问控制

**题目描述**：
设计一个 `Person` 类，包含私有成员变量 `name` 和 `age`，提供公共的成员函数 `setName`、`setAge`、`getName` 和 `getAge` 用于设置和获取这些信息。在 `main` 函数中创建 `Person` 对象并进行信息的设置和获取。








**代码示例**：

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;
public:
    void setName(const std::string& n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person p;
    p.setName("Alice");
    p.setAge(25);
    std::cout << "Name: " << p.getName() << ", Age: " << p.getAge() << std::endl;
    return 0;
}
```

### 基础内存管理相关题目

#### 题目 5：new/delete 操作符的使用

**题目描述**：
使用 `new` 操作符动态分配一个整数数组，数组大小由用户输入。然后将数组元素初始化为 1 到数组大小的值，最后使用 `delete[]` 释放内存。








**代码示例**：

```cpp
#include <iostream>

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // 动态分配数组
    int* arr = new int[size];

    // 初始化数组元素
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // 输出数组元素
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 释放内存
    delete[] arr;

    return 0;
}
```

#### 题目 6：浅拷贝与深拷贝问题

**题目描述**：
设计一个 `String` 类，包含一个字符指针 `str` 用于存储字符串。实现构造函数、析构函数、拷贝构造函数（深拷贝）。在 `main` 函数中创建对象并进行拷贝操作，验证深拷贝的效果。






**代码示例**：

```cpp
#include <iostream>
#include <cstring>

class String {
private:
    char* str;
public:
    // 构造函数
    String(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // 析构函数
    ~String() {
        delete[] str;
    }

    // 深拷贝构造函数
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    void print() {
        std::cout << str << std::endl;
    }
};

int main() {
    String s1("Hello");
    String s2(s1);
    s1.print();
    s2.print();
    return 0;
}
```

---
