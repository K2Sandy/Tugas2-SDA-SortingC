#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// fungsi tampiilin nilai
void printArray(int arr[], int n, int limit) {
for (int i = 0; i < limit && i< n; i++) {
    printf("%d ", arr[i]);
}
    printf("... (menampilkan %d data pertama)\n", limit);
}

void shuffleData(int arr[], int n){
    for (int i = n - 1; i > 0; i--){ //acak data 9999 kali
    //pilih indeks acak dari 0 sampai i
    int j = rand() % (i + 1);

    //proses swap (tukar nilai)
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    }

}

void insertionSort(int arr[], int n){
int i, key, j;
for (i = 1; i < n; i++) {
    key = arr[i];
    j = i- 1;

    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
 }
}

int main(){
    int n = 1000; //1000 data integer
    int data[n];

    srand(time(NULL));      //random angka seed generator

    for (int i = 0; i < n; i++ ){
        data[i] = (rand() % 10000) + 1;     //biar angaknya acak dari 1-10000
     }

     //acak datanya, sbnrnya sudah diacak tapi biar sesuai tugas aja
     shuffleData(data, n);

     printf ("=== Insertion Sort ===\n");
     
    printf("\nData Sebelum sorting:\n");
     printArray (data, n, 20);

     // Mulai menghitung waktu
    clock_t start_time = clock();

    // Jalankan algoritma
    insertionSort(data, n);

    clock_t end_time = clock();

    printf("\nData Setelah sorting:\n");
    printArray(data, n, 20);

    // Menghitung durasi eksekusi dalam detik
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nWaktu eksekusi Insertion Sort: %f detik\n", time_spent);
    return 0;
}