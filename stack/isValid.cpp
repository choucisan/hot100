/**
 * Created by choucisan on 2025/7/12 21:32
 */
/*
 20. 有效的括号
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 有效字符串需满足：
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 每个右括号都有一个对应的相同类型的左括号。
 */


#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 定义一个栈
        stack<char> stk;
        // 遍历字符串
        for(char ch : s){
            // 如果字符是左括号，则入栈
            if(ch == '(' || ch == '[' || ch == '{' ){
                stk.push(ch);
            }
            // 如果字符是右括号
            else {
                // 如果栈为空，则返回false
                if(stk.empty()) return false;
                // 获取栈顶元素
                char top = stk.top();
                // 如果栈顶元素和当前字符不匹配，则返回false
                if (ch == ')' && top != '(' ||
                    ch == ']' && top != '[' ||
                    ch == '}' && top != '{' ) {return false;}
                // 弹出栈顶元素
                stk.pop();
            }
        }
        // 如果栈为空，则返回true，否则返回false
        return stk.empty();

    }
};

int main(){
    Solution s;
    cout << boolalpha;
    cout << s.isValid("()[]{}") << endl;
    return 0;
}