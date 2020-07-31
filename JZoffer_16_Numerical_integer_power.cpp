#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
// 作者：yizhe-shi
// 链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/c-cheng-fa-kuai-su-mi-by-yizhe-shi/
/*
  我们这里使用快速幂进行求解。我们看一下 n 的二进制形式一定是若干个 1 和 0 构成，比如 9 = 1001 = 1*2^3 + 0*2^2 + 0*2^1 + 1*2^0
  x^9 = x^{2^0} * x^{2^1*0} * x^{2^2*0} * x^{2^3}
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1;
        double ans = 1;
        long num = n;
        if (n < 0) {
            num = -num;
            x = 1/x;
        }
        while (num) {
            if (num & 1) { // 当n对应位为 1 时进行累积，对应位为0时跳过
                ans *= x;
            }
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};