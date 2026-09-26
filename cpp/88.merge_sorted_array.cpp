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
