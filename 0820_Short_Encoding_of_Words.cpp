#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        
        vector<string> reversed_words;
        for(string word : words){
            reverse(word.begin(), word.end()); // reverse()需要#include <algorithm>
            reversed_words.push_back(word);
        }
        // 字典序排序 
        sort(reversed_words.begin(), reversed_words.end());
        
        int res = 0;
        for(int i = 1; i < n; ++i){
            // subWord只能是母词的后缀，出现在中间是不行的
            if(reversed_words[i].find(reversed_words[i - 1]) == 0)
                continue;
            else
                res += reversed_words[i - 1].length() + 1; // '#'需要占一个字符
        }
        
        return res + reversed_words[n - 1].length() + 1;
    }
};

/* 能优化空间复杂度的方法，欣赏一下 */
// static bool compare(string& s1, string& s2) {
//     int N1 = s1.length();
//     int N2 = s2.length();
//     for (int i = 0; i < min(N1, N2); i++) {
//         char c1 = s1[N1-1-i];
//         char c2 = s2[N2-1-i];
//         if (c1 != c2) {
//             return c1 < c2;
//         }
//     }
//     return N1 < N2;
// }

// int minimumLengthEncoding(vector<string>& words) {
//     int N = words.size();
//     // 逆序字典序排序    
//     sort(words.begin(), words.end(), compare);

//     int res = 0;
//     for (int i = 0; i < N; i++) {
//         if (i+1 < N && endsWith(words[i+1], words[i])) {
//             // 当前单词是下一个单词的后缀，丢弃
//         } else {
//             res += words[i].length() + 1; // 单词加上一个 '#' 的长度
//         }
//     }
//     return res;
// }

// bool endsWith(string& s, string& t) {
//     int N1 = s.length();
//     int N2 = t.length();
//     if (N1 < N2) {
//         return false;
//     }
//     for (int i = 0; i < N2; i++) {
//         if (s[N1-N2+i] != t[i]) {
//             return false;
//         }
//     }
//     return true;
// }