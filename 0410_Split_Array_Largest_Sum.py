from typing import List

''' Hard '''
# https://leetcode-cn.com/problems/split-array-largest-sum/solution/er-fen-cha-zhao-by-coder233-2/
# 时间复杂度O(n×log(sum−maxn))，其中 sum 表示数组 nums 中所有元素的和，maxn 表示数组所有元素的最大值。
class Solution:
    def splitArray(self, nums: list, m: int) -> int:
        # 由于题目的返回要求：返回最小和的值
        # 最小和必然落在 [max(nums), sum(nums)] 之间
        # 我们可以使用二分来进行查找
        low, high = max(nums), sum(nums)
        while low < high:
            mid = (low + high) // 2
            # 淘汰算法
            # 我们由前向后对nums进行划分，使其子数组和 <= mid，然后统计满足条件的数组数量
            # 若我们选的sum值过小，则满足条件的数量 > m，目标值应落在 [mid+1, high]
            # 若我们选的sum值过大，则满足条件的数量 < m，目标值应落在 [low, mid-1]
            count = 0
            sub_sum = 0
            for i in range(len(nums)):
                sub_sum += nums[i]
                if sub_sum > mid:
                    count += 1
                    sub_sum = nums[i]
            # 注意：末尾还有一个子数组我们没有统计，这里把它加上
            count += 1
            if count > m:
                low = mid + 1
            else:
                high = mid
        return low

# C++版
# 示例

# 输入
# 5 3
# 1 4 2 3 5

# 输出
# 5

# 说明
# 分割成 1  4 |  2  3  |  5 的时候，3段的权重都是5，得到分割权重的最小值。
'''
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long low = arr[0];
    long high = 0;
    for (int i = 0; i < n; ++i) {
        high += arr[i];
        low = low < arr[i] ? arr[i] : low;
    }
    while (low < high) {
        long mid = (low +  high) / 2;
        int count = 0;
        int sub_sum = 0;
        for (auto i : arr) {
            sub_sum += i;
            if (sub_sum > mid) {
                ++count;
                sub_sum = i;
            }
        }
        ++count;
        if (count > m) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << low;
    return 0;
}
'''