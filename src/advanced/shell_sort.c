#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/utils.h"
#include "../../include/sorting.h"

#define DISPLAY_LIMIT 10


void Shell_sort(char *arr[], int n) {
    int gap, i, j;
    
    for (gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j = i; j >= gap; j -= gap){
                if(strcmp(arr[j - gap],arr[j]) > 0){
                    swap_string(&arr[j - gap], &arr[j]);
                }
                else {
                    break;
                }
            }
        }
    }
}

void jalankan_Shell_sort() {
    int word_count = 0;
    
    // 1. Membaca dataset menggunakan utils
    char **word_list = read_words_file("advanced/data/words.txt", &word_count);

    if (word_list == NULL) {
        printf("\n[Error] Gagal membuka file 'words.txt'!\n");
        printf("Pastikan file diletakkan di tempat yang benar.\n");
        return;
    }