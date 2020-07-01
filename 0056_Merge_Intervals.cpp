#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
class Solution_1 {
public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;
        }
        return ans;
    }
};


// the fastest
class Solution_2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先对区间 按照第一个元素的大小进行排序，保证第一个元素是有序的；
        // 使用start ,end 表示一个区间；
        // start 设置为第一个区间的第一个元素；
        // 比较 第一个区间的 第2个元素 与 第 2个区间的关系
        // a[1] < b[0] // 两个区间没有交集； end = a[1];  对第2个区间执行相同的判断逻辑；
        // a[1] >= b[0] <=b[1] // 存在交集， end = b[1]; 跳过第2个区间：
        // a[1] > b[1] // 包含第2个区间， end = a[1]; 同时跳过第2个区间;
        if (intervals.size() == 0 || intervals[0].size() <=1) {
            return intervals;
        }

        // 排序保证 第一个元素是有序的；
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            if (x[0] < y[0]) {
                return true;
            }
            return false;
        });

        vector<vector<int>> retVecs;
        vector<int> tempVec;
        for (auto& tempVec: intervals) {
            // 合并后数组为空
            if (retVecs.empty()) {
                retVecs.push_back(tempVec);
            } else if (retVecs.back()[1] < tempVec[0]) { // 最后一个区间与当前区间没有交集
                retVecs.push_back(tempVec);
            } else {
                // 当前区间的右值 大于 数组中最后一个区间的右值;
                if (retVecs.back()[1] < tempVec[1]) {
                    retVecs.back()[1] = tempVec[1];
                }
            }
        }

        return retVecs;
    }
};