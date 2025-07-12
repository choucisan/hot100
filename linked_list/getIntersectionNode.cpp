/**
 * Created by choucisan on 2025/7/12 20:35
 */
/*
 160. 相交链表
 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
 图示两个链表在节点 c1 开始相交
 题目数据 保证 整个链式结构中不存在环。
 注意，函数返回结果后，链表必须 保持其原始结构 。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 如果headA或headB为空，则返回空
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        // 定义两个指针pA和pB，分别指向headA和headB的头节点
        ListNode *pA = headA;
        ListNode *pB = headB;
        // 当pA和pB不相等时，循环执行以下操作
        while (pA != pB){
            // 如果pA为空，则将pA指向headB的头节点
            pA = pA== nullptr ? headB : pA->next;
            // 如果pB为空，则将pB指向headA的头节点
            pB = pB== nullptr ? headA : pB->next;
        }
        // 返回pA，即pA和pB相遇的节点
        return pA;
    }
};


int main(){
    Solution s;
    ListNode *inter = new ListNode(8);
    inter->next = new ListNode(4);
    inter->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = inter;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = inter;

    ListNode *res = s.getIntersectionNode(headA, headB);
    cout << res->val << endl;
    return 0;

}
