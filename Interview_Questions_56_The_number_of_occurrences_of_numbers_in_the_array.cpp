#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution_1 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 一个数和0异或结果还是这个数本身
        int dif = 0;
        // 相同的数异或为0
        for (int num : nums)
            dif ^= num;

        int cmp = dif & (-dif); //cmp位保留最后一个1
        vector<int> ans(2, 0); //答案一个数的cmp位是1，一个是0
        for (int num : nums) {
            if (num & cmp) 
                ans[0] ^= num; //有cmp位的一组
            else 
                ans[1] ^= num; //没有的一组
        }
        return {ans[0], ans[1]};
    }
};

class Solution_2 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 一个数和0异或结果还是这个数本身
        int dif = 0; 
        for (int num : nums)
            dif ^= num;

        // int cmp = dif & (-dif); //cmp位保留最后一个1
        int cmp = 1;
        while ((cmp & dif) == 0) {
            cmp <<= 1;
        }
        
        // vector<int> ans(2, 0); //答案一个数的cmp位是1，一个是0
        // for (int num : nums) {
        //     if (num & cmp) 
        //         ans[0] ^= num; //有cmp位的一组
        //     else 
        //         ans[1] ^= num; //没有的一组
        // }
        int a = 0;
        int b = 0;
        for (int num : nums) {
            if (num & cmp) 
                a ^= num;
            else
                b ^= num;
        }
        // return {ans[0], ans[1]};
        return {a, b};
    }
};