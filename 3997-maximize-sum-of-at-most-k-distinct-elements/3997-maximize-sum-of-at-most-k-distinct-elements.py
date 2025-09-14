class Solution:
    def maxKDistinct(self, nums: List[int], k: int) -> List[int]:
        unique_values = set(nums)
        ordered = sorted(unique_values, key=lambda x: -x)
        limit = k if k < len(ordered) else len(ordered)
        
        return ordered[:limit]