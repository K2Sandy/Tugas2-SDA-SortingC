#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sorting.h"

int main() {
    int pilihan_utama, pilihan_sub;

    srand(time(NULL)); 

    while (1) { 
        printf("\n===========================================\n");
        printf("    TUGAS 2: ANALISIS ALGORITMA SORTING    \n");
        printf("===========================================\n");
        printf("1. Basic Sorting\n");
        printf("2. Advance Sorting\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan_utama);

        if (pilihan_utama == 1) {
            while (1) { 
                printf("\n============================\n");
                printf("        BASIC SORTING       \n");
                printf("============================\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("3. Selection Sort\n");
                printf("4. Kembali\n");
                printf("Pilih metode: ");
                scanf("%d", &pilihan_sub);

                if (pilihan_sub == 1) {
                    jalankan_bubble_sort();
                } 
                else if (pilihan_sub == 2) {
                    jalankanInsertionSort(); 
                } 
                else if (pilihan_sub == 3) {
                    jalankanSelectionSort();
                } 
                else if (pilihan_sub == 4) {
                    break; 
                } 
                else {
                    printf("\nPilihan tidak valid!\n");
                }
            }
        } 
        else if (pilihan_utama == 2) {
            while (1) { 
                printf("\n============================\n");
                printf("       ADVANCE SORTING       \n");
                printf("============================\n");
                printf("1. Merge Sort\n");
                printf("2. Quick Sort\n");
                printf("3. Shell Sort\n");
                printf("4. Kembali\n");
                printf("Pilih metode: ");
                scanf("%d", &pilihan_sub);

                if (pilihan_sub == 1) {
                     jalankan_merge_sort();
                } 
                else if (pilihan_sub == 2) {
                     jalankan_quick_sort();
                } 
                else if (pilihan_sub == 3) {
                     jalankan_Shell_sort();
                } 
                else if (pilihan_sub == 4) {
                    break; 
                } 
                else {
                    printf("Pilihan tidak valid!\n");
                }
            }
        } 
        else if (pilihan_utama == 3) {
            printf("\nKeluar dari program. Terima kasih!\n");
            break; 
        } 
        else {
            printf("\n[Peringatan] Pilihan menu utama tidak valid!\n");
        }
    }

    return 0;
}
