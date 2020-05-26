#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution_1 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> pos;
        pos.push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) {
                pos.push_back(i);
            }
        }
        pos.push_back(nums.size());

        int res = 0;
        for (int i = 1; i < (int)pos.size() - k; i++) {
            res += (pos[i] - pos[i - 1]) * (pos[i + k] - pos[i + k - 1]);
        }

        return res;
    }
};


class Solution_2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    vector<int> even;
    int len = 0;
    int even_cnt = 0;
    int first_odd = -1;
    int last_odd = 0;

    //神奇的思路  记录每个奇数前面的偶数个数，没有就填0  //两次遍历 O（2N）
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 1) {
            even.push_back(even_cnt);
            even_cnt = 0;
        }
        else {
            even_cnt++;
        }
    }
    even.push_back(even_cnt);
    int res = 0;
    if (even.size() >= k) {
        for (int i = k; i < even.size(); i++) {
            res += (even[i] + 1) * (even[i - k] + 1);
        }
        return res;
    }
    else return 0;
    }
};