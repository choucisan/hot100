/**
 * Created by choucisan on 2025/7/13 15:18
 */

/*
 49. 字母异位词分组
 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
// 定义一个函数，用于将字符串数组中的字符串按照字母顺序排序，并将相同排序的字符串分组
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // 定义一个无序映射，用于存储排序后的字符串和对应的字符串数组
            unordered_map<string, vector<string>> map;
            // 遍历字符串数组
            for (auto &str : strs) {
                // 将字符串排序
                string key = str;
                sort(key.begin(), key.end());
                // 将排序后的字符串和对应的字符串添加到映射中
                map[key].emplace_back(str);
            }
            // 定义一个二维字符串数组，用于存储分组后的字符串
            vector<vector<string>> res;
            // 遍历映射
            for (auto &m : map) {
                // 将映射中的字符串数组添加到二维字符串数组中
                res.emplace_back(m.second);
            }
            // 返回分组后的字符串数组
            return res;
        }
};


int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    cout << '[';
    for (size_t i = 0; i < res.size(); ++i) {
        cout << '[';
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << '"' << res[i][j] << '"';
            if (j < res[i].size() - 1) cout << ',';
        }
        cout << ']';
        if (i < res.size() - 1) cout << ',';
    }
    cout << ']' << endl;

    return 0;
}




