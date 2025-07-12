/**
 * Created by choucisan on 2025/7/12 21:07
 */
/*
 46. 全排列
 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> used;
// 回溯函数
    void backtrack(vector<int>& path,vector<int>& nums){
        // 如果路径长度等于nums长度，说明已经找到了一个解，将其加入结果集
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }

        // 遍历nums数组
        for(int i=0;i<nums.size();++i){
            // 如果当前元素已经被使用过，则跳过
            if(used[i]) continue;
            // 标记当前元素已经被使用
            used[i]=true;
            // 将当前元素加入路径
            path.push_back(nums[i]);
            // 递归调用回溯函数
            backtrack(path,nums);
            // 将当前元素从路径中移除
            path.pop_back();
            // 标记当前元素未被使用
            used[i]=false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        used.resize(nums.size(),false);
        backtrack(path,nums);
        return res;
    }
};


int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> res=s.permute(nums);
    cout<<'[';
    for(auto& i:res){
        cout<<'[';
        for(auto& j:i){
            cout<<j;
            if (j!=i[i.size()-1]){
                cout<<',';
            }
        }
        cout<<']';
        if (i != res[res.size()-1]){
            cout<<',';
        }
    }
    cout<<']'<<endl;
}
