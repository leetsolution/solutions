/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidCode(char* code) {
    if (code == NULL || strlen(code) == 0) {
        return false;
    }
    for (int i = 0; code[i] != '\0'; i++) {
        if (!((code[i] >= 'a' && code[i] <= 'z') ||
              (code[i] >= 'A' && code[i] <= 'Z') ||
              (code[i] >= '0' && code[i] <= '9') ||
              (code[i] == '_'))) {
            return false;
        }
    }
    return true;
}

int getBusinessLinePriority(char* businessLine) {
    if (strcmp(businessLine, "electronics") == 0) {
        return 1;
    } else if (strcmp(businessLine, "grocery") == 0) {
        return 2;
    } else if (strcmp(businessLine, "pharmacy") == 0) {
        return 3;
    } else if (strcmp(businessLine, "restaurant") == 0) {
        return 4;
    } else {
        return 0;
    }
}

bool isValidBusinessLine(char* businessLine) {
    return (strcmp(businessLine, "electronics") == 0 ||
            strcmp(businessLine, "grocery") == 0 ||
            strcmp(businessLine, "pharmacy") == 0 ||
            strcmp(businessLine, "restaurant") == 0);
}

typedef struct {
    char* code;
    char* businessLine;
} ValidCoupon;

int compareCoupons(const void* a, const void* b) {
    ValidCoupon* couponA = (ValidCoupon*)a;
    ValidCoupon* couponB = (ValidCoupon*)b;

    int priorityA = getBusinessLinePriority(couponA->businessLine);
    int priorityB = getBusinessLinePriority(couponB->businessLine);

    if (priorityA != priorityB) {
        return priorityA - priorityB;
    } else {
        return strcmp(couponA->code, couponB->code);
    }
}

char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    if (codeSize != businessLineSize || codeSize != isActiveSize) {
        *returnSize = 0;
        return NULL;
    }

    ValidCoupon* validCoupons = (ValidCoupon*)malloc(codeSize * sizeof(ValidCoupon));
    int validCount = 0;

    for (int i = 0; i < codeSize; i++) {
        if (isValidCode(code[i]) && isValidBusinessLine(businessLine[i]) && isActive[i]) {
            validCoupons[validCount].code = code[i];
            validCoupons[validCount].businessLine = businessLine[i];
            validCount++;
        }
    }

    qsort(validCoupons, validCount, sizeof(ValidCoupon), compareCoupons);

    char** result = (char**)malloc(validCount * sizeof(char*));
    for (int i = 0; i < validCount; i++) {
        result[i] = validCoupons[i].code;
    }

    free(validCoupons);

    *returnSize = validCount;
    return result;
}