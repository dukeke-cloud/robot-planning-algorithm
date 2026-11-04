/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); //保证把所有柱子都结算完
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    for(int i = 0; i < n; i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int h = heights[st.top()];
            st.pop();
            int left =(st.empty() ? -1 : st.top());
            int w = i - left - 1;
            maxArea = max(maxArea, (w * h));
        }
        st.push(i);
    }
    return maxArea;
    
}

int main(){
    vector<int> h = {2,1,5,6,2,3};
    int max_S = largestRectangleArea(h);
    cout << max_S;
    return 0;
}