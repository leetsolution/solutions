class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        lower = False
        upper = False
        digit = False
        special = False
        special_chars = "!@#$%^&*()-+"
        for i in range(len(password)):
            if password[i].islower():
                lower = True
            elif password[i].isupper():
                upper = True
            elif password[i].isdigit():
                digit = True
            elif password[i] in special_chars:
                special = True
            if i > 0 and password[i] == password[i - 1]:
                return False
        return lower and upper and digit and special