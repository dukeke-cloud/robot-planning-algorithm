/*
字母异位词分组

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

示例：
输入: ["eat","tea","tan","ate","nat","bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

  - "eat"、"tea"、"ate" 是异位词（都是 a、e、t 三个字母）
  - "tan"、"nat" 是异位词
  - "bat" 单独一组
*/

#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(string& s : strs){
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto& kv : mp){
        ans.push_back(kv.second);
    }
    return ans;
}

int main(){
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(s);

    return 0;
}