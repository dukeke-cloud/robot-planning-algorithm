/*
1.哈希表：一种“键->值”的存储结构，通过哈希函数吧key算成一个地址

两个主要容器
unordered_map<key, value>  存储键值对 
unordered_set<type> 只有键  

对应两个头文件
#include<unordered_map>
#include<unordered_set>

2.unorderde_map核心操作
unordered_map<string, int> mp;
mp["apple"] = 3; //插入，更新：key = apple, value = 3
mp["banana"];    // 访问：如果不存在，会自动插入 默认value = 0
mp["apple"]++;   //等价mp["apple"] = mp["apple"] + 1, 常用统计频率

mp.count("apple");  //判断key是否存在，存在返回1，不存在返回0
mp.rease("apple");  //删除
mp.size() //返回元素个数
mp.empty() //是否为空

3.遍历 unordered_map
for(auto& [key, value] : mp){
    cout << key << "->" << value << endl;
}

for(auto& kv : mp){
    cout << kv.first << "->" << kv.second << endl;
}

4.unordered_set核心操作
unordered_set<int> s;
s.insert(5);  //插入
s.earse(5);  //删除
s.count(5);  //判断是否存在
s.size(); //返回元素大小

5.常见用法
1.统计频率
unordered_map<int, int> freq;
for(int x : nums) freq[x]++;

2.分组
unordered_map<string, vector<string>> mp;
mp[key].push_back(s);

3.去重/查存在
unordered_set<int> seen;
if(seen.count(x)) seen.insert(x);

4.存补数快速查找
unordered_map<int, int> mp;
if(mp.count(target - x)){ }
mp[x] = i;
*/