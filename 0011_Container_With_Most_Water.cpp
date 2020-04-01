#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right, res, low, temp;
        int n = height.size();

        left = 0;
        right = n - 1;
        low = height[left] < height[right] ? left : right;
        res = (right - left) * height[low];

        while(left < right){
            if(low == left){
                ++left;
                low = height[left] < height[right] ? left : right;
            }
            else{
                --right;
                low = height[left] < height[right] ? left : right;
            }

            temp = (right - left) * height[low];
            res = temp > res ? temp : res;

            /* 更快，更简洁；
            res = max(res, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right])
                ++left;
            else
                --right;
            */
        }

        return res;
    }
};