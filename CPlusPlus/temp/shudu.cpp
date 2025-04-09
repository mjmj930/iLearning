#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class NxNTable {
private:
    vector<vector<int>> table;
    int size;

public:
    // 构造函数，创建n×n的表格
    NxNTable(int n) : size(n) {
        table.resize(n, vector<int>(n, 0));
    }

    // 填充表格数据（示例：填充行号×列号）
    void fillTable() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                table[i][j] = (i + 1) * (j + 1); // 示例数据
            }
        }
    }

    // 设置特定单元格的值
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            table[row][col] = value;
        } else {
            cerr << "Invalid row or column index!" << endl;
        }
    }

    // 获取特定单元格的值
    int getValue(int row, int col) const {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            return table[row][col];
        }
        cerr << "Invalid row or column index!" << endl;
        return -1; // 表示错误
    }

    // 显示表格
    void display() const {
        cout << "Displaying " << size << "x" << size << " table:" << endl;
        
        // 打印列号
        cout << "    ";
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << j + 1;
        }
        cout << "\n    ";
        for (int j = 0; j < size; ++j) {
            cout << "----";
        }
        cout << endl;
        
        // 打印表格内容
        for (int i = 0; i < size; ++i) {
            cout << setw(2) << i + 1 << " |"; // 行号
            for (int j = 0; j < size; ++j) {
                cout << setw(4) << table[i][j];
            }
            cout << endl;
        }
    }

    // 获取表格大小
    int getSize() const {
        return size;
    }
};

int main() {
    int n;
    cout << "Enter the size of the table (n x n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid table size!" << endl;
        return 1;
    }

    NxNTable table(n);
    table.fillTable();
    table.display();

    // 示例：修改和获取单元格值
    cout << "\nExample of modifying and accessing cells:" << endl;
    table.setValue(1, 1, 99); // 修改第2行第2列的值
    cout << "Value at (2,2): " << table.getValue(1, 1) << endl;
    cout << "Value at (3,3): " << table.getValue(2, 2) << endl;
    
    // 显示修改后的表格
    cout << "\nModified table:" << endl;
    table.display();

    return 0;
}