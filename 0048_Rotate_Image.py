""" Medium """
from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for i in range(n):
            for j in range(i, n):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        for i in range(n):
            matrix[i].reverse()

# C++版，很巧妙的双百答案
# class Solution {
# public:
#     void rotate(vector<vector<int>>& matrix) {
#         int n = matrix.size();
#         for(int i = 0; i < (n >> 1); ++i){
#             for(int j = i; j < n - 1 - i; ++j){
#                 swap(matrix[i][j], matrix[j][n - 1 - i]);
#                 swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
#                 swap(matrix[i][j], matrix[n - 1 - j][i]);
#             }
#         }
#     }
# };