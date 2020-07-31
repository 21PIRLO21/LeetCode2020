#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* Medium */
class Solution_1 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// the fastest
class Solution_2 {
public:
    const int mod = 1000000009;
    const int base = 113;
    long long Qpow(long long x, long long n) {
        if (n < 0) n += mod - 1;
        long long ret = 1;
        while (n) {
            if (n & 1) ret = ret * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }
    bool check(vector<int>& A, vector<int>& B, int len) {
        long long hashA = 0;
        for (int i = 0; i < len; i++) {
            hashA = (hashA * base + A[i]) % mod;
        }
        unordered_set<long long> bucketA;
        bucketA.insert(hashA);
        long long mult = Qpow(base, len - 1);
        for (int i = len; i < A.size(); i++) {
            hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
            bucketA.insert(hashA);
        }
        long long hashB = 0;
        for (int i = 0; i < len; i++) {
            hashB = (hashB * base + B[i]) % mod;
        }
        if (bucketA.count(hashB)) {
            return true;
        }
        for (int i = len; i < B.size(); i++) {
            hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
            if (bucketA.count(hashB)) {
                return true;
            }
        }
        return false;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int left = 0, right = min(A.size(), B.size()) + 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(A, B, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// 滑动窗口解法
// Reference: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/wu-li-jie-fa-by-stg-2/
class Solution_3 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return A.size()<=B.size()?helper(A,B):helper(B,A);
    }
        //窗口滑动的重叠过程可以分为三个过程：
        //1、下面子串进入，开始重叠的过程，重叠长度增加
        //2、上下两子串完全重叠，中间过程，重叠长度不变
        //3、下面的子串开始离开，重叠长度减少
    int helper(vector<int>& A,vector<int>& B){
        int na=A.size();
        int nb=B.size();
        int ret=0;
        //进入时候的处理
        for(int len=1;len<=na;len++){ // len 为重叠长度
            int tmplen=maxlen(A,0,B,nb-len,len);
            ret=max(ret,tmplen);
        }
        //中间过程的处理
        for(int indexb=nb;indexb-na>=0;indexb--){ // 此时重叠长度恒为na
            int tmplen=maxlen(A,0,B,indexb-na,na);
            ret=max(ret,tmplen);
        }
        //出去时的处理
        for(int len=na;len>0;len--){ // len 为重叠长度
            int tmplen=maxlen(A,na-len,B,0,len);
            ret=max(ret,tmplen);
        }
        return ret;
    }
    int maxlen(vector<int>& A,int indexa,vector<int>& B,int indexb,int len){
        int ret=0;
        int countnum=0;
        for(int i=0;i<len;i++){
            if(A[indexa+i]==B[indexb+i]){
                countnum++;
            }
            else if(countnum>0){
                ret=max(ret,countnum);
                countnum=0;
            }
        }
        return max(ret,countnum);
    }
};