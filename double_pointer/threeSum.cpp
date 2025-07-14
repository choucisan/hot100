/**
 * Created by choucisan on 2025/7/13 18:28
 */
/*
 15. 三数之和
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 注意：答案中不可以包含重复的三元组。
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // 定义一个二维向量res，用于存储结果
            vector<vector<int>> res;
            // 获取nums的大小
            int n = nums.size();
            // 如果nums的大小小于3，则直接返回res
            if (n < 3) return res;
            // 对nums进行排序
            sort(nums.begin(), nums.end());
            // 遍历nums，从第一个元素开始
            for (int i = 0; i < n - 2; i++) {
                // 如果当前元素大于0，则直接跳出循环
                if (nums[i] > 0) break;
                // 如果当前元素与前一个元素相等，则跳过
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                // 定义两个指针l和r，分别指向当前元素的下一个元素和最后一个元素
                int l = i + 1, r = n - 1;
                // 当l小于r时，进行循环
                while (l < r) {
                    // 计算当前元素、l指针指向的元素和r指针指向的元素的和
                    int sum = nums[i] + nums[l] + nums[r];
                    // 如果和等于0，则将当前元素、l指针指向的元素和r指针指向的元素加入res中
                    if (sum == 0) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        // 如果l指针指向的元素与下一个元素相等，则l指针向后移动
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        // 如果r指针指向的元素与上一个元素相等，则r指针向前移动
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        // l指针向后移动
                        l++;
                        // r指针向前移动
                        r--;
                    }
                    // 如果和小于0，则l指针向后移动
                    else if (sum < 0) l++;
                    // 如果和大于0，则r指针向前移动
                    else r--;
                    }
                }
            // 返回res
            return res;
            }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    cout<<'[';
    for(size_t i = 0; i < res.size(); ++i) {
        cout<<'[';
        for(size_t j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j];
            if(j != res[i].size() - 1) {
                cout<<',';
            }
        }
        cout<<']';
        if(i != res.size() - 1) {
            cout<<',';
        }
    }
    cout<<']';
}