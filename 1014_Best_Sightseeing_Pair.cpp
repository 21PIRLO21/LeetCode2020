#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* Medium */
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int tmp = A[0] + 0;
        int ans = INT_MIN;
        for (int j = 1; j < A.size(); j++) {
            // 既要保证ans最大，还要保证i和j的相对位置是i<j
            ans = max(A[j] - j + tmp, ans);
            tmp = max(A[j] + j, tmp);
        }
        return ans;
    }
};