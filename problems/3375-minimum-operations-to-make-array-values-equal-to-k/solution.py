class Solution:
    def minOperations(self, nums, k):
        if k not in nums and any(num > k for num in nums):
            return -1
        
        operations = 0
        while any(num != k for num in nums):
            valid_h = []
            for h in range(1, 101):
                greater_than_h = [num for num in nums if num > h]
                if not greater_than_h or all(greater_than_h[0] == num for num in greater_than_h):
                    valid_h.append(h)
            
            if not valid_h:
                return -1
            
            max_valid_h = 0
            for h in valid_h:
                if any(num > h for num in nums) and h > max_valid_h:
                    max_valid_h = h
            
            if max_valid_h == 0:
                return -1
            
            for i in range(len(nums)):
                if nums[i] > max_valid_h:
                    nums[i] = max_valid_h
            
            operations += 1
            
            if all(num == k for num in nums):
                break
                
        if any(num != k for num in nums):
            while any(num != k for num in nums):
                valid_h = []
                for h in range(1, 101):
                    greater_than_h = [num for num in nums if num > h]
                    if not greater_than_h or all(greater_than_h[0] == num for num in greater_than_h):
                        valid_h.append(h)
                
                if not valid_h:
                    return -1
            
                max_valid_h = 0
                for h in valid_h:
                    if any(num > h for num in nums) and h > max_valid_h:
                        max_valid_h = h
                
                if max_valid_h == 0:
                    return -1
                
                for i in range(len(nums)):
                    if nums[i] > max_valid_h:
                        nums[i] = max_valid_h
                
                operations += 1
                
                if all(num == k for num in nums):
                    break
        
        while any(num != k for num in nums):
            valid_h = []
            for h in range(1, 101):
                greater_than_h = [num for num in nums if num > h]
                if not greater_than_h or all(greater_than_h[0] == num for num in greater_than_h):
                    valid_h.append(h)
            
            if not valid_h:
                return -1
            
            max_valid_h = 0
            for h in valid_h:
                if any(num > h for num in nums) and h > max_valid_h:
                    max_valid_h = h
            
            if max_valid_h == 0:
                return -1
            
            for i in range(len(nums)):
                if nums[i] > max_valid_h:
                    nums[i] = max_valid_h
            
            operations += 1
            
            if all(num == k for num in nums):
                break
        
        while any(num > k for num in nums):
                valid_h = []
                for h in range(1, 101):
                    greater_than_h = [num for num in nums if num > h]
                    if not greater_than_h or all(greater_than_h[0] == num for num in greater_than_h):
                        valid_h.append(h)
                
                if not valid_h:
                    return -1
                
                max_valid_h = 0
                for h in valid_h:
                    if any(num > h for num in nums) and h > max_valid_h:
                        max_valid_h = h
                
                if max_valid_h == 0:
                    return -1
                
                for i in range(len(nums)):
                    if nums[i] > max_valid_h:
                        nums[i] = max_valid_h
                
                operations += 1
                
                if all(num == k for num in nums):
                    break
        
        if any(num < k for num in nums):
          return -1
            
        return operations