int captureForts(int* forts, int fortsSize) {
    int max_captured = 0;
    for (int i = 0; i < fortsSize; i++) {
        if (forts[i] == 1) {
            for (int j = 0; j < fortsSize; j++) {
                if (forts[j] == -1) {
                    int captured = 0;
                    int start = (i < j) ? i : j;
                    int end = (i < j) ? j : i;
                    int valid = 1;
                    for (int k = start + 1; k < end; k++) {
                        if (forts[k] != 0) {
                            valid = 0;
                            break;
                        } else {
                            captured++;
                        }
                    }
                    if (valid) {
                        if (captured > max_captured) {
                            max_captured = captured;
                        }
                    }
                } else if (forts[j] == 1) {
                     int captured = 0;
                    int start = (i < j) ? i : j;
                    int end = (i < j) ? j : i;
                    int valid = 0;
                    
                    }
            }
        } else if(forts[i] == -1){
             for (int j = 0; j < fortsSize; j++) {
                if (forts[j] == 1) {
                    int captured = 0;
                    int start = (i < j) ? i : j;
                    int end = (i < j) ? j : i;
                    int valid = 1;
                    for (int k = start + 1; k < end; k++) {
                        if (forts[k] != 0) {
                            valid = 0;
                            break;
                        } else {
                            captured++;
                        }
                    }
                    if (valid) {
                        if (captured > max_captured) {
                            max_captured = captured;
                        }
                    }
                } 
            }
        }
    }
    return max_captured;
}