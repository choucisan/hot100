/**
 * Created by choucisan on 2025/9/11 20:39
 */


/*
 189. 轮转数组
 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 */


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
/**
 * 反转数组中指定区间的元素
 * @param nums 待操作的数组
 * @param start 起始位置
 * @param end 结束位置
 */
    void reverse(vector<int>& nums,int start,int end){
        while(start < end){ // 当起始位置小于结束位置时，继续交换
            swap(nums[start],nums[end]); // 交换起始位置和结束位置的元素
            start += 1; // 起始位置向后移动
            end -= 1; // 结束位置向前移动
        }
    }

/**
 * 旋转数组函数
 * 将数组向右旋转k个位置
 * @param nums 要旋转的数组
 * @param k 旋转的步数
 */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  // 获取数组长度
        k %= n;               // 处理k大于数组长度的情况，避免不必要的旋转
        reverse(nums,0,n-1);  // 第一次反转：反转整个数组
        reverse(nums,0,k-1);  // 第二次反转：反转前k个元素
        reverse(nums,k,n-1);  // 第三次反转：反转剩余元素

    }
};



int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7};
    s.rotate(nums,3);
    cout<<"[";
    for(int i = 0;i < nums.size();i++){
        cout << nums[i];
        if(i < nums.size()-1) cout<<",";
    }
    cout<<"]"<<endl;
}