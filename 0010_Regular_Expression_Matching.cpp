#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Hard */
// 作者：OrangeMan
// 链接：https://leetcode-cn.com/problems/regular-expression-matching/solution/cjian-ji-dai-ma-ti-jie-ming-tian-xie-by-orangeman/
class Solution_1 {
public:
    bool isMatch(string s, string p) {
        // return match(s.data(), p.data()); // 替换
        return match(s.c_str(), p.c_str());
    }
    // bool match(char* s, char* p) { // 替换
    bool match(const char* s, const char* p) {
        if (!*p) return !*s;
        if (*(p + 1) != '*') 
            return *s == *p || (*p == '.' && *s != '\0') ? match(s + 1, p + 1) : false; 
        else 
            return *s == *p || (*p == '.' && *s != '\0') ? match(s, p + 2) || match(s + 1, p) : match(s, p + 2);
            //或者return (*s == *p || (*p == '.' && *s != '\0')) && match(s + 1, p) || match(s, p + 2);
    }
};

// the fastest
class Solution_2 {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        // const int sLen_c = sLen;
        // const int pLen_c = pLen;

        // int dp[(const int)sLen+1][(const int)pLen+1];
        // int dp[sLen_c+1][pLen_c+1];
        int dp[sLen+1][pLen+1];
        memset(dp, 0, sizeof(int)*(sLen+1)*(pLen+1));

        dp[0][0] = 1;
        for(int i =0; i < pLen; i+=2)
        {
            if(p[i] == '*')
                dp[0][i+1] = 1;
            else if(p[i+1] == '*')
                dp[0][i+2] = 1;
            else
                break;
        }

        for(int n = 1; n <= sLen; n++) {
            for(int m = 1; m <= pLen; m++) {
                if(s[n-1] == p[m-1])
                    dp[n][m] = dp[n-1][m-1];
                else if(p[m-1] == '.')
                    dp[n][m] = dp[n-1][m-1];
                else if(p[m-1] == '*')
                {
                    if(p[m-2] == '.' || p[m-2] == s[n-1])
                    {
                        dp[n][m] = dp[n-1][m] | dp[n][m-1] | dp[n][m-2];
                    }
                    else
                        dp[n][m] = dp[n][m-2];
                }
            }
        }
        return dp[sLen][pLen];
    }
};