#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Medium */
class Solution_1 {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        // 下面这个 else if 可有可无
        else if (target < 0) { // candidates排序之后利用这里进行剪枝
            return;
        }
        
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            // 以下三行代码是回溯算法的典型结构
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back(); //该分支结束时去掉 i 号数，使其不影响“不选 i ”这一分支
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 对candidates进行排序的目的是避免出现重复的组合项
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        
        return res;
    }
};

// the fastest
class Solution_2 {
public:
    void combineSum(vector<int>& candidates, 
                    int index,
                    vector<int>& item,
                    int target, 
                    int curSum, 
                    vector<vector<int>>& res)
    {
        if (curSum > target)
            return;
        if (curSum == target){
            res.push_back(item);
            return;
        }   

        for (int i = index; i < candidates.size(); ++i){
            if (candidates[i] + curSum <= target){
                item.push_back(candidates[i]);
                combineSum(candidates, i, item, target, curSum + candidates[i], res);
                item.pop_back();
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        combineSum(candidates, 0, item, target, 0, res);

        return res;
    }
};