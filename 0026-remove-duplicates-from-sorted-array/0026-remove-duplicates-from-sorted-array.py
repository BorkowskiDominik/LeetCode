from collections import OrderedDict
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = OrderedDict.fromkeys(nums)
        return len(nums)