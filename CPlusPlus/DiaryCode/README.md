

## 岛屿数量
### 题目分析
[岛屿数量](https://leetcode.cn/problems/number-of-islands/description/?envType=problem-list-v2&envId=depth-first-search) 这道题给定一个由 `'1'`（陆地）和 `'0'`（水）组成的二维网格，要求计算网格中岛屿的数量。岛屿被水包围，并且由水平或垂直方向上相邻的陆地连接形成。你可以假设网格的四个边均被水包围。

### 实现思路
可以使用深度优先搜索（DFS）来解决这个问题。具体步骤如下：
1. 遍历整个二维网格。
2. 当遇到 `'1'` 时，说明发现了一个新的岛屿，将岛屿数量加 1，并使用 DFS 方法将该岛屿所有相连的 `'1'` 都标记为 `'0'`，表示已经访问过。
3. 继续遍历网格，直到所有的陆地都被访问过。

### C++ 代码实现
```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // 遍历整个网格
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    // 发现新岛屿，数量加1
                    ++count;
                    // 使用 DFS 标记该岛屿的所有陆地
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 检查边界条件和是否为陆地
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
            return;
        }

        // 将当前陆地标记为已访问
        grid[i][j] = '0';

        // 递归访问上下左右相邻的陆地
        dfs(grid, i - 1, j); // 上
        dfs(grid, i + 1, j); // 下
        dfs(grid, i, j - 1); // 左
        dfs(grid, i, j + 1); // 右
    }
};
```

### 代码调用示例
```cpp
int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}
```

### 代码解释
1. **`numIslands` 函数**：
    - 首先检查网格是否为空，如果为空则直接返回 0。
    - 遍历整个网格，当遇到 `'1'` 时，岛屿数量加 1，并调用 `dfs` 函数将该岛屿的所有陆地标记为 `'0'`。
    - 最后返回岛屿的数量。

2. **`dfs` 函数**：
    - 检查当前位置是否越界或者是否为陆地，如果不满足条件则直接返回。
    - 将当前陆地标记为 `'0'`，表示已经访问过。
    - 递归调用 `dfs` 函数，访问当前位置的上下左右相邻的陆地。

### 复杂度分析
- **时间复杂度**：$O(m * n)$，其中 $m$ 是网格的行数，$n$ 是网格的列数。因为需要遍历整个网格。
- **空间复杂度**：$O(m * n)$，在最坏情况下，整个网格都是陆地，递归调用栈的深度最大为 $m * n$。