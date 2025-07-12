/**
 * Created by choucisan on 2025/7/12 21:46
 */
/*
 121. 买卖股票的最佳时机
 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
// 计算最大利润
    int maxProfit(vector<int>& prices) {
        // 初始化返回值为0
        int ret = 0;
        // 获取价格数组的长度
        int n =prices.size();
        // 初始化最小值为第一个价格
        int minv = prices[0];
        // 遍历价格数组
        for(int i =1;i<n;i++){
            // 计算当前价格与最小值的差值
            int ans = prices[i] - minv;
            // 更新最大利润
            ret=max(ret,ans);
            // 更新最小值
            minv=min(minv,prices[i]);
        }
        // 返回最大利润
        return ret;

    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}