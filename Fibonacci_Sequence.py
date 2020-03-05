class Solution:
    # 非递归
    def fib(self, n: int) -> int:
        a, b = 0, 1
        temp = 0
        for _ in range(n):
            temp = a
            a = b
            b = temp + b
        return a % 1000000007

# class Solution:
#     def fib(self, n: int) -> int:
#         a, b = 0, 1
#         for _ in range(n):
#             a, b = b, a + b
#         return a % 1000000007


"""
# 递归 -- 超时
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return (self.fib(n-1) + self.fib(n-2))
"""
