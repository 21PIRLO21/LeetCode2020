from typing import List
# from collections import Counter


class Solution:
    """自己的答案--利用机器逻辑来解"""
    def findDuplicate(self, nums: List[int]) -> int:
        numsDict = {}
        for num in nums:
            numsDict[num] = numsDict.get(num, 0) + 1
            if numsDict[num] > 1:
                return num

# class Solution:
# """利用Python高性能容器Counter来优化"""
#     def findDuplicate(self, nums: List[int]) -> int:
#         numFreq = collections.Counter(nums)
#         for num, freq in numFreq.items():
#             if freq > 1:
#                 return num

# class Solution:
# """结合容器自身方法来优化"""
#     def findDuplicate(self, nums: List[int]) -> int:
#         c = collections.Counter(nums)
#         return c.most_common()[0][0]

# class Solution:
# """利用数学逻辑来解"""
#     def findDuplicate(self, nums: List[int]) -> int:
#         return (sum(nums)-sum(set(nums))) // (len(nums) - len(set(nums)))
