#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Hard */
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
// DP
class Solution_1 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // vector<vector<int>> 时间效率更高，但也更耗费存储空间
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

// 贪心
class Solution_2 {
public:
    bool isMatch(string s, string p) {
        auto allStars = [](const string& str, int left, int right) {
            for (int i = left; i < right; ++i) {
                if (str[i] != '*') {
                    return false;
                }
            }
            return true;
        };
        auto charMatch = [](char u, char v) {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*') {
            if (charMatch(s.back(), p.back())) {
                s.pop_back();
                p.pop_back();
            }
            else {
                return false;
            }
        }
        if (p.empty()) {
            return s.empty();
        }

        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size()) {
            if (p[pIndex] == '*') {
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex])) {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size()) {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else {
                return false;
            }
        }
        return allStars(p, pIndex, p.size());
    }
};

// the fastest
class Solution_3 {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i, ++j;//i，j向后瞬移
            } else if (j < n && p[j] == '*') {//记录如果之后序列匹配不成功时， i和j需要回溯到的位置
                iStar = i;//记录星号
                jStar = j++;//记录星号 并且j移到下一位 准备下个循环s[i]和p[j]的匹配
            } else if (iStar >= 0) {//发现字符不匹配且没有星号出现 但是istar>0 说明可能是*匹配的字符数量不对 这时回溯
                i = ++iStar;//i回溯到istar+1 因为上次从s串istar开始对*的尝试匹配已经被证明是不成功的（不然不会落入此分支） 所以需要从istar+1再开始试 同时inc istar 更新回溯位置
                j = jStar + 1;//j回溯到jstar+1 重新使用p串*后的部分开始对s串istar（这个istar在上一行已经inc过了）位置及之后字符的匹配 
            } else return false;
        }
        while (j < n && p[j] == '*') ++j;//去除多余星号
        return j == n;
    }
};