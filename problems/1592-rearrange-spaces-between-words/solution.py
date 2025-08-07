class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        space_count = text.count(' ')
        word_count = len(words)
        if word_count == 1:
            return words[0] + ' ' * space_count
        spaces_between = space_count // (word_count - 1)
        extra_spaces = space_count % (word_count - 1)
        return (' ' * spaces_between).join(words) + ' ' * extra_spaces