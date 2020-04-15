#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* hard */
// 左指针+动态规划，时间复杂度O(n),空间复杂度O(n)
class Solution_1 {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int max_left = 0;
        int res = 0;
        // vector<int> max_right(height.size() - 2, 0);
        vector<int> max_right(height.size(), 0);
        
        // 将各个元素的右侧最高柱子的高度逐一统计，从优往左统计
        // for(int i = height.size() - 1; i > 0; --i){
        //     max_right[i - 1] = max(height[i], max_right[i]);
        // }
        for(int i = height.size() - 2; i >= 0; --i)
            max_right[i] = max(height[i + 1], max_right[i + 1]);
        
        // 逐一累加每根柱子对应的存水
        for(int k = 1; k < height.size() - 1; ++k){
            // 更新最大左侧柱子高度
            max_left = max(max_left, height[k - 1]);
            
            int min_ = min(max_left, max_right[k - 1]);
            if(height[k] < min_)
                res += min_ - height[k];
        }
        return res;
    }
};

// 双指针，时间复杂度O(n),空间复杂度O(1)
class Solution_2 {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        
        // int left = 1;
        // int right = height.length - 2; // 加右指针进去
        int left = 0;
        int right = height.size() - 1;
        
        
        int max_left = 0;
        int max_right = 0;
        int min_ = 0;
        int res = 0;
        for(int i = 1; i < height.size() - 1; ++i){
            //从左到右更
            if(height[left] < height[right]){
                max_left = max(max_left, height[left]);
                // min_ = min(max_left, max_right);
                min_ = max_left;
                if(height[left + 1] < min_)
                    res += min_ - height[left + 1];
                left++;
            }
            //从右到左更
            else{
                max_right = max(max_right, height[right]);
                // min_ = min(max_left, max_right);
                min_ = max_right;
                if(height[right - 1] < min_)
                    res += min_ - height[right - 1];
                right--;
            }
        }
        return res;
    }
};


// 动态规划
class Solution_3 {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		// left[i]表示i左边的最大值，right[i]表示i右边的最大值
		vector<int> left(n), right(n);
		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], height[i + 1]);
		}
		int water = 0;
		for (int i = 0; i < n; i++) {
			int level = min(left[i], right[i]);
			water += max(0, level - height[i]);
		}
		return water;
	}
};