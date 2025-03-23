#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // 遍历网格
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j){
                if(grid[i][j] == '1') {
                    ++count;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    };

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 检查边界是否为陆地
        if(i < 0 || i >= rows || j < 0 || j>= cols || grid[i][j] != '1') {
            return;
        }

        // 标记当前陆地已访问
        grid[i][j] = '0';

        // 递归访问上下左右相邻的陆地
        dfs(grid, i-1, j); // 上
        dfs(grid, i+1, j); // 下
        dfs(grid, i, j-1); // 左
        dfs(grid, i, j+1); // 右

        }
};