/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

思路：
滑动窗口
左指针left从0开始
右指针right也从0开始，遍历所有元素，作为新加入的元素
用哈希集合存储子串
若当前集合中已经有新加入的元素，从左开始删，直到该集合中没有新加入的元素right
将right加入集合
更新maxLen
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0;
    int maxLen = 0;

    for(int right = 0; right < s.size(); right++){
        while (window.count(s[right]) > 0) //判断新加入的字符是否在已有的字符串里面
        {
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]); //插入新的字符
        maxLen = max(maxLen, right - left + 1);
        
    }
    return maxLen;
}


int main(){
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}