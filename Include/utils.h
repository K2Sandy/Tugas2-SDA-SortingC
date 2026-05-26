#ifndef UTILS_H
#define UTILS_H

// === UNTUK DATA INTEGER (Sorting Dasar) ===
void printArray(int arr[], int n, int limit);
void shuffleData(int arr[], int n);
void swap_int(int *a, int *b);

// === UNTUK DATA STRING (Advance Sorting) ===
void printArrayString(char *arr[], int n, int limit);
void shuffleDataString(char *arr[], int n);
void swap_string(char **a, char **b);
char** read_words_file(const char *filename, int *word_count);
void free_word_list(char **word_list, int word_count);

#endif
