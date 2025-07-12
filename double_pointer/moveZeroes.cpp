/**
 * Created by choucisan on 2025/7/12 18:18
 */
/*
 283. 移动零
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 定义一个指针pos，用于记录非零元素的位置
        int pos =0;
        // 遍历数组
        for(int i=0;i<nums.size();++i){
            // 如果当前元素不为零
            if(nums[i]!=0){
                // 将当前元素赋值给指针pos所指向的位置
                nums[pos]=nums[i];
                // 指针pos向后移动一位
                pos++;
            }
        }
        // 将指针pos之后的位置全部赋值为零
        for(;pos<nums.size();++pos){
            nums[pos]=0;
        }
    }
};


int main(){
    vector<int>nums={0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    cout<<'[';
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}

