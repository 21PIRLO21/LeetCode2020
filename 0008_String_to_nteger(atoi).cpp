#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/* medium */
/*
我觉得比较难搞的两个点：

    在转化过程中防止超过 MAX。
    求得int的最大值和最小值。

对于第一点，有 res * 10 + curVal <= MAX，转化一下 res <= (MAX - curVal)/10 。
对于第二点，可以考虑位运算，但直接左移31位会影响符号位，所以分三步走。

    先将 1 左移30位，然后减一。此时二进制为 0011111111111111111111111111，即两个0 和 30 个1。
    左移一位。此时二进制为 0111111111111111111111111110，即一个 0 和 30 个1 和 1 个 0。
    然后加一。

最小值可以由最大值做减法得到(即 MIN = - MAX - 1;)。

作者：Time-Limit
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/c-wei-yun-suan-qiu-zui-da-zhi-ji-bai-shuang-bai-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int myAtoi(string str) {
        const char *p = str.c_str();
        for ( ; p != nullptr && *p == ' '; p++) {}

        // 这一条判断其实可以省略，因为后面 res初始化刚好是0。
        if (p == nullptr || (*p != '+' && *p != '-' && (*p < '0' || *p > '9'))) {
            return 0;
        } 

        int res = 0, flag = 1;
        if (*p == '-') {
            flag = -1;
            p++;
        } else if (*p == '+') {
            p++;
        }
        int MAX = (((1 << 30) - 1) << 1) + 1;
        int MIN = - MAX - 1;
        for (; '0' <= *p && *p <= '9'; p++) {
            if ((MAX - (*p - '0')) / 10 < res) {
                if (flag == -1) {
                    return MIN;
                } else {
                    return MAX;
                }
            }
            // res = res * 10 + (*ptr - '0');
            (res *= 10) += *p - '0';
        }
        return res * flag;
    }
};