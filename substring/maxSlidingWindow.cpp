/**
 * Created by choucisan on 2025/9/8 13:35
 */

/*
 239. 滑动窗口最大值
 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 返回滑动窗口中的最大值。
 */


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
/**
 * 使用双端队列(deque)解决滑动窗口最大值问题
 * @param nums 输入数组
 * @param k 滑动窗口的大小
 * @return 返回一个数组，包含每个滑动窗口的最大值
 */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();    // 获取数组长度
        deque<int> dq;         // 双端队列，用于存储可能成为最大值的元素索引
        vector<int> res;       // 结果数组，存储每个窗口的最大值
    // 遍历数组
        for (int i = 0;i < n;++i){
        // 维护队列：移除队列末尾所有比当前元素小的元素
        // 这确保队列中的元素是从大到小排列的
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);    // 将当前元素的索引加入队列

        // 检查队列头部元素是否超出窗口范围
            if(dq.front()<=i-k){
                dq.pop_front(); // 移除超出窗口范围的元素
            }

        // 当窗口大小达到k时，记录当前窗口的最大值
        // 队列头部元素即为当前窗口的最大值
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }

        }
        return res; // 返回结果数组

    }
};


int main(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = s.maxSlidingWindow(nums,3);
    for(auto i:res){
        cout<<i<<" ";
    }
}