/**
 * Created by choucisan on 2025/9/11 20:47
 */

/*
 238. 除自身以外数组的乘积
 给你一个整数数组 nums，返回一个数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 */



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
/**
 * 计算除自身外的乘积
 * @param nums 输入的整数数组
 * @return 返回一个新数组，其中每个元素是原数组中除该元素外所有元素的乘积
 */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();  // 获取数组长度
        vector<int> chengji(n);  // 创建结果数组

    // 初始化第一个元素为1
        chengji[0]=1;
    // 从左到右遍历数组，计算每个位置左边所有元素的乘积
        for(int i = 1;i<n;++i){
            chengji[i] = nums[i-1] * chengji[i-1];
        }
        int R = 1;  // 用于存储右边元素的乘积
    // 从右到左遍历数组，将左边乘积与右边乘积相乘
        for(int i = n-1;i >=0 ;--i){
            chengji[i] = chengji[i] * R;  // 左右乘积相得到最终结果
            R *= nums[i];  // 更新右边乘积
        }
        return chengji;  // 返回结果数组

    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);

    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) cout << ","; // 数组内元素用逗号分隔
    }
    cout << "]" << endl;

    return 0;
}