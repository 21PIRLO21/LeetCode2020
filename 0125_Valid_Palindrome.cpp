#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Easy */
class Solution_1 {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(!valid(s[l])) {
                ++l;
                continue;
            }
            if(!valid(s[r])) {
                --r;
                continue;
            }
            if(!isSame(s[l], s[r]))
                return false;
            ++l;
            --r;
        }
        return true;
    }
private:
    bool valid(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }

    bool isSame(char c1, char c2) {
        if(c1 >= 'A' && c1 <= 'Z')
            c1 = (char)(c1 - 'A' + 'a');
        if(c2 >= 'A' && c2 <= 'Z')
            c2 = (char)(c2 - 'A' + 'a');
        return c1 == c2;
    }
};

// 利用isalnum()函数
class Solution_2 {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};