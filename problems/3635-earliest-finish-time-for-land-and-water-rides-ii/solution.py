from typing import List
from bisect import bisect_right

class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        """
        Calculates the earliest possible time to finish one land ride and one water ride.

        The problem can be broken down into two main scenarios:
        1. Land ride first, then water ride.
        2. Water ride first, then land ride.

        We need to find the minimum finish time for each scenario and then take the overall minimum.
        A naive O(n*m) approach checking all pairs of land and water rides would be too slow.

        To optimize, let's focus on one scenario, e.g., land -> water. For each land ride 'i',
        we want to pick the best water ride 'j' to partner with. The finish time for a pair (i, j)
        in this order is `max(land_finish_time_i, water_start_time_j) + water_duration_j`.

        To find the best 'j' for a given 'i' efficiently, we can sort the water rides by their start times.
        For a land ride 'i' that finishes at `finish1 = landStartTime[i] + landDuration[i]`,
        we can split water rides into two groups:
        a) Those that open at or before `finish1`.
        b) Those that open after `finish1`.

        For group (a), we can start the water ride at `finish1`. To minimize the total time, we should
        choose the water ride with the minimum duration.
        Total time = `finish1 + min(water_duration)`.

        For group (b), we must wait for the water ride to open. The finish time will be `water_start_time + water_duration`.
        To minimize, we choose the ride with the minimum finish time.

        By pre-computing prefix minimums of durations and suffix minimums of finish times for the sorted
        water rides, we can find the best choice from group (a) and (b) in O(1) after a binary search.
        The binary search (O(log m)) finds the split point between group (a) and (b).

        We repeat this process for all land rides, giving a total time complexity of O(n log m) for
        the land -> water scenario, after an initial O(m log m) sort.

        The same logic is applied symmetrically for the water -> land scenario. The final answer is the
        minimum of the results from both scenarios.
        """

        def _calculate_one_way(starts1: List[int], durations1: List[int], starts2: List[int], durations2: List[int]) -> int:
            n1 = len(starts1)
            n2 = len(starts2)

            # Combine start times and durations for type 2 rides and sort by start time.
            rides2 = sorted(zip(starts2, durations2))
            
            s2_starts = [r[0] for r in rides2]
            s2_durations = [r[1] for r in rides2]
            
            # Precompute prefix minimums of durations for type 2 rides.
            prefix_min_d2 = [0] * n2
            prefix_min_d2[0] = s2_durations[0]
            for j in range(1, n2):
                prefix_min_d2[j] = min(prefix_min_d2[j-1], s2_durations[j])

            # Precompute suffix minimums of finish times for type 2 rides.
            suffix_min_finish2 = [0] * n2
            suffix_min_finish2[n2 - 1] = s2_starts[n2 - 1] + s2_durations[n2 - 1]
            for j in range(n2 - 2, -1, -1):
                suffix_min_finish2[j] = min(suffix_min_finish2[j+1], s2_starts[j] + s2_durations[j])

            min_total_finish = float('inf')

            # Iterate through each ride of type 1.
            for i in range(n1):
                finish1 = starts1[i] + durations1[i]
                
                # Find the split point in type 2 rides using binary search.
                k = bisect_right(s2_starts, finish1)
                
                current_min_for_this_ride1 = float('inf')
                
                # Case 1: Second ride opens at or before the first one finishes.
                if k > 0:
                    min_dur_among_available = prefix_min_d2[k - 1]
                    current_min_for_this_ride1 = min(current_min_for_this_ride1, finish1 + min_dur_among_available)

                # Case 2: Second ride opens after the first one finishes.
                if k < n2:
                    min_finish_among_waiting = suffix_min_finish2[k]
                    current_min_for_this_ride1 = min(current_min_for_this_ride1, min_finish_among_waiting)
                
                min_total_finish = min(min_total_finish, current_min_for_this_ride1)

            return min_total_finish

        # Calculate for land -> water order.
        min_finish_lw = _calculate_one_way(landStartTime, landDuration, waterStartTime, waterDuration)
        
        # Calculate for water -> land order.
        min_finish_wl = _calculate_one_way(waterStartTime, waterDuration, landStartTime, landDuration)
        
        return min(min_finish_lw, min_finish_wl)