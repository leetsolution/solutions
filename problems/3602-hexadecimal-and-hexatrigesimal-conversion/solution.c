#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatHex36(int n) {
    long long n2 = (long long)n * n;
    long long n3 = (long long)n * n * n;

    char hex_buf[20];
    char hex36_buf[20];
    int hex_len = 0;
    int hex36_len = 0;

    long long temp_n2 = n2;
    while (temp_n2 > 0) {
        int rem = temp_n2 % 16;
        if (rem < 10) {
            hex_buf[hex_len++] = rem + '0';
        } else {
            hex_buf[hex_len++] = rem - 10 + 'A';
        }
        temp_n2 /= 16;
    }
    if (hex_len == 0) {
        hex_buf[hex_len++] = '0';
    }

    long long temp_n3 = n3;
    while (temp_n3 > 0) {
        int rem = temp_n3 % 36;
        if (rem < 10) {
            hex36_buf[hex36_len++] = rem + '0';
        } else {
            hex36_buf[hex36_len++] = rem - 10 + 'A';
        }
        temp_n3 /= 36;
    }
    if (hex36_len == 0) {
        hex36_buf[hex36_len++] = '0';
    }

    char* hex = (char*)malloc(hex_len + 1);
    for (int i = 0; i < hex_len; i++) {
        hex[i] = hex_buf[hex_len - 1 - i];
    }
    hex[hex_len] = '\0';

    char* hex36 = (char*)malloc(hex36_len + 1);
    for (int i = 0; i < hex36_len; i++) {
        hex36[i] = hex36_buf[hex36_len - 1 - i];
    }
    hex36[hex36_len] = '\0';

    char* result = (char*)malloc(hex_len + hex36_len + 1);
    strcpy(result, hex);
    strcat(result, hex36);

    free(hex);
    free(hex36);

    return result;
}