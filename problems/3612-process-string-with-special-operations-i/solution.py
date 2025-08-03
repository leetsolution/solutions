class Solution:
    def process_string(s):
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
        return result