#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> numCounter(n + 1, 0);
        vector<int> res;
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            numCounter[temp] += 1;
        }

        for(int j = 1; j < n + 1; j++){
            if(numCounter[j] == 0)
                res.push_back(j);
        }
        return res;
    }

    /* 原地修改，空间复杂度O(1) */
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     int i;
    //     vector<int> v;
    //     for(i = 0; i < nums.size(); ++i)
    //     {
    //         if(nums[abs(nums[i]) - 1] > 0)
    //         {
    //             nums[abs(nums[i]) - 1] *= -1;
    //         }
    //     }
    //     for(i = 0; i < nums.size(); ++i)
    //     {
    //         if(nums[i] > 0)
    //         {
    //             v.push_back(i + 1);
    //         }
    //     }
    //     return v;
    // }
};
