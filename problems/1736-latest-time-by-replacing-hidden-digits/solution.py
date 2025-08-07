class Solution:
    def maximumTime(self, time: str) -> str:
        time_list = list(time)
        
        if time_list[0] == '?':
            if time_list[1] == '?':
                time_list[0] = '2'
                time_list[1] = '3'
            elif int(time_list[1]) <= 3:
                time_list[0] = '2'
            else:
                time_list[0] = '1'
        
        if time_list[1] == '?':
            if time_list[0] == '2':
                time_list[1] = '3'
            else:
                time_list[1] = '9'
                
        if time_list[3] == '?':
            time_list[3] = '5'
        
        if time_list[4] == '?':
            time_list[4] = '9'
        
        return "".join(time_list)