#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
class Solution_2 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N=nums.size();
        if(N==3)
          return nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int value=abs(nums[0]+nums[1]+nums[2]-target);
        int result=nums[0]+nums[1]+nums[2];
        for(int i=0;i<N-2;i++){
            int low=i+1;
            int high=N-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                int S=abs(sum-target);
                if(S<value){
                    value=S;
                    result=sum;
                }
                if(sum<target)
                  low++;
                else if(sum>target)
                  high--;
                else
                  return sum;
            }
        }
        return result;
    }
};