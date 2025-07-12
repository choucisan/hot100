/**
 * Created by choucisan on 2025/7/12 20:59
 */
/*
 200. 岛屿数量
 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 此外，你可以假设该网格的四条边均被水包围。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        // 获取网格的行数和列数
        int m=grid.size();
        int n=grid[0].size();
        // 如果当前节点越界或者当前节点值为'0'，则返回
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;

        // 将当前节点值设为'0'
        grid[i][j]='0';

        // 递归调用dfs函数，分别对当前节点的上下左右节点进行深度优先搜索
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);

    }

// 计算岛屿数量
    int numIslands(vector<vector<char>>& grid) {
        // 初始化岛屿数量为0
        int count=0;
        // 获取网格的行数
        int m=grid.size();
        // 如果网格为空，返回0
        if(m==0) return 0;
        // 获取网格的列数
        int n=grid[0].size();
        // 遍历网格
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                // 如果当前格子为1，则进行深度优先搜索
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    // 岛屿数量加1
                    count++;
                }
            }
        }
        // 返回岛屿数量
        return count;
    }
};


int main(){
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','0','1'}};
    cout<<s.numIslands(grid)<<endl;
    return 0;
}