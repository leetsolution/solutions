int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    int units = 0;
    int n = boxTypesSize;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (boxTypes[j][1] < boxTypes[j + 1][1]) {
                int temp_boxes = boxTypes[j][0];
                int temp_units = boxTypes[j][1];
                boxTypes[j][0] = boxTypes[j + 1][0];
                boxTypes[j][1] = boxTypes[j + 1][1];
                boxTypes[j + 1][0] = temp_boxes;
                boxTypes[j + 1][1] = temp_units;
            }
        }
    }

    for (int i = 0; i < boxTypesSize; i++) {
        int num_boxes = boxTypes[i][0];
        int units_per_box = boxTypes[i][1];

        if (truckSize >= num_boxes) {
            units += num_boxes * units_per_box;
            truckSize -= num_boxes;
        } else {
            units += truckSize * units_per_box;
            truckSize = 0;
            break;
        }
    }

    return units;
}