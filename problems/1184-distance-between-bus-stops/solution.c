int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int clockwise_dist = 0;
    int counterclockwise_dist = 0;
    int i = start;

    if (start == destination) {
        return 0;
    }

    while (i != destination) {
        clockwise_dist += distance[i];
        i = (i + 1) % distanceSize;
    }

    i = start;
    while (i != destination) {
        i = (i + distanceSize - 1) % distanceSize;
        counterclockwise_dist += distance[i];
    }

    if (clockwise_dist < counterclockwise_dist) {
        return clockwise_dist;
    } else {
        return counterclockwise_dist;
    }
}