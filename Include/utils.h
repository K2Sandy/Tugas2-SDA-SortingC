#ifndef UTILS_H
#define UTILS_H

// fungsi bantuan
void printArray(int arr[], int n, int limit);
void shuffleData(int arr[], int n);

// Fungsi untuk tipe data Integer (Bubble Sort)
void swap_int(int *a, int *b);
void shuffle_int_data(int arr[], int n);
void display_int_data(int arr[], int n, int limit, const char *msg);

// Fungsi untuk tipe data String (Quick Sort)
void swap_string(char **a, char **b);
void shuffle_string_data(char *arr[], int n);
void display_string_data(char *arr[], int n, int limit, const char *msg);
char** read_words_file(const char *filename, int *word_count);
void free_word_list(char **word_list, int word_count);

#endif
