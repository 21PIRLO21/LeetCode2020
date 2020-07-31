#include <iostream>
#include <vector>

using namespace std;

/* 
 * 有序数组中的目标出现多次，
 * 利用二分查找返回在 最左侧 or 最右侧 出现的目标值。
 */
// 此解用于查找 最右侧 出现的target
int findRightest(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else { // 此处可以与 nums[mid] < target 合并为nums[mid] <= target，但是那样逻辑不够清晰
            // 查找 最右侧 就保持 right 边界不动，只移动 left
            left = mid + 1; // 精妙啊！！！
        }
    }
    // 精妙啊！！！
    if (nums[left - 1] == target) {
        return left - 1;
    }
    else {
        return -1;
    }
}


int main() {
    // vector<int> data = {2, 4, 5, 6, 6, 6, 6, 6, 7, 8, 8, 10};
    // cout << findRightest(data, 6) << endl;
    vector<int> data = {1, 1, 1, 1};
    cout << findRightest(data, 1) << endl;

    return 0;
}