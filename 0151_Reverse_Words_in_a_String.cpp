#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/* medium */
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin) {
            if (s[begin] != ' ') { //找到了下一个字符串的起点
                if (pos != 0) { //放一个空格做间隔
                    s[pos++] = ' ';
                }
                int end = begin;
                while (end < n && s[end] != ' ') { //前移
                    // s[pos++] = s[end++];
                    s[pos] = s[end];
                    ++pos;
                    ++end;
                }
                reverse(s.begin() + pos - (end - begin), s.begin() + pos); //局部反转
                begin = end;
            }
        }
        s.erase(s.begin() + pos, s.end()); //将末尾多余内容删除，包含多余的空格
        return s;
    }
};