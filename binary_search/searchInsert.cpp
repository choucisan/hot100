/**
 * Created by choucisan on 2025/7/12 21:27
 */
/*
 35. 搜索插入位置
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 请必须使用时间复杂度为 O(log n) 的算法。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// 在给定的排序数组中查找目标值，并返回其索引。如果目标值不存在，则返回它应插入的位置。
    int searchInsert(vector<int>& nums, int target) {
        // 定义左指针和右指针
        int left =0;
        int right =nums.size() - 1;

        // 当左指针小于等于右指针时，继续循环
        while(left<=right){
            // 计算中间位置
            int mid = left + (right - left)/2;
            // 如果中间位置的值等于目标值，则返回中间位置的索引
            if(nums[mid]==target){
                return mid;
            // 如果目标值小于中间位置的值，则将右指针移动到中间位置的前一个位置
            }else if(target<nums[mid]){
                right = mid-1;
            // 如果目标值大于中间位置的值，则将左指针移动到中间位置的后一个位置
            }if(target>nums[mid]){
                left = mid+1;
            }
        }
        // 如果目标值不存在，则返回左指针的位置
        return left;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout<<s.searchInsert(nums,target)<<endl;
    return 0;
}
