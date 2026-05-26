#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/utils.h"
#include "../include/sorting.h"

#define DATA_SIZE_INT 1000
#define DISPLAY_LIMIT 10

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void jalankan_bubble_sort() {
    int data[DATA_SIZE_INT];
    clock_t start, end;

    // Generate data random otomatis
    for (int i = 0; i < DATA_SIZE_INT; i++) {
        data[i] = rand() % 10000;
    }

    // Melakukan pengacakan data (Shuffle) terlebih dahulu
    shuffleData(data, DATA_SIZE_INT);
    
    printf("\n=== BUBBLE SORT: DATA SEBELUM SORTING ===\n");
    printArray(data, DATA_SIZE_INT, DISPLAY_LIMIT);

    // Hitung waktu eksekusi
    start = clock();
    bubble_sort(data, DATA_SIZE_INT);
    end = clock();

    printf("\n=== BUBBLE SORT: DATA SETELAH SORTING ===\n");
    printArray(data, DATA_SIZE_INT, DISPLAY_LIMIT);

    double durasi = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Bubble Sort: %f detik\n", durasi);
}
