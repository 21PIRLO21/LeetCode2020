#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/* Hard */
// stack
class Solution_1 {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};


// dp
// 作者：ping-yuan-hu-tong-jin-hai
// 链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/xiao-bai-lai-zuo-kun-nan-ti-xiao-xue-sheng-du-ke-y/
class Solution_2 {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        vector<int> dp(n, 0);
        int maxval=0;
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=2;
                    if(i-2>=0){
                        dp[i]=dp[i]+dp[i-2];
                    }
                }
                else if(dp[i-1]>0){
                    if((i-dp[i-1]-1)>=0 && s[i-dp[i-1]-1]=='('){
                        dp[i]=dp[i-1]+2;
                        if((i-dp[i-1]-2) >0){
                            dp[i]=dp[i]+dp[i-dp[i]];
                        }
                    }
                }
            }
            maxval = max(maxval,dp[i]);
        }
        return maxval;
    }
};

// 空间复杂度 O(1)
class Solution_3 {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                res = max(res, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                res = max(res, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return res;
    }
};