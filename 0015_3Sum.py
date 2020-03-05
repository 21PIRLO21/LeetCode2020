# import bisect
import List


class Solution:
    # """
    # 时间复杂度O(n)
    # 自己学习学习
    # """
    # def threeSum(self, nums: List[int]) -> List[List[int]]:
    #     ans = []
    #     counts = {}
    #     # O(n)
    #     for num in nums:
    #         counts[num] = counts.get(num, 0) + 1

    #     # O(nlogn)
    #     nums = sorted(counts)

    #     # O(n)
    #     for i, num in enumerate(nums):
    #         if counts[num] > 1:
    #             if num == 0:
    #                 if counts[num] > 2:
    #                     ans.append([0, 0, 0])
    #             else:
    #                 if (- num * 2) in counts:
    #                     ans.append([num, num, - 2 * num])
    #         # 核心，观摩学习
    #         if num < 0:
    #             two_sum = - num
    #             left = bisect.bisect_left(nums, (two_sum - nums[-1]), i + 1)
    #           for i in nums[left : bisect.bisect_right(nums, (two_sum // 2)
    #           , left)]:
    #                 j = two_sum - i
    #                 if j in counts and j != i:
    #                     ans.append([num, i, j])

    #     return ans

    """
    自己的写法，时间复杂度O(n**2)
    """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        # 特判
        if n < 3:
            return []

        nums.sort()
        # elemSet = []
        for i in range(n):
            if nums[i] > 0:
                return res

            # 超时，学会利用有序数组本省有序的性质
            # if nums[i] in elemSet:
            #     continue
            # elemSet.append(nums[i])

            if (i > 0 and nums[i] == nums[i - 1]):
                continue

            lp = i + 1
            rp = n - 1

            while lp < rp:
                temp = nums[i]
                if (temp + nums[lp]) > 0:
                    break
                if nums[rp] < 0:
                    break

                temp += nums[rp]

                if (temp + nums[lp]) == 0:
                    while (lp < rp and nums[lp] == nums[lp + 1]):
                        lp += 1
                    while (lp < rp and nums[rp] == nums[rp - 1]):
                        rp -= 1
                    res.append([nums[i], nums[lp], nums[rp]])
                    # if [nums[i], nums[lp], nums[rp]] not in res:
                    #     res.append([nums[i], nums[lp], nums[rp]])

                    lp += 1
                    rp -= 1
                elif (temp + nums[lp]) > 0:
                    rp -= 1
                else:
                    lp += 1
        return res
