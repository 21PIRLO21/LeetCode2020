''' Hard '''
# 归并排序 + 索引数组
# Author: powcai
class Solution_1:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr = []
        res = [0] * len(nums)
        for idx, num in enumerate(nums):
            arr.append((idx, num))
        # arr = [enumerate(nums)] # arr[0] is a enumerate object
        

        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = merge_sort(arr[:mid])
            right = merge_sort(arr[mid:])
            # print(left, right)
            return merge(left, right)

        def merge(left, right):
            tmp = []
            i = 0
            j = 0
            while i < len(left) or j < len(right):
                if j == len(right) or i < len(left) and left[i][1] <= right[j][1]:
                    tmp.append(left[i])
                    res[left[i][0]] += j
                    i += 1
                else:
                    tmp.append(right[j])
                    j += 1
            return tmp

        merge_sort(arr)
        return res

# 树状数组
class BinaryIndexedTree:
    def __init__(self, nums):

        self.BIT_arr = [0] * (len(nums) + 1)
        # O(nlogn)
        # for i in range(len(nums)):
        #     self.updata(i, nums[i])
        # O(n)
        for i in range(len(nums)):
            self.BIT_arr[i + 1] = nums[i]
        for i in range(1, len(self.BIT_arr)):
            j = i + (i & -i)
            if j < len(self.BIT_arr):
                self.BIT_arr[j] += self.BIT_arr[i]
	# 更新,是指在i位置上加上 val
    def updata(self, i, delta):
        i += 1
        while i < len(self.BIT_arr):
            self.BIT_arr[i] += delta
            i += (i & (-i))
	# 重新赋值, 在i位置为val
    def setVal(self, i, val):
        i += 1
        self.updata(i, val - self.BIT_arr[i])

    def prefix(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.BIT_arr[i]
            i -= (i & (-i))
        return res


class Solution_2:
    def countSmaller(self, nums: List[int]) -> List[int]:
        hashTable = {v: i for i, v in enumerate(sorted(set(nums)))}
        # print(hashTable)
        tree = BinaryIndexedTree([0] * len(hashTable))
        res = []
        for i in range(len(nums) - 1, -1, -1):
            res.append(tree.prefix(hashTable[nums[i]] - 1))
            tree.updata(hashTable[nums[i]] , 1)
        
        return res[::-1]