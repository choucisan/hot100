/**
 * Created by choucisan on 2025/7/14 12:06
 */

/*
 42. 接雨水
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// 计算给定数组中可以存储的水量
    int trap(vector<int>& height) {
        // 获取数组长度
        int n = height.size();
        // 创建两个数组，分别存储当前位置左边的最大值和右边的最大值
        vector<int> left(n), right(n);
        // 遍历数组，计算当前位置左边的最大值
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        // 遍历数组，计算当前位置右边的最大值
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        // 初始化水量为0
        int water = 0;
        // 遍历数组，计算当前位置可以存储的水量
        for (int i = 0; i < n; i++) {
            // 当前位置可以存储的水量等于当前位置左边的最大值和右边的最大值中的较小值减去当前位置的高度
            int level = min(left[i], right[i]);
            water += max(0, level - height[i]);
        }
        // 返回总水量
        return water;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water = solution.trap(height);
    cout << water << endl;
    return 0;

}
