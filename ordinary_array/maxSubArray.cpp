/**
 * Created by choucisan on 2025/7/12 20:27
 */
/*
 53. 最大子数组和
 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 子数组 是数组中的一个连续部分。
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
// 定义一个函数，用于计算数组中最大子数组的和
    int maxSubArray(vector<int>& nums) {
        // 初始化sum为0，max为INT_MIN
        int sum=0,max=INT_MIN;
        // 遍历数组
        for(int i=0;i<nums.size();++i){
            // 将当前元素加到sum中
            sum+=nums[i];
            // 如果sum大于max，则更新max
            if(sum>max){
                max=sum;
            }
            // 如果sum小于等于0，则将sum重置为0
            if(sum<=0){
                sum=0;
            }
        }
        // 返回max
        return max;
    }
};


int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}



