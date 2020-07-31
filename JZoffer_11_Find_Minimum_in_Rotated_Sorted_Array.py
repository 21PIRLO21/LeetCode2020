from typing import List

''' Easy '''

class Solution_1:
    def minArray(self, numbers: List[int]) -> int:
        for i in range(1, len(numbers)):
            if numbers[i - 1] > numbers[i]:
                return numbers[i]
        return numbers[0]

# 二分查找
# 作者：LeetCode-Solution
# 链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/
# 考虑数组中的最后一个元素 x：
# 在最小值右侧的元素，它们的值一定都小于等于(<=) x；
# 而在最小值左侧的元素，它们的值一定都大于等于(>=) x。
class Solution_2:
    def minArray(self, numbers: List[int]) -> int:
        low, high = 0, len(numbers) - 1
        while low < high:
            pivot = low + (high - low) // 2
            if numbers[pivot] < numbers[high]:
                high = pivot 
            elif numbers[pivot] > numbers[high]:
                low = pivot + 1
            else:
                high -= 1
        return numbers[low]