#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        
        int cnt = 0;
        /*while (cnt < n - 1) {
            int temp = cnt;
            cnt += nums[cnt];
            if (temp == cnt) {
                return false;
            }
        }
        if (cnt == n - 1) {
            return true;
        }
        else {
            return false;    
        }*/
        for (int i = 0; i < n; ++i) {
            if (cnt < i) {
                return false;
            }
            // 实时更新，cnt不需要一下就算到最大可跳跃距离
            cnt = max(cnt, i + nums[i]);
        }
        return true;
    }
};