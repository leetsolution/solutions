class Solution:
    def generateTag(self, caption: str) -> str:
        words = caption.split()
        tag = "#"
        for i, word in enumerate(words):
            cleaned_word = ''.join(c for c in word if 'a' <= c <= 'z' or 'A' <= c <= 'Z')
            if i == 0:
                tag += cleaned_word.lower()
            else:
                if cleaned_word:
                    tag += cleaned_word[0].upper() + cleaned_word[1:].lower()
        
        tag = ''.join(c for c in tag if 'a' <= c <= 'z' or 'A' <= c <= 'Z' or c == '#')

        if len(tag) > 100:
            return tag[:101]
        return tag