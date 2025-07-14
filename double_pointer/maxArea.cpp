/**
 * Created by choucisan on 2025/7/13 17:57
 */
/*
 11. 盛最多水的容器
 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 说明：你不能倾斜容器。
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
// 计算容器中水的最大面积
    int maxArea(vector<int>& height) {
        // 获取容器的高度
        int n = height.size();
        // 初始化左指针
        int left = 0;
        // 初始化右指针
        int right = n-1;
        // 初始化最大水量
        int maxwater =0;

        // 当左指针小于右指针时，继续循环
        while(left<right){
            // 初始化当前水量
            int water =0;
            // 如果左指针的高度小于等于右指针的高度
            if(height[left]<=height[right]){
                // 当前水量为左指针和右指针之间的距离乘以左指针的高度
                water = (right-left)*height[left];
                // 左指针向右移动一位
                left+=1;
            }
            // 否则
            else{
                // 当前水量为左指针和右指针之间的距离乘以右指针的高度
                water = (right-left)*height[right];
                // 右指针向左移动一位
                right+=-1;

            }
            // 更新最大水量
            maxwater = max(maxwater,water);
        }
        // 返回最大水量
        return maxwater;
    }
};

int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
}