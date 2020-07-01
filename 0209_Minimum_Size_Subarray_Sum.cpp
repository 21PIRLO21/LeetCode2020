#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int temp = 0;
        int left = 0, right = 0;
        for ( ; right < n; ++right) {
            temp += nums[right];
            while (temp >= s) {
                res = min(res, right - left + 1);
                if (res == 1) return res;
                temp -= nums[left];
                ++left;
            }
        }
        // return left == 0 ? 0 : res;
        return res != INT_MAX ? res : 0;
    }
};