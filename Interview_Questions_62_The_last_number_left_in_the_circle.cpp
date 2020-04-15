#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* easy */
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0; // 为什么初始化为0？
        for(int i = 2; i <= n; ++i)
            res = (res + m) % i; // 循环右移
        
        return res;
    }
};