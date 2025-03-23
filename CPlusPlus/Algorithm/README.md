## static 和 const

### 1. `static` 关键字

#### 作用：

`static` 用于修饰变量、函数或类成员，具体作用取决于它的使用场景。

#### 使用场景：

- **局部变量**：

  - 在函数内部定义的 `static` 变量，其生命周期贯穿整个程序运行期间，但作用域仅限于函数内部。
  - 示例：
    ```cpp
    void func() {
        static int count = 0; // 静态局部变量
        count++;
        std::cout << "Count: " << count << std::endl;
    }
    ```

    每次调用 `func()` 时，`count` 的值会保留并递增。
- **全局变量**：

  - 在全局作用域中定义的 `static` 变量，其作用域仅限于当前文件（文件作用域），避免与其他文件的同名变量冲突。
  - 示例：
    ```cpp
    static int globalVar = 42; // 静态全局变量
    ```
- **类成员**：

  - 在类中定义的 `static` 成员变量属于类，而不是类的实例，所有对象共享同一个静态成员。
  - 示例：
    ```cpp
    class MyClass {
    public:
        static int staticVar; // 静态成员变量
    };
    int MyClass::staticVar = 0; // 类外初始化
    ```
- **函数**：

  - 在函数定义前加 `static`，表示该函数的作用域仅限于当前文件。
  - 示例：
    ```cpp
    static void helperFunc() {
        // 只能在当前文件中调用
    }
    ```

---

### 2. `const` 关键字

#### 作用：

`const` 用于定义常量，表示变量或对象的值不能被修改。

#### 使用场景：

- **变量**：

  - 定义常量变量，初始化后不能被修改。
  - 示例：
    ```cpp
    const int maxValue = 100; // 常量变量
    // maxValue = 200; // 错误：常量不能被修改
    ```
- **指针**：

  - 可以修饰指针本身或指针指向的值。
  - 示例：
    ```cpp
    int value = 10;
    const int *ptr1 = &value; // 指针指向的值是常量
    int *const ptr2 = &value; // 指针本身是常量
    ```
- **函数参数**：

  - 用于防止函数内部修改参数的值。
  - 示例：
    ```cpp
    void printValue(const int value) {
        // value = 20; // 错误：常量不能被修改
        std::cout << value << std::endl;
    }
    ```
- **类成员函数**：

  - 表示该函数不会修改类的成员变量。
  - 示例：
    ```cpp
    class MyClass {
    public:
        int getValue() const {
            return value; // 不会修改成员变量
        }
    private:
        int value;
    };
    ```

---

### 3. `static` 和 `const` 的组合

`static` 和 `const` 可以组合使用，表示一个静态常量。

#### 使用场景：

- **局部静态常量**：

  - 在函数内部定义的 `static const` 变量，其生命周期贯穿整个程序运行期间，且不能被修改。
  - 示例：
    ```cpp
    void func() {
        static const int value = 10; // 静态常量
        // value = 20; // 错误：常量不能被修改
        std::cout << value << std::endl;
    }
    ```
- **类中的静态常量成员**：

  - 在类中定义的 `static const` 成员变量，所有对象共享同一个常量。
  - 示例：
    ```cpp
    class MyClass {
    public:
        static const int value = 100; // 静态常量成员
    };
    ```
- **全局静态常量**：

  - 在全局作用域中定义的 `static const` 变量，其作用域仅限于当前文件，且不能被修改。
  - 示例：
    ```cpp
    static const int globalValue = 42; // 全局静态常量
    ```

---

### 4. `static` 和 `const` 的区别

| 特性         | `static`                       | `const`                      |
| ------------ | -------------------------------- | ------------------------------ |
| 作用         | 控制变量或函数的作用域和生命周期 | 定义常量，防止变量或对象被修改 |
| 生命周期     | 贯穿整个程序运行期间             | 取决于变量的作用域             |
| 作用域       | 局部、全局或类作用域             | 局部、全局或类作用域           |
| 是否可以修改 | 可以修改（除非同时是 `const`） | 不能被修改                     |
| 典型用途     | 保留函数调用之间的值、共享类成员 | 定义常量、保护函数参数不被修改 |

---

### 5. 总结

- `static` 用于控制变量或函数的作用域和生命周期。
- `const` 用于定义常量，防止变量或对象被修改。
- `static` 和 `const` 可以组合使用，表示一个静态常量，既保留静态特性，又保证不可变性。
