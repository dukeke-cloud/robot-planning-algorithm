/*
leetcode88：合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
为了应对这种情况，nums1 的初始长度为 m + n，
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，
应忽略。nums2 的长度为 n 
*/

#include <vector>   
#include <iostream> 
#include <unordered_map>
using namespace std; 

// vector<int>& nums1是引用传递， merge函数需要修改外部参数nums1 ,所以需要使用&引用；
// vector<int> nums1是值传递（拷贝），编译器回复制一份全新的vector，只是在函数内部修改，不会改变函数外部变量的值
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    while(p2 >= 0){
        if(p1 >= 0 && nums1[p1] > nums2[p2]){
            nums1[p] = nums1[p1];  //把最大的放在数组后面
            p1--;
        }
        else{
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    merge(nums1, 3, nums2, 3);
    for(int x : nums1){
        cout << x << ' ';
    }
    
    return 0;
}
