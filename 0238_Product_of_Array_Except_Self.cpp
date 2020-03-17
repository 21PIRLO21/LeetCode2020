#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int k = 1;
        // 先求前坐标左边数组的乘积
        for(int i = 0; i < n; ++i){
            res[i] *= k; // *= 性能比 res[i] = k; 好
            k *= nums[i];
        }

        // 再求当前坐标右边数组的乘积
        k = 1; 
        for(int j = n - 1; j >= 0; --j){
            res[j] *= k;
            k *= nums[j];
        }

        return res;
    }
};