#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 将队列按身高降序，同身高按k升序的规则调整
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] > b[0])
                return true;
            // if(a[0] == b[0])
            //     if(a[1] < b[1])
            //         return true;
            if(a[0] == b[0] && a[1] < a[1])
                return true;
            return false;
        });
        
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); ++i){
            res.insert(res.begin() + people[i][1], people[i]);
        }
        
        return res;
    }
};

// 在频繁插入场景下 list 的效率比 vector 高很多
/* class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序
        sort(people.begin(), people.end(),
                [](const vector<int>& lhs, const vector<int>& rhs)
                 {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];});
        int len = people.size();
        list<vector<int>> tmp;
        // 循环插入
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]); // 需要 iterator 头文件
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
*/