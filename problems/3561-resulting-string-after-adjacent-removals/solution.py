class Solution:
    def resultingString(self, s: str) -> str:
        stack = []
        for char in s:
            if stack:
                top = stack[-1]
                if (ord(char) - ord(top) == 1) or (ord(top) - ord(char) == 1) or \
                   (top == 'z' and char == 'a') or (top == 'a' and char == 'z'):
                    stack.pop()
                else:
                    stack.append(char)
            else:
                stack.append(char)
        return "".join(stack)