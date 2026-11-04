/*
给定一个整数数组 temperatures ，表示每天的温度，
返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// //暴力法
// vector<int> tem(vector<int>& temperauters){
//     int n = temperauters.size();
//     vector<int> days(n,0);
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             if (temperauters[j] > temperauters[i]){
//                 days[i] = j-i;
//                 break;
//             }
//         }
//     }
//     return days;
// }
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> index;
    vector<int> days(n, 0);
    for(int i = 0; i < n; i++){
        while (!index.empty() && temperatures[i] > temperatures[index.top()])
        {
            int prev = index.top();
            index.pop();
            days[prev] = i - prev; 

        }
        index.push(i);
    }
    return days;
}


int main(){
    vector<int> temperauters = {73, 74, 75, 71, 69, 72, 76, 73};
    // vector<int> ans = tem(temperauters);
    vector<int> ans = dailyTemperatures(temperauters);
    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}