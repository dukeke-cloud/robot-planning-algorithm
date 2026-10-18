#include <iostream>          // 输入输出，对应 Python 的 print
#include <vector>            // 动态数组，对应 Python 的 list
#include <unordered_map>     // 哈希表，对应 Python 的 dict
using namespace std;         // 让 std::vector 简写成 vector

/*
 * LeetCode 1. 两数之和
 * 给定数组 nums 和目标值 target，返回和为 target 的两个数的「下标」。
 * 算法：一遍哈希表，O(n) 时间。
 */

// 这里参数用vector<int>& nums 【引用传递】；相比直接用vector<int> nums【值传递】更省内存
// 引用传递操作原内存，值传递开辟新内存。
vector<int> twoSum(vector<int>& nums, int target) {
    // map<int, int> 有序，底层是红黑树，按照键值大小排序
    // unordered_map<int, int>：键=具体的值，值=索引，无序，底层是哈希表
    unordered_map<int, int> seen; //seen:常用命名，记录已经遍历过的数字

    // C++ 经典 for 循环：i 从 0 到 nums.size()-1
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];   // 需要的另一个数

        // seen.count(need) 判断 need 是否在哈希表里
        // see.count(key):key存在返回1，不存在返回0
        if (seen.count(need)) {
            // 返回两个下标：{a, b} 直接构造一个 vector<int>
            return {seen[need], i};
        }
        // 把当前数存进哈希表
        seen[nums[i]] = i;
    }

    return {};   // 没找到时返回空 vector
}

// main 是本地测试用的入口；提交到 LeetCode 时只需要上面的 twoSum 函数
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    // cout 输出，对应 Python 的 print；endl 表示换行
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;   // 程序正常结束
}
