#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/sorting.h"
#include "../../include/utils.h" // Panggil utils untuk fungsi print dan shuffle

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void jalankanInsertionSort() {
    int n = 1000;
    int data[n];

    // Generate data
    for (int i = 0; i < n; i++ ){
        data[i] = (rand() % 10000) + 1; 
    }
    // Shuffle data menggunakan fungsi dari utils.c
    shuffleData(data, n);

    printf("\nData Sebelum sorting:\n");
    printArray(data, n, 10);

    // Hitung waktu dan jalankan algoritma murni
    clock_t start_time = clock();
    insertionSort(data, n);
    clock_t end_time = clock();

    printf("\nData Setelah sorting:\n");
    printArray(data, n, 10);

    // Kalkulasi dan print waktu
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Insertion Sort: %f detik\n", time_spent);
}