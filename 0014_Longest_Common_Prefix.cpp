#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Easy */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        int len = strs[0].length(); 
        int index = strs.size(); // 字符串数组长度
        // 注意这里是按列优先检索的
        for (int i = 0; i < len; i++) {
            char temp = strs[0][i];
            for (int j = 0; j < index; j++) {
                if (i == strs[j].length() || strs[j][i] != temp)
                    return strs[0].substr(0, i);
            }
        }
        
        return strs[0];
    }
};