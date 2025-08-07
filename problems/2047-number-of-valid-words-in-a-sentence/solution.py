class Solution:
    def countValidWords(self, sentence: str) -> int:
        count = 0
        for token in sentence.split():
            if not token:
                continue
            valid = True
            hyphen_count = 0
            punctuation_count = 0
            n = len(token)
            for i in range(n):
                if token[i].isdigit():
                    valid = False
                    break
                elif token[i] == '-':
                    hyphen_count += 1
                    if hyphen_count > 1:
                        valid = False
                        break
                    if i == 0 or i == n - 1:
                        valid = False
                        break
                    if not token[i - 1].islower() or not token[i + 1].islower():
                        valid = False
                        break
                elif token[i] in ['!', '.', ',']:
                    punctuation_count += 1
                    if punctuation_count > 1:
                        valid = False
                        break
                    if i != n - 1:
                        valid = False
                        break
            if valid:
                count += 1
        return count