/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums){
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for(int num : s){
        if(!s.count(num - 1)){ //避免在下一轮重复计算上一轮的元素
            int cur = num;
            int length = 0;
            while(s.count(cur)){
                cur++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}
        


int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int longest = longestConsecutive(nums);
    cout << longest;
    return 0;
}