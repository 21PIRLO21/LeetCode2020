#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/* Medium */
class Solution_1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 学习一下auto的用法
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

class Solution_2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> restStr;
        vector<int> visited(s.size() + 1, false);
        restStr.push(0);
        visited[0] = true;
        int strLen = s.size();
        while(!restStr.empty()) {
            int start = restStr.front(); // start是 该次循环中substr的开始位
            restStr.pop();
            for(int i = 0; i < wordDict.size(); i++) {
                int len = wordDict[i].size();
                if (start + len > strLen) continue;
                if(visited[start + len] == true) continue;  //cut branch
                if (s.substr(start, len) == wordDict[i]) {
                    if (start + len == strLen) return true;
                    restStr.push(start + len); // start+len是符合要求的substr结束标志位
                    visited[start + len] = true;
                }
            }
        }
        return false;
    }
};

// the fastest
class Solution_3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (string word: wordDict) {
                if (i >= word.size()) {
                    dp[i] = (dp[i - word.size()] && (s.substr(i - word.size(), word.size()) == word));
                    if (dp[i]) break;
                }
            }
        }
        return dp.back();
    }
};