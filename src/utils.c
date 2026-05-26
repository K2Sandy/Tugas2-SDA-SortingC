#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"


//  NI UTILS YANG AWAK PAKEK, KALO KALIAN BEDA, BEBAS AJA SI
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
void swap_int(int *a, int *b) { //fungsi swap untuk tukar posisi elemen index
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArrayString(char *arr[], int n, int limit) {
    for (int i = 0; i < limit && i < n; i++) {
        printf("%d. %s\n", i + 1, arr[i]);
    }
    printf("... (menampilkan %d data pertama)\n", limit);
}

void shuffleDataString(char *arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void swap_string(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi otomatis membaca dataset kata dari file .txt
char** read_words_file(const char *filename, int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    int capacity = 200000;
    char **word_list = malloc(capacity * sizeof(char *));
    *word_count = 0;
    char buffer[50];

    while (fscanf(file, "%s", buffer) != EOF) {
        if (*word_count >= capacity) {
            capacity *= 2;
            word_list = realloc(word_list, capacity * sizeof(char *));
        }
        word_list[*word_count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(word_list[*word_count], buffer);
        (*word_count)++;
    }
    fclose(file);
    return word_list;
}

// Fungsi membersihkan memori RAM
void free_word_list(char **word_list, int word_count) {
    for (int i = 0; i < word_count; i++) {
        free(word_list[i]);
    }
    free(word_list);
}
