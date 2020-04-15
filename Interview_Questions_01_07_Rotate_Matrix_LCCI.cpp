#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium  Microsoft */
// Strategy 1：先将矩阵以主对角线为轴交换元素，再对每一行以中点进行翻转
class Solution_1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        
        // 遍历主对角线右上方元素，交换元素，得到原矩阵转置矩阵
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 此时按行对折是顺时针旋转，按列对折是逆时针旋转，这里选择按行对折
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (n / 2); ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

// Strategy 2：按题意对左上角区域的点进行旋转
class Solution_2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        
        int r = (n >> 1) - 1; // (n/2)-1 左上角区域的最大行下标，
        int c = (n - 1) >> 1; // (n-1)/2 左上角区域的最大列下标，行列下标从 0 开始
        
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= c; ++j) {
                swap(matrix[i][j], matrix[j][n - i - 1]); // 将左上角元素与其水平右侧元素交换
                // 将左上角元素与其斜对角元素交换，满足两个坐标相加等于 n-1
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]); 
                swap(matrix[i][j], matrix[n - j - 1][i]); // // 将左上角元素与其正下方元素交换
            }
        }
    }
};
