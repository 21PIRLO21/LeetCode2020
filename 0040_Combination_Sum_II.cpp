#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/* Medium */
class Solution_1 {
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> input;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        else if (target < 0) {
            return;
        }
        
        for (int i = start; i < input.size() && target - input[i] >= 0; i++) {
            if (i > start && input[i] == input[i - 1])
                continue; // 去重
            path.push_back(input[i]);
            DFS(i + 1, target - input[i]);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->input = candidates;
        // 颠倒上面两行的顺序
        // this->input = candidates;
        // std::sort(input.begin(), input.end());
        DFS(0, target);
        return res;
    }
};

// 加法
class Solution_2 {
public:
    vector<int> input;
    int target;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index, int sum) {
        // index >= input.size() ，写成 index == input.size() 即可
        // 因为每次都 + 1，在 index == input.size() 剪枝就可以了
        if (sum >= target || index == input.size()) {
            if (sum == target) {
                result.push_back(vc);
            }
            return;
        }
        for (int i = index; i < input.size(); i++) {
            if (input[i] > target) {
                continue;
            }

            // 【我添加的代码在这里】：
            // 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
            // 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
            // 因为前一个分支的候选集合一定大于后一个分支的候选集合
            // 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
            // “剪枝”的前提是排序，升序或者降序均可
            if (i > index && input[i - 1] == input[i]) {
                continue;
            }

            vc.push_back(input[i]);
            sum += input[i];
            dfs(i + 1, sum);
            vc.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // “剪枝”的前提是排序，升序或者降序均可
        std::sort(candidates.begin(), candidates.end());
        this->input = candidates;
        this->target = target;
        dfs(0, 0);
        return result;
    }
};


int main() {
    cout << "LeetCode 第 40 题：组合问题 II" << endl;
    Solution_2 solution = Solution_2();

    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    int target = 8;
    vector<vector<int>> res = solution.combinationSum2(candidates, target);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << "" << endl;
    }
    return 0;
}