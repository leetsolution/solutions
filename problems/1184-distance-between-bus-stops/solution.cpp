class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int clockwise_dist = 0;
        int counterclockwise_dist = 0;
        int i = start;

        while (i != destination) {
            clockwise_dist += distance[i];
            i = (i + 1) % n;
        }

        i = start;
        while (i != destination) {
            i = (i - 1 + n) % n;
            counterclockwise_dist += distance[i];
        }
        
        return min(clockwise_dist, counterclockwise_dist);
    }
};