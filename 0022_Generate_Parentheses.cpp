#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        if(n == 0){
            res.push_back("");
            return res;
        }
        dfs("", n, n, res);
        return res;
    }

    /**
     * @param curStr 当前递归得到的结果
     * @param left   左括号还有几个可以使用
     * @param right  右括号还有几个可以使用
     * @param res    结果集
    **/
    void dfs(string curStr, int left, int right, vector<string> &res){
        if(left == 0 && right == 0){
            res.push_back(curStr);
            return;
        }
        
        // 左括号可用数目必须严格大于右括号
        if(left > right)
            return;
        
        if(left > 0){
            // dfs(curStr.append("("), left - 1, right, res); // 这么写递归有问题
            // curStr.append("(");
            // --left;
            // dfs(curStr, left, right, res);
            dfs(curStr + "(", left - 1, right, res);
        }
            
        if(right > 0){
            // dfs(curStr.append(")"), left, right - 1, res);
            // curStr.append(")");
            // --right;
            // dfs(curStr, left, right, res);
            dfs(curStr + ")", left, right - 1, res);
        }
            
    }
};

/* // 最快答案，也是学习string类的好例子
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        backtrack(ans, temp, n, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string& temp, int left, int right) {
        if(left == 0 && right == 0) {
            ans.push_back(temp);
            return;
        }
        if(left) {
            temp.push_back('(');
            backtrack(ans, temp, left - 1, right);
            temp.pop_back();
        }
        if(left < right) {
            temp.push_back(')');
            backtrack(ans, temp, left, right - 1);
            temp.pop_back();
        }
    }
};
*/