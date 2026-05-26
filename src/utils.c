#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"


//  NI UTILS YANG AWAK PAKEK, KALO KALIAN BEDA, BEBASI AJA SI
void printArray(int arr[], int n, int limit) {
    for (int i = 0; i < limit && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("... (menampilkan %d data pertama)\n", limit);
}

void shuffleData(int arr[], int n){
    for (int i = n - 1; i > 0; i--){ 
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
// Fungsi untuk menukar dua integer
void swap_int(int *a, int *b) { //fungsi 
    int temp = *a;
    *a = *b;
    *b = temp;
}
