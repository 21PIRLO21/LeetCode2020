import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # all in [0, zero) = 0
        # all in [zero, p) = 1
        # all in [two, len - 1] = 2

        if nums is None:
            return

        def swap(nums, left, right):
            nums[left], nums[right] = nums[right], nums[left]

        zero = 0
        p = 0

        lenth = len(nums)
        two = lenth

        while p < two:
            if nums[p] == 0:
                swap(nums, p, zero)
                zero += 1
                p += 1
            elif nums[p] == 1:
                p += 1
            else:
                two -= 1
                swap(nums, p, two)
