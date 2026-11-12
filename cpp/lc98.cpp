/*
验证二叉搜索树

给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 严格小于 当前节点的数。
节点的右子树只包含 严格大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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


bool check(TreeNode* root, long minVal, long maxVal){
    if(root == nullptr) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;

    return check(root->left, minVal, root->val) && check(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return check(root, LONG_MIN, LONG_MAX);  
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    bool ans = isValidBST(root);
    if(ans)cout << "true" << endl;
    else cout << "false";
    return 0;
}