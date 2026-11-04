/*
移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[slow]);
            slow++;
        }
    }
}

int main(){
    vector<int> nums={1,0,2,4,0,5};
    moveZeroes(nums);
    for(int n : nums){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}