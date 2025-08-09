class Solution:
    def countCells(self, grid: List[List[str]], pattern: str) -> int:
        m = len(grid)
        n = len(grid[0])
        p_len = len(pattern)
        horz_matches = set()
        vert_matches = set()
        count = 0

        for r in range(m):
            for c in range(n):
                # Check horizontal
                horz_str = ""
                curr_r = r
                curr_c = c
                for _ in range(p_len):
                    horz_str += grid[curr_r][curr_c]
                    curr_c += 1
                    if curr_c == n:
                        curr_c = 0
                        curr_r += 1
                        if curr_r == m:
                            break

                if len(horz_str) == p_len and horz_str == pattern:
                    curr_r = r
                    curr_c = c
                    for _ in range(p_len):
                        horz_matches.add((curr_r, curr_c))
                        curr_c += 1
                        if curr_c == n:
                            curr_c = 0
                            curr_r += 1

        for c in range(n):
            for r in range(m):
                # Check vertical
                vert_str = ""
                curr_r = r
                curr_c = c
                for _ in range(p_len):
                    vert_str += grid[curr_r][curr_c]
                    curr_r += 1
                    if curr_r == m:
                        curr_r = 0
                        curr_c += 1
                        if curr_c == n:
                            break
                            
                if len(vert_str) == p_len and vert_str == pattern:
                    curr_r = r
                    curr_c = c
                    for _ in range(p_len):
                        vert_matches.add((curr_r, curr_c))
                        curr_r += 1
                        if curr_r == m:
                            curr_r = 0
                            curr_c += 1

        for cell in horz_matches:
            if cell in vert_matches:
                count += 1

        return count