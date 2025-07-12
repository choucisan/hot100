/**
 * Created by choucisan on 2025/7/12 17:57
 */
/*
 1. 两数之和
 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个整数，并返回它们的数组下标。
 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
 你可以按任意顺序返回答案。
 */


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建一个哈希表，用于存储数组中的元素及其对应的索引
        unordered_map<int,int>hsahtable;
        // 获取数组的大小
        int n = nums.size();
        // 遍历数组
        for(int i=0;i<n;++i){
            // 在哈希表中查找目标值与当前元素的差值
            auto it = hsahtable.find(target-nums[i]);//
            // 如果找到，则返回两个元素的索引
            if(it != hsahtable.end()){
                return {it->second,i};
            }
            // 将当前元素及其索引存入哈希表中
            hsahtable[nums[i]] = i;
        }
        // 如果没有找到，则返回空数组
        return{};
    }
};


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    Solution s;
    vector<int> result = s.twoSum(nums, target);

    if (!result.empty()) {
        cout << '['<< result[0] << "," << result[1] <<']'<< endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
