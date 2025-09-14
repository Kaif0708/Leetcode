class Solution:
    MOD = 1_000_000_007

    def countStableSubsequences(self, nums: List[int]) -> int:
        # states: [odd_active, odd_passive, even_active, even_passive]
        state = [0, 0, 0, 0]

        for num in nums:
            if num & 1:  # odd branch
                next_state = [
                    (state[0] + 1 + state[2] + state[3]) % self.MOD,  # odd_active
                    (2 * state[1] + state[0]) % self.MOD - state[1], # odd_passive
                    state[2],                                         # even_active
                    state[3]                                          # even_passive
                ]
            else:        # even branch
                next_state = [
                    state[0],                                         # odd_active
                    state[1],                                         # odd_passive
                    (state[2] + 1 + state[0] + state[1]) % self.MOD,  # even_active
                    (2 * state[3] + state[2]) % self.MOD - state[3]   # even_passive
                ]

            # normalize modulo and assign
            state = [val % self.MOD for val in next_state]

        return sum(state) % self.MOD