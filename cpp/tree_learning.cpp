/*
1.二叉树基础
每个节点最多有两个子节点：左孩子 left 和右孩子 right。
          1          ← 根节点 root
         / \
        2   3        ← 1 的左孩子是 2，右孩子是 3
       / \   \
      4   5   6      ← 叶子节点（没有孩子的节点）

2.TreeNode结构体
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
}

3.三种遍历
前序：preorder 顺序：根->左->右 124536
中序：inorder 顺序：左->根->右  425136
后序：postorder 顺序：左->右->根  452631

4.递归
任何递归都满足三要素：
1.终止条件： if(root == nullptr) return;
2.处理当前节点： cout << root->val;
3.递归子问题： preordered(root->left)、preordered(root->right)
前序遍历：
void preordered(TreeNode* root){
    if(root == nullptr) return;
    cout << root->val << " ";  //先处理根
    preordered(root->left);    //再处理左
    preordered(root->right);   //再处理右
}
*/

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}

};

void preorder(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}