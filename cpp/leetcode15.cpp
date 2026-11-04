/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。

思路：
先排序
双指针，固定一个num[i],指针left = i + 1,指针right = n - 1;
计算num[i] + nums[left] + nums[right]
若sum < 0,则说明数值小了，left++;
若sum > 0,则说明数值大了，right--;
S
不重复需要保证每个指针指向的数值不能有重复的
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        //跳过重复的i
        //这里不能用i+1，遍历到n的时候i+1会越界
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum < 0){
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                ans.push_back({nums[i], nums[left], nums[right]});


                //跳过重复的left和right

                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }
                left++;
                right--;
                
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto& triple : ans) {
          cout << "[" << triple[0] << ", " << triple[1] << ", " << triple[2] << "]" << endl;
      }
    return 0;
}