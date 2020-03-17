#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if(n == 0)
            return res;
        
        int candidateA = nums[0], candidateB = nums[0]; 
        int countA = 0, countB = 0;
        
        // 第一遍遍历选出票数最高的两个候选者 candidateA和candidateB
        for(int i = 0; i < n; ++i){
            if(nums[i] == candidateA){
                countA += 1;
                continue;
            }
            
            if(nums[i] == candidateB){
                countB += 1;
                continue;
            }
            
            // 如果都不是的话，先看看A和B的票数是否为0，如果为0，则更新候选者
            if(countA == 0){
                candidateA = nums[i];
                countA += 1;
                continue;
            }
            if(countB == 0){
                candidateB = nums[i];
                countB += 1;
                continue;
            }
            
            // 如果都不是0，则两位的票数都 自减--
            --countA;
            --countB;
        }
        
        countA = countB = 0;
        for(int i = 0; i < n; ++i){
            if(candidateA == nums[i]){
                countA += 1;
                continue;
            }
            if(candidateB == nums[i]){
                countB += 1;
                continue;
            }
        }
        
        if(countA > n / 3)
            res.push_back(candidateA);
        // if(countB > n / 3 && candidateA != candidateB)
        //     res.push_back(candidateB);
        if(countB > n / 3)
            res.push_back(candidateB);
        
        return res;
    }
};