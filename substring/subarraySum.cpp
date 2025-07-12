/**
 * Created by choucisan on 2025/7/12 20:19
 */
/*
 560. 和为 K 的子数组
 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的子数组的个数 。
 子数组是数组中元素的连续非空序列。
 */


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
// 计算数组中和为k的子数组的个数
    int subarraySum(vector<int>& nums, int k) {
        // 创建一个哈希表，用于存储前缀和及其出现的次数
        unordered_map<int,int>hashtable;
        // 初始化结果为0，前缀和为0的次数为1
        int res=0,sum=0;
        hashtable[sum]++;
        // 遍历数组
        for(int i=0;i<nums.size();++i){
            // 更新前缀和
            sum+=nums[i];
            // 如果哈希表中存在前缀和为sum-k的值，则说明存在一个子数组的和为k
            if(hashtable.count(sum-k)){
                // 将该子数组的个数加到结果中
                res+=hashtable[sum-k];
            }
            // 将当前前缀和的次数加1
            hashtable[sum]++;
        }
        // 返回结果
        return res;
    }
};


int main(){
    vector<int>nums={1,2,3};
    Solution s;
    cout<<s.subarraySum(nums,3)<<endl;
    return 0;
}


