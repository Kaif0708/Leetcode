class Solution:
    def evenNumberBitwiseORs(self, nums: List[int]) -> int:
        def is_even(x: int) -> bool:
            return (x & 1) == 0  

        answer = 0
        for value in filter(is_even, nums): 
            answer |= value

        return answer