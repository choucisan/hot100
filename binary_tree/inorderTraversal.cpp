/**
 * Created by choucisan on 2025/7/12 20:46
 */
/*
 94. 二叉树的中序遍历
 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
 */


#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
// 中序遍历二叉树
    vector<int> inorderTraversal(TreeNode* root) {
        // 定义一个vector用于存储遍历结果
        vector<int> res;
        // 调用中序遍历函数
        inorder(root,res);
        // 返回遍历结果
        return res;
    }
// 中序遍历二叉树
    void inorder(TreeNode* node,vector<int> &res){
        // 如果节点为空，则返回
        if(node== nullptr) return;
        // 递归遍历左子树
        inorder(node->left, res);
        // 将节点值加入结果向量
        res.push_back(node->val);
        // 递归遍历右子树
        inorder(node->right, res);
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = s.inorderTraversal(root);
    cout << '[';
    for (auto i: res) {
        cout << i << " ";
        if (i != res[res.size() - 1]) {
            cout << ',';
        }
    }
    cout << ']';
    return 0;
}
