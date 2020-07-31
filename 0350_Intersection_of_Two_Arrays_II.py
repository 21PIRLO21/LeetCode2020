from collections import Counter

# sort
class Solution_1:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        
        res = []
        len1 = len(nums1)
        len2 = len(nums2)
        idx1 = 0
        idx2 = 0
        
        while idx1 < len1 and idx2 < len2:
            if nums1[idx1] < nums2[idx2]:
                idx1 += 1
            elif nums1[idx1] > nums2[idx2]:
                idx2 += 1
            else: 
                res.append(nums1[idx1])
                idx1 += 1
                idx2 += 1
        return res

# hash
class Solution_2:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        Hash = {}
        for i in range(len(nums1)):
            if nums1[i] not in Hash:
                # Hash 的可以是一个 list object
                Hash[nums1[i]] = [i]
            else:
                Hash[nums1[i]].append(i)
        res = []
        for j in range(len(nums2)):
            if nums2[j] in Hash:
                res.append(nums2[j])
                Hash[nums2[j]].pop()
                if Hash[nums2[j]] == []:
                    del Hash[nums2[j]]
        return res

# the fastest
class Solution_3:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        res = []
        for k, v in (Counter(nums1) & Counter(nums2)).items():
            for _ in range(v):
                res.append(k)
        return res