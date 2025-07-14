/**
 * Created by choucisan on 2025/7/12 22:03
 */
/*
 62. 不同路径
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 问总共有多少条不同的路径？
 */

#include <iostream>
using namespace std;

class Solution {
public:
// 计算从左上角到右下角有多少条不同的路径
    int uniquePaths(int m, int n) {
        // 初始化一个长度为n的数组，所有元素都为1
        vector<int> f(n,1);
        // 从第二行开始遍历
        for (int i=1;i<m;++i){
            // 从第二列开始遍历
            for(int j=1;j<n;++j){
                // 当前格子的路径数等于左边格子的路径数加上上边格子的路径数
                f[j]+=f[j-1];
            }
        }
        // 返回最后一个格子的路径数
        return f[n-1];
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;
    return 0;
}