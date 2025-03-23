# C++ `sstream` 库详解

`<sstream>` 是 C++ 标准库中用于处理内存字符串流的头文件，提供了 `istringstream`、`ostringstream` 和 `stringstream` 三个核心类，支持字符串与多种数据类型的转换、流式操作及格式化处理[1,4](@ref)。

---

## 一、核心类及功能

| 类名              | 功能描述                           | 继承关系                                     |
| --------------- | ------------------------------ | ---------------------------------------- |
| `istringstream` | 从字符串中读取数据（输入流），支持 `>>` 操作符解析数据 | `istream` + `stringstreambase`[1](@ref)  |
| `ostringstream` | 向字符串写入数据（输出流），支持 `<<` 操作符拼接内容  | `ostream` + `stringstreambase`[1](@ref)  |
| `stringstream`  | 同时支持输入和输出操作，常用于复杂的数据转换和流处理     | `iostream` + `stringstreambase`[1](@ref) |

---

## 二、核心应用场景

### 1. 数据类型转换

通过流操作符 `<<` 和 `>>` 实现 **字符串与基本类型（int、float 等）的相互转换**，避免 `sprintf`/`sscanf` 的缓冲区溢出风险[4,6](@ref)。

```cpp
#include <sstream>
#include <iostream>

int main() {
    // int 转 string
    std::stringstream sstr;
    int num = 100;
    sstr << num;          // 写入流
    std::string str = sstr.str();  // 获取字符串
    std::cout << str;     // 输出 "100"

    // string 转 float
    std::istringstream istr("3.14");
    float pi;
    istr >> pi;           // pi = 3.14
    return 0;
}
```

### 2. 字符串分割

利用 `istringstream` 按空格自动分割字符串

```cpp
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {  // 按空格分割
        tokens.push_back(token);
    }
    return tokens;
}
// 输入 "Hello World 2023"，输出 ["Hello", "World", "2023"]
```

### 3. 流式操作与格式化

支持类似 `cout/cin` 的格式化操作（如精度控制）

```cpp
std::ostringstream oss;
oss << std::fixed << std::setprecision(2) << 3.14159;  
// oss.str() 为 "3.14"
```

### 4. 动态字符串拼接

通过 `ostringstream` 高效拼接多类型数据

```cpp
std::ostringstream oss;
oss << "ID: " << 1001 << ", Score: " << 95.5;
std::string result = oss.str();  // "ID: 1001, Score: 95.5"
```

## 三、注意事项

1. **清空流状态**
   多次转换时需先调用 `clear()` 重置错误标志，再通过 `str("")` 清空内容

```cpp
std::stringstream sstr;
sstr << "123";
int a;
sstr >> a;               // a = 123
sstr.clear();            // 重置状态
sstr.str("");            // 清空内容
sstr << "456";           // 重新写入
```

2. **性能考虑**
   频繁创建 `stringstream` 对象可能因动态内存分配影响性能，建议复用对象。
3. **多线程安全**
   `ostream` 系列类在多线程中无法保证原子性，日志输出建议使用专用库