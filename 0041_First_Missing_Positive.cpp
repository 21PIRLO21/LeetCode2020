#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 别人正确的解法
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                // 将nums[i] 放置到对应位置上[1,2,3...]
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
/*  // 自己的错误答案
    int firstMissingPositive(vector<int>& nums) {
        // int counter = 0;
        int n = nums.size();
        if(n == 0)
            return 1;
        if(n == 1 && nums[0] == 1)
            return 2;
        // vector<int> dummy;
        for(int i = 0; i < n; ++i){
            while(nums[i] != i){
                if(nums[i] < 0 || nums[i] >= n || nums[i] == nums[nums[i]])
                    break;
                // swap(nums, i, nums[i]);
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        
        for(int j = 1; j < n - 1; ++j){
            if(nums[j] != j)
                return j;
        }

        return nums[n - 1] > 0 ? n : 1;
    }

    void swap(vector<int> vect, int a, int b) {
        int temp;
        temp = vect[a];
        vect[a] = vect[b];
        vect[b] = temp;
    }
*/
};