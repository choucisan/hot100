/**
 * Created by choucisan on 2025/7/13 15:44
 */
/*
 128. 最长连续序列
 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
// 定义一个函数，用于计算数组中连续数字的最长长度
    int longestConsecutive(vector<int>& nums) {
        // 定义一个无序集合，用于存储数组中的数字
        unordered_set<int> num_set;
        // 遍历数组中的每个数字，将其插入到无序集合中
        for (int num : nums) {
            num_set.insert(num);
        }
        // 定义一个变量，用于存储最长连续数字的长度
        int longestStreak = 0;
        // 遍历无序集合中的每个数字
        for (int num : num_set) {
            // 如果当前数字的前一个数字不在无序集合中，说明当前数字是连续数字的起始数字
            if (!num_set.count(num - 1)) {
                // 定义一个变量，用于存储当前连续数字的长度
                int currentNum = num;
                int currentStreak = 1;

                // 遍历当前连续数字的下一个数字，直到下一个数字不在无序集合中
                while (num_set.count(currentNum + 1)) {
                    // 将当前数字加1
                    currentNum += 1;
                    // 将当前连续数字的长度加1
                    currentStreak += 1;
                }
                // 更新最长连续数字的长度
                longestStreak = max(longestStreak, currentStreak);
                }
            }
        // 返回最长连续数字的长度
        return longestStreak;
        }
};


int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    int longestStreak = solution.longestConsecutive(nums);
    cout  << longestStreak << endl;
    return 0;
}

