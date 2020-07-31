#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Easy */
class Solution_1 {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) return res;
        if (shorter == longer) {
            res.push_back(k * shorter);
            return res;
        }
        
        for (int i = 0; i <= k; ++i) {
            res.push_back(i * longer + (k - i) * shorter);
        }
        return res;
    }
};

// the fastest
class Solution_2 {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) {
            return vector<int> {};
        }
        if(shorter == longer) {
            return vector<int> {shorter * k};
        }
        
        vector<int> vec(k + 1);
        for(int i = 0; i <= k; i++) {
            vec[i] = (k - i) * shorter + i * longer;
        }
        return vec;
    }
};