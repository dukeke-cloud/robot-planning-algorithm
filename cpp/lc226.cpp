/*
二叉树反转
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}

};

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void preorder(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    TreeNode* ans = invertTree(root);
    preorder(ans);
    return 0;
}