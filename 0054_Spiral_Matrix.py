import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        res = []
        row = len(matrix)
        col = len(matrix[0])

        # if row == 1 and col == 1:
        #     return matrix

        # r -> right
        left, r, t, b = 0, col-1, 0, row-1
        temp = 0

        while True:
            for l_r in range(left, r+1):
                res.append(matrix[t][l_r])

            if t == b:
                break
            t += 1

            for t_b in range(t, b+1):
                res.append(matrix[t_b][r])

            if r == left:
                break
            r -= 1

            for r_l in range(r, left-1, -1):
                res.append(matrix[b][r_l])

            if b == t:
                break
            b -= 1

            for b_t in range(b, t-1, -1):
                temp += 1
                res.append(matrix[b_t][left])

            if left == r:
                break
            left += 1

        return res
