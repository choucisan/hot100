/**
 * Created by choucisan on 2025/7/12 22:06
 */
/*
 136. 只出现一次的数字
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// 定义一个函数，用于找出数组中只出现一次的数字
    int singleNumber(vector<int>& nums) {
        // 定义一个无序映射，用于存储数组中每个数字出现的次数
        unordered_map<int,int> freq;
        // 遍历数组，将每个数字出现的次数存储到映射中
        for(int i=0;i<nums.size();++i){
            freq[nums[i]]++;
        }
        // 遍历映射，找出只出现一次的数字
        for(auto& [num,count]:freq){
            if (count==1){
                return num;
            }
        }
        // 如果没有找到只出现一次的数字，则返回-1
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,2,1,1};
    cout<<s.singleNumber(nums)<<endl;
    return 0;
}