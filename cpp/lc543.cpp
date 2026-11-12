/*
二叉树的直径
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {} 
};

int maxDiameter = 0;

//得到最大深度
int depth(TreeNode* root){
    if(root == nullptr) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    maxDiameter = max(maxDiameter, left + right);
    return max(left, right) + 1;
}

int getMaxD(TreeNode* root){
    depth(root);
    return maxDiameter;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int max_d = getMaxD(root);
    cout << max_d;
    return 0;
}