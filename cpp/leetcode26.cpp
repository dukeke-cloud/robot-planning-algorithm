/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。

nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
*/

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    int slow = 1;
    for(int fast = 1; fast < nums.size(); fast++){
        if(nums[fast] != nums[slow - 1]){
            nums[slow] = nums[fast]; //nums[slow]代表新的数组
            slow++;
        }
    }        
    return slow;
}

int main(){
    vector<int> nums = {1,2,2,4,5,6};
    int k = removeDuplicates(nums);
    cout << k << endl;
    return 0;
}