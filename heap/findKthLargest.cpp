/**
 * Created by choucisan on 2025/7/12 21:41
 */
/*
 215. 数组中的第K个最大元素
 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 你必须实现时间复杂度为 O(n) 的算法解决此问题。
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        //最小堆
        priority_queue<int,vector<int>,greater<int>>pq;
        //遍历数组中的每个元素
        for(int x : nums){
            //如果堆的大小小于k，则将元素加入堆中
            if(pq.size()<k){
                pq.push(x);
            }else {
                //如果堆顶元素小于当前元素，则将堆顶元素弹出，将当前元素加入堆中
                if (pq.top()<x){
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        //返回堆顶元素，即第k大的元素
        return pq.top();

    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout<<s.findKthLargest(nums,2)<<endl;
}