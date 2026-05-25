#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT_DATA 1000
#define DISPLAY_LIMIT 10 // Jumlah data yang ditampilkan di terminal

// Fungsi untuk menukar dua integer
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengacak data integer
void shuffle_int_data(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap_int(&arr[i], &arr[j]);
    }
}

// Fungsi Bubble Sort (Ascending)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Fungsi untuk menampilkan sebagian data integer
void display_int_data(int arr[], int n, const char *msg) {
    printf("\n%s (Menampilkan %d data pertama):\n", msg, DISPLAY_LIMIT);
    for (int i = 0; i < DISPLAY_LIMIT && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi Driver untuk menu Bubble Sort
void handle_bubble_sort() {
    int data[MAX_INT_DATA];
    clock_t start, end;
    double cpu_time_used;

    // 1. Generate 1000 data random
    for (int i = 0; i < MAX_INT_DATA; i++) {
        data[i] = rand() % 10000; // Random angka dari 0 - 9999
    }

    // 2. Lakukan shuffle sesuai ketentuan
    shuffle_int_data(data, MAX_INT_DATA);

    // 3. Tampilkan data sebelum sorting
    display_int_data(data, MAX_INT_DATA, "=== DATA SEBELUM SORTING ===");

    // 4. Hitung waktu eksekusi Bubble Sort
    start = clock();
    bubble_sort(data, MAX_INT_DATA);
    end = clock();

    // 5. Tampilkan data setelah sorting
    display_int_data(data, MAX_INT_DATA, "=== DATA SETELAH SORTING ===");

    // 6. Tampilkan waktu eksekusi
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Bubble Sort: %f detik\n", cpu_time_used);
}
