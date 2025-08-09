class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        total_poisoned_time = 0
        if not timeSeries:
            return 0
        
        prev_attack_time = timeSeries[0]
        total_poisoned_time += duration
        
        for i in range(1, len(timeSeries)):
            current_attack_time = timeSeries[i]
            
            if current_attack_time - prev_attack_time >= duration:
                total_poisoned_time += duration
            else:
                total_poisoned_time += current_attack_time - prev_attack_time
            
            prev_attack_time = current_attack_time
            
        return total_poisoned_time