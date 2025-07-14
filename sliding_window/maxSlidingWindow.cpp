/**
 * Created by choucisan on 2025/7/14 16:17
 */

/*
 239. 滑动窗口最大值
 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 */


#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
// 定义一个函数，用于计算滑动窗口中的最大值
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            // 定义一个结果向量
            vector<int> res;
            // 获取输入向量的长度
            int n = nums.size();
            // 如果长度为0，则返回空的结果向量
            if(n == 0) return res;
            // 定义一个双端队列
            deque<int> q;
            // 遍历输入向量
            for(int i = 0; i < n; i++){
                // 如果队列不为空，且当前元素大于队列中的最后一个元素，则将队列中的最后一个元素弹出
                while(!q.empty() && nums[i] > nums[q.back()]){
                    q.pop_back();
                }
                // 将当前元素的索引加入队列
                q.push_back(i);
                // 如果队列中的第一个元素等于当前索引减去k，则将队列中的第一个元素弹出
                if(q.front() == i - k){
                    q.pop_front();
                }
                // 如果当前索引大于等于k-1，则将队列中的第一个元素加入结果向量
                if(i >= k - 1){
                    res.push_back(nums[q.front()]);
                }
                }
            // 返回结果向量
            return res;
            }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    cout<<'[';
    for(auto i : res){
        cout << i ;
        if(i != res.back()) cout<<',';
    }
    cout<<']';
}