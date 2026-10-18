/*
leetcode215:
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
#include <queue>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int findKthLargetst(vector<int>& nums, int k){
    /*
    greater: 是 C++ 标准库（<functional>头文件里）
    现成提供的一个「比较器」
    greater = greater than = 「大于」，所以它干的事就是 a > b
    */
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    for(int x : nums){
        minHeap.push(x);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int ans = findKthLargetst(nums, 4);
    cout << ans;
    return 0;
}
