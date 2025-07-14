/**
 * Created by choucisan on 2025/7/14 15:17
 */

/*
 438. 找到字符串中所有字母异位词
 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
// 定义一个函数，用于找到字符串s中所有与字符串p相同的子串的起始位置
    vector<int> findAnagrams(string s, string p) {
        // 获取字符串s和p的长度
        int n = s.size(), m = p.size();
        // 如果字符串s的长度小于字符串p的长度，则返回空向量
        if(n<m) return{};
        // 定义两个向量，用于存储字符串s和p中每个字符出现的次数
        vector<int> maps(26);
        vector<int> mapp(26);
        // 定义一个向量，用于存储结果
        vector<int> res;
        // 遍历字符串p，统计每个字符出现的次数
        for(int i=0;i<m;++i){
            mapp[p[i]-'a']++;
        }
        // 遍历字符串s，统计每个字符出现的次数
        for(int i=0;i<n;++i){
            maps[s[i]-'a']++;
            // 如果当前遍历到的字符位置大于等于字符串p的长度减1
            if(i>=m-1){
                // 如果字符串s中从当前位置向前m个字符的子串与字符串p相同
                if(mapp==maps){
                    // 将当前位置减去字符串p的长度加1，即子串的起始位置，添加到结果向量中
                    res.push_back(i-m+1);
                }
                // 将当前位置向前m个字符的字符的次数减1
                maps[s[i-m+1] -'a']--;
            }
        }
        // 返回结果向量
        return res;
    }
};


int main(){
    Solution s;
    vector<int> res = s.findAnagrams("cbaebabacd","abc");
    cout<<'[';
    for(auto i:res){
        cout<<i;
        if(i<res[res.size()-1]) cout<<',';
    }
    cout<<']'<<endl;
}