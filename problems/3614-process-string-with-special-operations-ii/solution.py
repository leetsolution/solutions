class Solution:
    def process_string(s, k):
        result = ""
        for char in s:
            if 'a' <= char <= 'z':
                result += char
            elif char == '*':
                if result:
                    result = result[:-1]
            elif char == '#':
                result += result
            elif char == '%':
                result = result[::-1]

        if k >= len(result) or k < 0:
            return "."
        else:
            return result[k]