#include<iostream>

class MyVector {
private:
    int* arr;       // 存储元素
    int capacity;   // 总容量
    int size;       // 当前元素数量

public:
    MyVector() : arr(nullptr), capacity(0), size(0) {}

    // 拷贝构造函数
    MyVector(const MyVector& other) : capacity(other.capacity),size(other.size) {
        arr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // 赋值运算符重载
    MyVector& operator = (const MyVector& other) {
        if(this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i=0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void push_back(int val) {
        if(size == capacity) {
            if(capacity == 0) {
                resize(1);
            } else {
                // 扩容
                resize(capacity * 2);
            }
        }
            arr[size++] = val;
        }



    int at(int index) {
        if(index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }



    void resize(int new_size) {
        int* new_arr = new int[new_size];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_size;
    }

    ~MyVector() {
        delete[] arr;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

};


int main() {
    MyVector vec;
    int initial_capacity = vec.getCapacity();
    int expansion_count = 0;

    for (int i = 0; i < 20; ++i) {
        int current_capacity = vec.getCapacity();
        vec.push_back(i);
        if (vec.getCapacity() != current_capacity) {
            ++expansion_count;
        }
    }

    std::cout << "Initial capacity: " << initial_capacity << std::endl;
    std::cout << "Final capacity: " << vec.getCapacity() << std::endl;
    std::cout << "Number of expansions: " << expansion_count << std::endl;


    std::cout << "Final size: " << vec.getSize() << std::endl;

    return 0;
}    