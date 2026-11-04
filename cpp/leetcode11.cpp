#include<iostream>
#include<vector>
using namespace std;

//暴力法
/*
int maxAera(vector<int>& heights){
    int n = heights.size();
    int max_aera = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            max_aera = max(max_aera, ((j-i) * min(heights[j], heights[i]))); 
        }
    }
    return max_aera;
}
*/

//高低指针
int maxArea(vector<int>& heights){
    int left = 0;
    int right = heights.size() - 1;
    int maxarea = 0;
    while(left < right){
        maxarea = max(maxarea, (right - left) * min(heights[left], heights[right]));
        if(heights[left] < heights[right]){
            left ++;
        }
        else{
            right--;
        }
    }
    return maxarea;


}

int main(){
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(heights);
    cout << ans << endl;
    return 0;
}
