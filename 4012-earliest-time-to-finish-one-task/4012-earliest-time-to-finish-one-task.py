class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        finish_times = [s + d for s, d in tasks]
        
        return int(min(finish_times))