#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/utils.h"
#include "../../include/sorting.h"

#define DISPLAY_LIMIT 10

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high]; // Elemen terakhir sebagai pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Membandingkan string secara alfabetis (Ascending)
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap_string(&arr[i], &arr[j]); // Memakai swap_string dari utils
        }
    }
    swap_string(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Memproses sub-array kiri dan kanan secara rekursif
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void jalankan_quick_sort() {
    int word_count = 0;
    // Pastikan letak file words.txt berada di satu folder dengan executable (.exe)
    char **word_list = read_words_file("data/words.txt", &word_count);

    if (word_list == NULL) {
        printf("\n[Error] Gagal membuka file 'words.txt'!\n");
        printf("Pastikan file diletakkan di tempat yang benar.\n");
        return;
    }

    printf("\n[Sukses] Berhasil membaca %d kata dari file.\n", word_count);

    // Melakukan pengacakan data string (Shuffle) terlebih dahulu
    shuffleDataString(word_list, word_count);

    printf("\n=== QUICK SORT: DATA SEBELUM SORTING ===\n");
    printArrayString(word_list, word_count, DISPLAY_LIMIT);

    // Hitung waktu eksekusi
    clock_t start = clock();
    quick_sort(word_list, 0, word_count - 1);
    clock_t end = clock();

    printf("\n=== QUICK SORT: DATA SETELAH SORTING ===\n");
    printArrayString(word_list, word_count, DISPLAY_LIMIT);

    double durasi = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Quick Sort: %f detik\n", durasi);

    free_word_list(word_list, word_count);
}
