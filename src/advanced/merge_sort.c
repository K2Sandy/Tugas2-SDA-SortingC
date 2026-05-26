#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/utils.h"
#include "../../include/sorting.h"

#define DISPLAY_LIMIT 10

//fungsi gabungin
void merge(char *arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Membuat array pointer sementara
    char **L = malloc(n1 * sizeof(char *));
    char **R = malloc(n2 * sizeof(char *));

    // Menyalin data pointer ke array sementara L[] dan R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Proses penggabungan kembali ke arr[]
    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L[] jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen R[] jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Bebaskan memori array sementara L dan R
    free(L);
    free(R);
}

//merge sort rekursif
void merge_sort(char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void jalankan_merge_sort() {
    int word_count = 0;
    
    // 1. Membaca dataset menggunakan utils
    char **word_list = read_words_file("words.txt", &word_count);

    if (word_list == NULL) {
        printf("\n[Error] Gagal membuka file 'words.txt'!\n");
        printf("Pastikan file diletakkan di tempat yang benar.\n");
        return;
    }

    printf("\n[Sukses] Berhasil membaca %d kata dari file.\n", word_count);

    // 2. Mengacak data menggunakan utils
    shuffleDataString(word_list, word_count);

    printf("\n=== MERGE SORT: DATA SEBELUM SORTING ===\n");
    printArrayString(word_list, word_count, DISPLAY_LIMIT);

    // 3. Hitung waktu eksekusi
    clock_t start = clock();
    merge_sort(word_list, 0, word_count - 1);
    clock_t end = clock();

    printf("\n=== MERGE SORT: DATA SETELAH SORTING ===\n");
    printArrayString(word_list, word_count, DISPLAY_LIMIT);

    // 4. Kalkulasi durasi
    double durasi = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Merge Sort: %f detik\n", durasi);

    // 5. Bersihkan memori menggunakan utils
    free_word_list(word_list, word_count);
}