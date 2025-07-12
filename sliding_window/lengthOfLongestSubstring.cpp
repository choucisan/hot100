/**
 * Created by choucisan on 2025/7/12 20:09
 */
/*
 3.无重复字符的最长子串
 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
// 计算字符串中最长不重复子串的长度
    int lengthOfLongestSubstring(string s) {
        // 创建一个哈希表，用于存储字符及其在字符串中的位置
        unordered_map<char,int>hashtable;
        // 获取字符串的长度
        int n = s.size();
        // 初始化最长子串长度为0
        int nums=0;
        // 初始化左指针为0
        int left=0;
        // 遍历字符串
        for(int i=0;i<n;++i){
            // 如果哈希表中存在当前字符，并且该字符的位置大于等于左指针
            if(hashtable.count(s[i])&& hashtable[s[i]]>=left){
                // 更新左指针为该字符的位置加1
                left=hashtable[s[i]]+1;
            }
            // 将当前字符及其位置存入哈希表
            hashtable[s[i]]=i;
            // 更新最长子串长度
            nums=max(nums,i-left+1);
        }
        // 返回最长子串长度
        return nums;
    }
};


int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}



