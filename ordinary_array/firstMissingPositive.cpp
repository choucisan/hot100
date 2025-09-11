/**
 * Created by choucisan on 2025/9/11 20:50
 */


/*
 41. 缺失的第一个正数
 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 */

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
/**
 * 寻找第一个缺失的正整数
 * @param nums 输入的整数数组
 * @return 第一个缺失的正整数
 */
    int firstMissingPositive(vector<int>& nums) {
        // 获取数组的大小
        int n = nums.size();
        // 创建一个布尔数组，用于标记1到n的正整数是否在原数组中出现过
        // 大小为n+1，因为可能所有1到n的正整数都存在，此时返回n+1
        vector<bool> present(n+1,false);
        // 遍历数组中的每个元素
        for(int x : nums){
            // 如果元素在1到n的范围内，则在present数组中标记为true
            if(x>0 && x<=n){
                present[x]= true;
            }
        }
        // 从1开始检查每个正整数，找到第一个未出现的正整数
        for(int i=1;i<=n;++i){
            // 如果某个正整数没有出现过，则直接返回它
            if(!present[i]) return i;
        }
        // 如果1到n的正整数都存在，则返回n+1
        return n+1;
    }
};


int main(){
    Solution s;
    vector<int> nums = {7,8,9,11,12};
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}