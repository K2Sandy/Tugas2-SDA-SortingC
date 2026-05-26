#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/sorting.h"
#include "../../include/utils.h" // Panggil utils untuk fungsi print dan shuffle

void SelectionSort(int arr[], int n){
    int i, min_index, j;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++){
            if ( arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if ( min_index != i){
            swap_int(&arr[i], &arr[min_index]);
        }
    }
}
void jalankanSelectionSort() {
    int n = 1000;
    int data[n];

    // Generate data
    for (int i = 0; i < n; i++ ){
        data[i] = (rand() % 10000) + 1; 
    }

    // Shuffle data menggunakan fungsi dari utils.c
    shuffleData(data, n);
    printf("\n=== SELECTION SORT: DATA SEBELUM SORTING ===\n");
    printArray(data, n, 10);

    // Hitung waktu dan jalankan algoritma murni
    clock_t start_time = clock();
    SelectionSort(data, n);
    clock_t end_time = clock();

    printf("\n=== SELECTION SORT: DATA SETELAH SORTING ===\n");
    printArray(data, n, 10);

    // Kalkulasi dan print waktu
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Selection Sort: %f detik\n", time_spent);
}