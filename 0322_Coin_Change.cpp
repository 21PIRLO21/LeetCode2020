#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

// Note: You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    // int min(int a,int b){return a<b?a:b;}
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, amount + 1);
        table[0] = 0;
        
        int n = coins.size();
        for(int i = 0; i < table.size(); ++i){
            for(int j = 0; j < n; ++j){
                if(i - coins[j] < 0)
                    continue;
                table[i] = min(table[i], table[i - coins[j]] + 1);
            }
        }
        
        return (table[amount] == amount + 1) ? -1 : table[amount];

    }
};

/*
// 4ms答案
class Solution {
    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        {
            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }
    public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

};
*/
