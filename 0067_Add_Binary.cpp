#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Easy */
class Solution_1 {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        while (asize < bsize) {
            a = '0' + a;
            ++asize;
        }
        while (asize > bsize) {
            b = '0' + b;
            ++bsize;
        }

        int carry = 0;
        for (int i = asize - 1; i >= 0; --i) {
            int tempSum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = (tempSum % 2) + '0';//本位数值
            carry = tempSum / 2;
        }
        if (carry > 0) {
            a = '1' + a;
        }
        
        return a;
    }
};
// Author: 左
/* 优雅 */
class Solution_2 {
  public:
    string addBinary(string a, string b) {
        string str;
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
            int x = i < 0 ? 0 : a[i] - '0';
            int y = j < 0 ? 0 : b[j] - '0';
            int sum = (x + y + carry) % 2;
            carry = (x + y + carry) / 2;
            str.insert(0, 1, sum + '0');
        }
        return str;
    }
};