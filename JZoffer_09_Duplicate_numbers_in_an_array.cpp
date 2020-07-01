#include <iostream>
#include <vector>

using namespace std;

/* Easy */
// 类比LeetCode 41题：https://leetcode-cn.com/problems/first-missing-positive/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                // swap(nums[i], nums[nums[i]]);
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        return -1;
    }
};