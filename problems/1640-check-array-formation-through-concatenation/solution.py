class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        piece_map = {piece[0]: piece for piece in pieces}
        i = 0
        while i < len(arr):
            if arr[i] not in piece_map:
                return False
            piece = piece_map[arr[i]]
            for j in range(len(piece)):
                if i + j >= len(arr) or arr[i + j] != piece[j]:
                    return False
            i += len(piece)
        return True