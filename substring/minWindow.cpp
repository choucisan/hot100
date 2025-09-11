/**
 * Created by choucisan on 2025/9/9 13:39
 */

/*
  76. 最小覆盖子串
  给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
  注意：
  对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
  如果 s 中存在这样的子串，我们保证它是唯一的答案。
 */


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
/**
 * 最小覆盖子串问题解决方案
 * 使用滑动窗口技术找出字符串s中包含字符串t所有字符的最小窗口
 * @param s 主字符串，需要在其中查找最小窗口
 * @param t 目标字符串，需要被包含在窗口中
 * @return 返回s中包含t所有字符的最小子串，如果没有则返回空字符串
 */
    string minWindow(string s, string t) {
        // 初始化一个大小为128的数组，用于存储ASCII字符的需求计数
        // 每个字符初始计数为0
        vector<int> need(128,0);
        // 遍历目标字符串t，统计每个字符出现的次数
        for(char c : t) need[c]++;
        // 初始化滑动窗口的左边界、最小窗口的起始位置和最小窗口长度
        // minlen初始设为INT_MAX，确保任何找到的窗口都会比它小
        int left = 0,start = 0,minlen = INT_MAX;
        // count表示还需要匹配的字符数量，初始为t的长度
        // n是主字符串s的长度
        int count=t.size(),n=s.size();
        // 使用right作为滑动窗口的右边界，向右扩展窗口
        for(int right=0;right<n;++right){
            // 如果当前字符在t中存在，则减少计数
            if(need[s[right]]>0) count--;
            // 减少当前字符的需求计数（可能为负数，表示有多余的该字符）
            need[s[right]]--;

            // 当count为0时，表示当前窗口包含了t中的所有字符
            while(count==0){
                // 更新最小窗口信息
                if(right-left+1 < minlen){
                    minlen = right-left+1 ;  // 更新最小窗口长度
                    start = left;             // 记录最小窗口的起始位置
                }

                // 移动左边界，尝试缩小窗口
                need[s[left]]++;            // 增加左边界字符的需求计数
                if(need[s[left]]>0) count++; // 如果左边界字符是t中的必需字符，增加计数
                left++;                     // 左边界右移
            }
        }
        // 根据找到的最小窗口长度返回相应的子串
        // 如果minlen仍为INT_MAX，说明没有找到符合条件的窗口，返回空字符串
        return(minlen == INT_MAX)?  "" : s.substr(start,minlen);
    }
};


int main(){
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout<<s.minWindow(s1,s2)<<endl;
    return 0;
}