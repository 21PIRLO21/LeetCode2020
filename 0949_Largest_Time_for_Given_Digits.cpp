#include <ostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int hour, minute, dummy = -1, res_int = -1;
        // 向量A中四个元素的全排列数量是确定的，为24
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(i != j){
                    for(int k = 0; k < 4; ++k){
                        if(j != k && i != k){
                            int g = 6 - i - j - k;
                            hour = A[i] * 10 + A[j];
                            minute = A[k] * 10 + A[g];
                            if(hour < 24 && minute < 60)
                                dummy = hour * 60 + minute;
                            res_int = max(dummy, res_int);
                        }
                    }
                }
                
            }
        }
        if(res_int >= 0){
            char c[6];
            sprintf(c, "%.2d:%.2d", res_int / 60, res_int % 60);
            return (string)c;
        }
        return "";
    }
};