#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int len = coins.size();
        // 相当于存在面值为0的硬币来初始化dp
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin : coins){
            for(int j = coin; j <= amount; ++j){
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};