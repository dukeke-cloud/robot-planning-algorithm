#include <iostream>          // 输入输出，对应 Python 的 print
#include <vector>            // 动态数组，对应 Python 的 list
#include <unordered_map>     // 哈希表，对应 Python 的 dict
using namespace std;         // 让 std::vector 简写成 vector

/*
 * LeetCode 1. 两数之和
 * 给定数组 nums 和目标值 target，返回和为 target 的两个数的「下标」。
 * 算法：一遍哈希表，O(n) 时间。
 */
vector<int> twoSum(vector<int>& nums, int target) {
    // unordered_map<int, int>：键=数值，值=下标
    // 对应 Python 的 dict：{数值: 下标}
    unordered_map<int, int> seen;

    // C++ 经典 for 循环：i 从 0 到 nums.size()-1
    // nums.size() 对应 Python 的 len(nums)
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];   // 需要的另一个数

        // seen.count(need) 判断 need 是否在哈希表里
        // 对应 Python 的：if need in seen
        if (seen.count(need)) {
            // 返回两个下标：{a, b} 直接构造一个 vector<int>
            // 对应 Python 的：return [seen[need], i]
            return {seen[need], i};
        }

        // 把当前数存进哈希表
        // 对应 Python 的：seen[nums[i]] = i
        seen[nums[i]] = i;
    }

    return {};   // 没找到时返回空 vector（题目保证有解，这行几乎不执行）
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
