#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 50
#define DISPLAY_LIMIT_STR 10

// Fungsi untuk menukar dua string (pointer-nya yang ditukar agar cepat)
void swap_string(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengacak data string
void shuffle_string_data(char *arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap_string(&arr[i], &arr[j]);
    }
}

// Fungsi pembantu Quick Sort untuk membagi/partisi array string
int partition(char *arr[], int low, int high) {
    char *pivot = arr[high]; // Mengambil elemen terakhir sebagai pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Jika arr[j] secara alfabetis lebih kecil dari pivot (Ascending)
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap_string(&arr[i], &arr[j]);
        }
    }
    swap_string(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi utama Quick Sort (Rekursif)
void quick_sort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort elemen sebelum dan setelah partisi
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan sebagian data string
void display_string_data(char *arr[], int n, const char *msg) {
    printf("\n%s (Menampilkan %d data pertama):\n", msg, DISPLAY_LIMIT_STR);
    for (int i = 0; i < DISPLAY_LIMIT_STR && i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

// Fungsi Driver untuk menu Quick Sort
void handle_quick_sort() {
    // Membuka dataset file .txt
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("[Error] Gagal membuka file words.txt!\n");
        printf("Pastikan file berada di folder yang sama dengan program.\n");
        return;
    }

    // Alokasi dinamis untuk menampung kata agar aman dari stack overflow
    // Di sini kita asumsikan kapasitas awal 200.000 kata
    int capacity = 200000;
    char **word_list = malloc(capacity * sizeof(char *));
    int word_count = 0;

    char buffer[MAX_WORD_LEN];
    // Membaca seluruh isi file baris per baris
    while (fscanf(file, "%s", buffer) != EOF) {
        // Jika data melebihi kapasitas awal, kita perbesar memorinya
        if (word_count >= capacity) {
            capacity *= 2;
            word_list = realloc(word_list, capacity * sizeof(char *));
        }
        word_list[word_count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(word_list[word_count], buffer);
        word_count++;
    }
    fclose(file);

    printf("\nBerhasil membaca %d kata dari file.\n", word_count);

    // 1. Lakukan shuffle sebelum di-sorting
    shuffle_string_data(word_list, word_count);

    // 2. Tampilkan data sebelum sorting
    display_string_data(word_list, word_count, "=== DATA SEBELUM SORTING ===");

    // 3. Hitung waktu eksekusi Quick Sort
    clock_t start = clock();
    quick_sort(word_list, 0, word_count - 1);
    clock_t end = clock();

    // 4. Tampilkan data setelah sorting
    display_string_data(word_list, word_count, "=== DATA SETELAH SORTING ===");

    // 5. Tampilkan waktu eksekusi
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Quick Sort: %f detik\n", cpu_time_used);

    // Free memori yang telah dialokasikan
    for (int i = 0; i < word_count; i++) {
        free(word_list[i]);
    }
    free(word_list);
}
