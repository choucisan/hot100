/**
 * Created by choucisan on 2025/7/12 21:52
 */
/*
 70. 爬楼梯
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

#include <iostream>
using namespace std;

class Solution {
public:
// 定义一个函数，用于计算爬楼梯的方法数
    int climbStairs(int n) {
        // 定义三个变量，分别表示前两个台阶的方法数和当前台阶的方法数
        int p=0,q=0,r=1;
        // 循环n次，计算当前台阶的方法数
        for(int i =1;i<=n;++i){
            // 将前两个台阶的方法数赋值给p和q
            p=q;
            q=r;
            // 当前台阶的方法数为前两个台阶的方法数之和
            r=p+q;
        }
        // 返回当前台阶的方法数
        return r;

    }
};

int main(){
    Solution s;
    cout<<s.climbStairs(3)<<endl;
    return 0;
}