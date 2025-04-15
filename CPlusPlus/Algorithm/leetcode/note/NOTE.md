## 常见STL容器的基础操作

以下是C++中常见STL容器的基础操作、常见函数及区别的详细介绍：

---

### **1. std::vector**

-**用途**：动态数组，支持快速随机访问。

-**底层结构**：连续内存空间。

-**核心操作**：

```cpp

  push_back(val);       // 尾部插入

  pop_back();           // 尾部删除

  insert(iterator, val);// 指定位置插入

  erase(iterator);      // 指定位置删除

  operator[] /at();    // 随机访问（at会检查越界）

  size();               // 元素数量

  resize(n);            // 调整大小

  clear();              // 清空

```

```cpp

  #include<iostream>

  #include<vector>


  intmain() {

      std::vector<int> vec;

      // 插入元素

      vec.push_back(1);

      vec.push_back(2);

      vec.push_back(3);


      // 访问元素

      std::cout <<"Element at index 1: "<<vec[1] << std::endl;


      // 获取元素数量

      std::cout <<"Size of vector: "<<vec.size() << std::endl;


      // 删除最后一个元素

      vec.pop_back();


      return0;

  }

```

-**特点**：

- 尾部操作高效（O(1)），中间插入/删除较慢（O(n)）。
- 内存预分配（`capacity()` 和 `reserve()`）。

---

### **2. std::stack**

-**用途**：后进先出（LIFO）的栈结构。

-**底层容器**：默认使用 `std::deque`，可替换为 `std::vector` 或 `std::list`。

-**核心操作**：

```cpp

  push(val);  // 压栈

  pop();      // 弹栈（不返回栈顶元素）

  top();      // 查看栈顶元素

  empty();    // 是否为空

  size();     // 元素数量

```

```cpp

  #include<iostream>

  #include<stack>


  intmain() {

      std::stack<int> st;

      // 入栈

      st.push(1);

      st.push(2);

      st.push(3);


      // 访问栈顶元素

      std::cout <<"Top element: "<<st.top() << std::endl;


      // 出栈

      st.pop();


      return0;

  }

```

-**特点**：

- 仅允许操作栈顶，不支持遍历。

---

### **3. std::list**

-**用途**：双向链表，支持高效插入/删除。

-**核心操作**：

```cpp

  push_front(val); // 头部插入

  push_back(val);  // 尾部插入

  pop_front();     // 头部删除

  pop_back();      // 尾部删除

  insert(iterator, val); // 指定位置插入

  erase(iterator);       // 指定位置删除

  sort();          // 成员函数排序（优于算法库的std::sort）

  splice();        // 移动元素到另一链表

```

```cpp

  #include<iostream>

  #include<list>


  intmain() {

      std::list<int> lst;

      // 插入元素

      lst.push_back(1);

      lst.push_front(0);


      // 遍历列表

      for (auto it =lst.begin(); it !=lst.end(); ++it) {

          std::cout <<*it <<" ";

      }

      std::cout << std::endl;


      // 删除元素

      lst.pop_back();


      return0;

  }

```

-**特点**：

- 任意位置插入/删除为 O(1)，但访问元素需遍历（O(n)）。
- 内存非连续，额外指针开销。

---

### **4. std::deque**

-**用途**：双端队列，支持头尾高效操作。

-**底层结构**：分段连续内存（多块数组）。

-**核心操作**：

```cpp

  push_front(val); // 头部插入

  push_back(val);  // 尾部插入

  pop_front();     // 头部删除

  pop_back();      // 尾部删除

  operator[];      // 随机访问（类似vector）

```

```cpp

  #include<iostream>

  #include<deque>


  intmain() {

      std::deque<int> dq;

      // 插入元素

      dq.push_back(1);

      dq.push_front(0);


      // 访问元素

      std::cout <<"Element at index 1: "<<dq[1] << std::endl;


      // 删除元素

      dq.pop_back();


      return0;

  }

```

-**特点**：

- 头尾操作高效（O(1)），中间插入/删除较慢（O(n)）。
- 随机访问性能接近 `vector`，但内存非完全连续。

---

### **5. std::set / std::multiset**

-**用途**：有序唯一键集合（`multiset` 允许重复）。

-**底层结构**：红黑树（平衡二叉搜索树）。

-**核心操作**：

```cpp

  insert(val);      // 插入元素

  erase(val);       // 删除元素

  find(val);        // 查找元素（返回迭代器）

  count(val);       // 统计元素出现次数

  lower_bound(val); // 第一个 >= val 的元素

  upper_bound(val); // 第一个 > val 的元素

```

```cpp

  #include<iostream>

  #include<set>


  intmain() {

      std::set<int> s;

      // 插入元素

      s.insert(1);

      s.insert(2);

      s.insert(3);


      // 查找元素

      auto it =s.find(2);

      if (it !=s.end()) {

          std::cout <<"Element 2 found."<< std::endl;

      }


      // 删除元素

      s.erase(3);


      return0;

  }

```

-**特点**：

- 元素自动排序，插入/删除/查找为 O(log n)。
- 不支持修改元素值（需先删除再插入）。

---

### **6. std::map / std::multimap**

-**用途**：键值对的有序关联容器（`multimap` 允许重复键）。

-**底层结构**：红黑树。

-**核心操作**：

```cpp

  insert({key, val}); // 插入键值对

  erase(key);         // 删除键

  find(key);          // 查找键

  operator[];         // 通过键访问值（若不存在则插入）

```

```cpp

  #include<iostream>

  #include<map>


  intmain() {

      std::map<std::string, int> m;

      // 插入元素

      m["apple"] =1;

      m["banana"] =2;


      // 访问元素

      std::cout <<"Value of apple: "<<m["apple"] << std::endl;


      // 查找元素

      auto it =m.find("banana");

      if (it !=m.end()) {

          std::cout <<"Key banana found, value: "<<it->second<< std::endl;

      }


      // 删除元素

      m.erase("apple");


      return0;

  }

```

-**特点**：

- 类似 `set`，但存储键值对。

  -`operator[]` 可用于插入或修改值。

---

### **容器对比与选择**

| **特性** | vector | deque | list | set/map  | stack/queue  |

| -------------- | ------ | ----- | ---- | -------- | ------------ |

| 随机访问       | ✅     | ✅    | ❌   | ❌       | ❌           |

| 头尾插入/删除  | 尾 ✅  | ✅    | ✅   | ❌       | ✅（受限）   |

| 中间插入/删除  | ❌     | ❌    | ✅   | ❌       | ❌           |

| 自动排序       | ❌     | ❌    | ❌   | ✅       | ❌           |

| 内存连续性     | ✅     | ❌    | ❌   | ❌       | 依赖底层容器 |

| 查找效率       | O(n)   | O(n)  | O(n) | O(log n) | ❌           |

---

### **选择建议**

-**需要快速随机访问**：`vector` 或 `deque`。

-**频繁头尾操作**：`deque`。

-**频繁中间插入/删除**：`list`。

-**有序且快速查找**：`set/map`。

-**后进先出/先进先出**：`stack/queue`。

## 常用的 STL 容器操作函数总结

以下是针对算法题中常用的 STL 容器操作函数总结，涵盖高频使用场景和优化技巧：

---

### **1. `std::vector`**

-**核心操作**：

```cpp

  v.push_back(x);      // 尾部插入元素

  v.pop_back();        // 删除尾部元素

  v.emplace_back(...); // 直接在尾部构造元素（避免拷贝，高效）

  v.size();            // 元素数量

  v.empty();           // 判断是否为空

  v.clear();           // 清空元素

  v.resize(n);         // 调整大小

  v.reserve(n);        // 预分配内存（避免动态扩容）

  v.swap(other);       // 快速交换内容（释放内存）

  sort(v.begin(), v.end()); // 排序（配合算法库）

  reverse(v.begin(), v.end()); // 反转

```

-**算法题场景**：

- 动态数组、模拟栈/队列、二维数组（`vector<vector<int>>`）。
- 预分配内存 (`reserve`) 可大幅优化性能（例如处理 1e5 规模数据）。

  -`emplace_back` 替代 `push_back` 减少临时对象拷贝。

---

### **2. `std::stack`**

-**核心操作**：

```cpp

  s.push(x);   // 压栈

  s.pop();     // 弹栈（无返回值）

  s.top();     // 获取栈顶元素

  s.empty();   // 判空

  s.size();    // 元素数量

```

-**算法题场景**：

- 括号匹配、表达式求值、DFS 递归的非递归实现。
- 若需遍历栈，可以先用 `vector` 模拟栈（直接操作 `back()` 和 `pop_back()`）。

---

### **3. `std::deque`**

-**核心操作**：

```cpp

  d.push_front(x); // 头部插入

  d.push_back(x);  // 尾部插入

  d.pop_front();   // 删除头部

  d.pop_back();    // 删除尾部

  d.front();       // 访问头部

  d.back();        // 访问尾部

  d[i];           // 随机访问（类似 vector）

```

-**算法题场景**：

- 滑动窗口最大值、BFS 队列（替代 `queue` 以支持随机访问）。
- 双端操作高效，适合需要频繁头尾增删的场景。

---

### **4. `std::list`**

-**核心操作**：

```cpp

  lst.push_front(x); // 头部插入

  lst.push_back(x);  // 尾部插入

  lst.pop_front();   // 删除头部

  lst.pop_back();    // 删除尾部

  lst.insert(it, x); // 在迭代器位置插入

  lst.erase(it);     // 删除迭代器指向的元素

  lst.splice(pos, other_lst); // 合并链表

```

-**算法题场景**：

- 需要频繁在中间插入/删除（如 LRU 缓存的双向链表实现）。
- 实际算法题中使用较少，优先考虑 `vector` 或 `deque`。

---

### **5. `std::set` / `std::multiset`**

-**核心操作**：

```cpp

  s.insert(x);       // 插入元素

  s.erase(x);        // 删除元素

  s.erase(it);       // 删除迭代器指向的元素

  s.find(x);         // 查找元素，返回迭代器（未找到返回 s.end()）

  s.count(x);        // 统计元素出现次数（set 为 0/1，multiset 可 >1）

  s.lower_bound(x);  // 返回第一个 >=x 的元素的迭代器

  s.upper_bound(x);  // 返回第一个 >x 的元素的迭代器

  s.begin();         // 最小元素（有序集合）

  s.rbegin();        // 最大元素（反向迭代器）

```

-**算法题场景**：

- 维护有序集合（如求中位数、区间查询）。
- 快速查找是否存在元素（替代线性搜索）。
- 注意 `multiset` 的 `erase(val)` 会删除所有等于 `val` 的元素，需用迭代器删除单个元素。

---

### **6. `std::map` / `std::multimap`**

-**核心操作**：

```cpp

  m[key] = value;            // 插入或修改键值对

  m.insert({key, value});    // 插入键值对（返回是否成功）

  m.erase(key);              // 删除键

  m.find(key);               // 查找键

  m.count(key);              // 统计键是否存在

  m.lower_bound(key);        // 返回第一个键 >= key 的迭代器

  m.upper_bound(key);        // 返回第一个键 > key 的迭代器

  m.begin();                 // 最小键的迭代器

```

-**算法题场景**：

- 键值对的有序存储（如统计频率、范围查询）。
- 注意 `operator[]` 在键不存在时会自动插入默认值，可能导致意外行为。

---

### **高频优化技巧**

1.**预分配内存**：

```cpp

   vector<int> v;

   v.reserve(1e5); // 处理大数据时减少动态扩容开销

```

2.**避免拷贝构造**：

```cpp

   v.emplace_back(a, b); // 直接构造对象，替代 push_back(MyClass(a, b))

```

3.**快速清空容器**：

```cpp

   vector<int>().swap(v); // 释放 vector 内存

   deque<int>().swap(d);

```

4.**有序容器范围查询**：

```cpp

   auto it_low =s.lower_bound(L); // 区间 [L, R)

   auto it_high =s.upper_bound(R);

   for (auto it = it_low; it != it_high; ++it) { ... }

```

5.**使用迭代器删除元素**：

```cpp

   auto it =m.find(key);

   if (it !=m.end()) m.erase(it); // 比 erase(key) 更安全

```

6.**替代 `stack` 或 `queue` 的底层容器**：

```cpp

   stack<int, vector<int>> st; // 用 vector 实现栈（方便遍历）

   queue<int, list<int>> q;     // 用 list 实现队列（避免 deque 的扩容问题）

```

---

### **容器选择指南**

| **场景**        | **推荐容器**             |

| --------------------- | ------------------------------ |

| 需要快速随机访问      | `vector` / `deque`         |

| 频繁头尾插入删除      | `deque`                      |

| 需要自动排序/快速查找 | `set` / `map`              |

| 后进先出（LIFO）      | `stack`（或 `vector`模拟） |

| 先进先出（FIFO）      | `queue`（或 `deque`）      |

| 需要中间插入删除      | `list`（少用，优先其他）     |

| 高频插入删除且需排序  | `multiset` / `multimap`    |

---

掌握这些操作和优化技巧，可以显著提升算法题的编码效率和运行性能！
