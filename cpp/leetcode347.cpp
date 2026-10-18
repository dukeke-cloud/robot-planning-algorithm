/*
leetcode347:前K个高频元素
给你一个整数数组 nums 和一个整数 k ，
请你返回其中出现频率前 k 高的元素。
你可以按 任意顺序 返回答案。
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

// 返回出现频率前K个高频元素
vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> freq; //哈希表存储{k=元素，v=频次}
    for(int x : nums){
        freq[x]++;
    }

    //pair<type1, type2> p; 把两个不同（或相同）类型的值打包成一个整体，两个成员分别叫 `first` 和 `second`
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto& p : freq){
        minHeap.push({p.second, p.first});//second是频次，first是元素。小顶推根据频次排序
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    vector<int> res;
    while(!minHeap.empty()){
        //push_back()是vector的成员函数，：再vector的末尾追加一个元素
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;

}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums, 2);
    for(int x : ans){
        cout << '[' << x << ']';
    }
    return 0;
}