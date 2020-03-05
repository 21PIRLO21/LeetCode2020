import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n <= 0:
            return []
        if n == 1:
            return [[1]]

        matrix = [[0 for _ in range(n)] for _ in range(n)]
        action = {
            'right': (0, 1),
            'down': (1, 0),
            'left': (0, -1),
            'up': (-1, 0)}
        count, total = 1, n*n

        i, j = 0, 0
        act = 'right'
        while count <= total:
            matrix[i][j] = count
            count += 1
            if i <= j and i+j == n-1 and act == 'right':
                act = 'down'
            elif i == j and i != 0 and act == 'down':
                act = 'left'
            elif i > j and i+j == n-1 and act == 'left':
                act = 'up'
            # elif (i-j == 1 and act == 'up') or i == 0:
            elif (i-j == 1 and act == 'up'):
                act = 'right'
            i += action[act][0]
            j += action[act][1]

        return matrix


#         if n == 1:
#             return [[1]]
#         res = [[0 for _ in range(n)] for x in range(n)]
#         l = 0
#         r = n-1
#         t = 0
#         b = n-1
#         tar = n*n
#         num = 0
#         while num < tar:
#             for l_r in range(l, r):
#                 num += 1
#                 res[t][l_r] = num
#             t += 1

#             for t_b in range(t-1, b):
#                 num += 1
#                 res[t_b][r] = num
#             r -= 1

#             for r_l in range(r+1, l, -1):
#                 num += 1
#                 res[b][r_l] = num
#             b -= 1

#             for b_t in range(b+1, t-1, -1):
#                 num += 1
#                 res[b_t][l] = num
#             l += 1

#             if num == tar-1:
#                 num += 1
#                 res[r][l] = num

#         return res


# class Solution:
#     def generateMatrix(self, n: int) -> List[List[int]]:
#         l, r, t, b = 0, n - 1, 0, n - 1
#         mat = [[0 for _ in range(n)] for _ in range(n)]
#         num, tar = 1, n * n
#         while num <= tar:
#             for i in range(l, r + 1): # left to right
#                 mat[t][i] = num
#                 num += 1
#             t += 1
#             for i in range(t, b + 1): # top to bottom
#                 mat[i][r] = num
#                 num += 1
#             r -= 1
#             for i in range(r, l - 1, -1): # right to left
#                 mat[b][i] = num
#                 num += 1
#             b -= 1
#             for i in range(b, t - 1, -1): # bottom to top
#                 mat[i][l] = num
#                 num += 1
#             l += 1
#         return mat
