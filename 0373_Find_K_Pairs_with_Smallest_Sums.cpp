#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty() || k <= 0)
            return {}; // 或者 return vector<vector<int>>();
        vector<vector<int>> res, edge;
        if(nums1.size() * nums2.size() <= k){
            for(int i = 0; i < nums1.size(); ++i)
                for(int j = 0; j < nums2.size(); ++j)
                    res.push_back({nums1[i], nums2[j]});
            return res;
        }
        
        int low = nums1.front() + nums2.front(), high = nums1.back() + nums2.back();
        int mid = 0;
        while(low < high){
            int t, count = 0;
            mid = low + ((high - low) >> 1);
            for(int i=0; i < nums1.size(); ++i){
                t = BSearch(nums2, mid - nums1[i]);
                if(t == 0)
                    break;
                count += t;
            }
            if(count < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        for(int i=0; i < nums1.size(); ++i){
            int t = BSearch(nums2, high-nums1[i]);
            if(t == 0) break;
            for(int j=0; j < t; ++j){
                if(nums1[i] + nums2[j] == high)
                    edge.push_back({nums1[i], nums2[j]});
                else
                    res.push_back({nums1[i], nums2[j]});
            }
        }
        // if(res.size() == k)
        //     return res;
        // else{
        //     while(res.size() != k){
        //        res.pop_back();
        //     }
        // }
        
        // while(res.size() != k){
        //     res.pop_back();
        // }
        // return res;
        
        while(res.size() < k){
            res.push_back(edge.back());
            edge.pop_back();
        }
        return res;
    }

    int BSearch(vector<int> &row, int target){
        int low = 0, high = row.size(), mid=0;
        while(low < high){
            mid = low + ((high - low) >> 1);
            if(target < row[mid])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};