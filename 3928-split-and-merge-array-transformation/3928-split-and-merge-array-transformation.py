from typing import List

class Solution:
    def minSplitMerge(self, arr1: List[int], arr2: List[int]) -> int:
        if arr1 == arr2:
            return 0
        
        n = len(arr1)
        count_diff = Counter(arr1)
        count_diff.subtract(arr2)
        if any(count_diff.values()):
            return -1
        
        def make_key(lst):
            return ','.join(map(str, lst))
        
        target_key = make_key(arr2)
        seen = {make_key(arr1): 0}
        q = deque([arr1])
        
        while q:
            current = q.popleft()
            depth = seen[make_key(current)]
            
            for start in range(n):
                for end in range(start, n):
                    block = current[start:end+1]
                    rest = current[:start] + current[end+1:]
                    
                    for insert_pos in range(len(rest)+1):
                        if insert_pos == start:
                            continue
                        next_arr = rest[:insert_pos] + block + rest[insert_pos:]
                        key_next = make_key(next_arr)
                        if key_next not in seen:
                            if key_next == target_key:
                                return depth + 1
                            seen[key_next] = depth + 1
                            q.append(next_arr)
        
        return -1