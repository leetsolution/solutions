class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build_string(s):
            res = []
            for char in s:
                if char == '#':
                    if res:
                        res.pop()
                else:
                    res.append(char)
            return "".join(res)

        return build_string(s) == build_string(t)