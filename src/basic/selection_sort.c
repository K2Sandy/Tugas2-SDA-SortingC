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
