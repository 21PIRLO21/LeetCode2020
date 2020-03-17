import List
from collections import Counter


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        """ 自己的答案，利用计数器 Counter """
        c = collections.Counter(nums)
        res = []
        for num, k in c.items():
            if k > 1:
                res.append(num)
        return res

        """和下面的方法比显得有点啰嗦"""
        # n=len(nums)
        # hashmap=[0]*n
        # result=[]

        # for num in nums:
        #     hashmap[num - 1] += 1
        # for i in range(n):
        #     if hashmap[i] > 1:
        #         result.append(i+1)
        # return result

        """为C++代码提供了一个方案"""
        # n = len(nums)
        # res = []
        # l = [0]*(n+1) # 多加一个int空间使得整个list变得更直观
        # for i in nums:
        #     l[i]+=1
        #     if l[i]>1:
        #         res.append(i)
        # return res
