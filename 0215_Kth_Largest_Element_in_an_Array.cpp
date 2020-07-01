#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* Medium */
// 思路：利用优先队列，可以维护一个有 K 个元素的最小堆;
class Solution {
public:
    void minHeapify(vector<int>& nums, int i, int len) {
        while ((i << 1) + 2 <= len) {
            int left = (i << 1) + 1;
            int right = (i << 1) + 2;
            int min = i;
            if(left < len && nums[left] < nums[i])
                min = left;
            if(right < len && nums[right] < nums[min])
                min = right;
            
            if(min != i) {
                swap(nums[min], nums[i]);
                i = min;
            } else break;
        }
    }

    void buildMinHeap(vector<int>& nums, int k) {
        for(int i = (k - 2) / 2; i >= 0; --i) {
            minHeapify(nums, i, k);
        }
    }

    void sortHeap(vector<int>& nums, int k) {
        int nums_len = nums.size();
        buildMinHeap(nums, k);
        for(int i = k; i < nums_len; ++i) {
            if(nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                minHeapify(nums, 0, k);
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k)
            return 0;
        
        sortHeap(nums, k);
        return nums[0];
    }
};

// 利用快排
class Solution_2 {
public:
    void swap(int&a,int&b)
    {
        int tem=a;
        a=b;
        b=tem;
    }
    int helper(vector<int>& nums,int left,int right,int d)
    {
        if(left>=right) return left;
        int len = right-left+1;
        srand(unsigned(time(NULL)));
        // int ans=left+random()%len;
        int ans=left+rand()%len;
        swap(nums[ans],nums[right]);
        int i=left;
        for(int j=left;j<=right-1;j++)
        {
            if(nums[j]<nums[right])
            {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
        if(d==i) return i;
        if(d>i) return helper(nums,i+1,right,d);
        else return helper(nums,left,i-1,d);        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int index=helper(nums,0,nums.size()-1,nums.size()-k);
        return nums[index];
    }
};