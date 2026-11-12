/*
二叉树的层序遍历

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

思路：队列 + 记录每层大小
1.先把根节点入队
2.每次处理一层：先记录当前队列大小（作为当前层的节点数levelSize）， 
3.遍历当前层中的节点元素：记录当前节点元素，然后弹出这节点元素，把当前元素的值加入到当前层的动态数组thisLevel中，同时把他们的左右孩子节点入队，供下一层用
4.重复，直至队列空
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {} 
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root == nullptr) return ans;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> thisLevel;
        for(int i = 0; i < levelSize; i++){
            TreeNode* node = q.front();
            q.pop();
            thisLevel.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(thisLevel);
    }
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<vector<int>> ans = levelOrder(root);
    for(vector<int> a : ans){
        cout << "[";
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}