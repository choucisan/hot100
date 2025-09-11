/**
 * Created by choucisan on 2025/9/11 16:47
 */

/*
 56. 合并区间
 给你一个二维整数数组 intervals ，其中 intervals[i] = [starti, endi] 表示从 starti 到 endi 的闭区间。
 合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 */

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
/**
 * 合并重叠区间
 * @param intervals 区间数组，每个区间用包含两个整数的向量表示
 * @return 合并后的区间数组
 */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 如果输入区间数组为空，直接返回空数组
        if(intervals.empty()) return {};

        // 将区间数组按照第一个元素进行排序
        sort(intervals.begin(),intervals.end());

        // 初始化结果数组，并将第一个区间加入结果
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        // 遍历所有区间，进行合并操作
        for(int i = 0;i<intervals.size();++i){
            // 如果当前区间的起始值小于等于结果数组中最后一个区间的结束值，则存在重叠
            if(intervals[i][0] <= res.back()[1]){
                // 合并区间，更新结果数组中最后一个区间的结束值为两者中的较大值
                res.back()[1]= max(res.back()[1],intervals[i][1]);
            }
            else{
                // 如果没有重叠，将当前区间加入结果数组
                res.push_back(intervals[i]);
            }
        }
        // 返回合并后的区间数组
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = s.merge(intervals);

    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ","; // 数组内元素用逗号分隔
        }
        cout << "]";
        if (i < res.size() - 1) cout << ","; // 数组之间用逗号分隔
    }
    cout << "]" << endl;

    return 0;
}