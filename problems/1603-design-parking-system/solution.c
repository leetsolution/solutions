#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* obj = (ParkingSystem*)malloc(sizeof(ParkingSystem));
    if (obj == NULL) {
        return NULL;
    }
    obj->big = big;
    obj->medium = medium;
    obj->small = small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (obj == NULL) {
        return false;
    }

    if (carType == 1) {
        if (obj->big > 0) {
            obj->big--;
            return true;
        } else {
            return false;
        }
    } else if (carType == 2) {
        if (obj->medium > 0) {
            obj->medium--;
            return true;
        } else {
            return false;
        }
    } else if (carType == 3) {
        if (obj->small > 0) {
            obj->small--;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void parkingSystemFree(ParkingSystem* obj) {
    if (obj != NULL) {
        free(obj);
    }
}