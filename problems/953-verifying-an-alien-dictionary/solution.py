class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map = {char: i for i, char in enumerate(order)}

        def compare_words(word1, word2):
            min_len = min(len(word1), len(word2))
            for i in range(min_len):
                if order_map[word1[i]] < order_map[word2[i]]:
                    return -1
                elif order_map[word1[i]] > order_map[word2[i]]:
                    return 1
            if len(word1) < len(word2):
                return -1
            elif len(word1) > len(word2):
                return 1
            else:
                return 0

        for i in range(len(words) - 1):
            if compare_words(words[i], words[i+1]) > 0:
                return False

        return True