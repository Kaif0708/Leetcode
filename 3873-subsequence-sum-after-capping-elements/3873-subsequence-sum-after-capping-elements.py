class Solution:
    def subsequenceSumAfterCapping(self, nums: List[int], k: int) -> List[bool]:
        size = len(nums)
        counts = [0] * (size + 1)
        for val in nums:
            if val <= size:
                counts[val] += 1

        
        at_least = [0] * (size + 2)
        running = 0
        for threshold in range(size, 0, -1):
            running += counts[threshold]
            at_least[threshold] = running

        outcome = [False for _ in range(size)]

        dp_possible = [False] * (k + 1)
        dp_possible[0] = True

        for threshold in range(1, size + 1):
            cap_count = at_least[threshold]

            feasible = False
            max_take = min(cap_count, k // threshold)
            for take in range(max_take + 1):
                rest = k - take * threshold
                if dp_possible[rest]:
                    feasible = True
                    break
            outcome[threshold - 1] = feasible

            copies = counts[threshold]
            while copies > 0:
                for target in range(k, threshold - 1, -1):
                    if dp_possible[target - threshold]:
                        dp_possible[target] = True
                copies -= 1

        return outcome