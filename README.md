# AlgoBench CLI - Sorting Algorithm Benchmark

Sebuah program berbasis *Command Line Interface* (CLI) yang ditulis menggunakan bahasa C untuk melakukan simulasi dan analisis perbandingan waktu eksekusi dari berbagai algoritma pengurutan (*sorting*).

Proyek ini dibuat untuk memenuhi **Tugas 2 Praktikum Struktur Data dan Algoritma C** di Program Studi Informatika, Universitas Syiah Kuala.

---

## 👥 Anggota Kelompok
1. **Hanif Maulana** (NPM: 250810701100008) - *[Tugas: Selection Sort, Shell Sort]*
2. **Muhammad Albharaka Putrosandy** (NPM: 250810701100022) - *[Tugas: Insertion Sort & Merge Sort]*
3. **Arinal Haq** (NPM: 250810701100073) - *[Tugas: Bubble Sort & Quick Sort]*

---

## 🚀 Fitur Program

Program ini mengimplementasikan dua kategori algoritma pengurutan utama tanpa menggunakan fungsi *sorting* bawaan dari C:

### 1. Sorting Dasar (Basic Sorting)
Menggunakan **1000 data integer acak** (di-*generate* otomatis menggunakan `rand()`).
* **Bubble Sort**
* **Insertion Sort**
* **Selection Sort**

### 2. Advance Sorting
Menggunakan **dataset string (kata dalam Bahasa Inggris)** yang dibaca dari file `.txt`.
* **Merge Sort**
* **Quick Sort**
* **Shell Sort**

> **Catatan:** Seluruh data wajib diacak (di-*shuffle*) menggunakan kombinasi fungsi `rand()` dan metode *swap* sebelum proses pengurutan dimulai untuk menguji keandalan algoritma.

---

## 📂 Struktur Repositori

```text
TUGAS2-SDA-SORTINGC/
 ├── include/
 │    ├── sorting.h
 │    └── utils.h
 ├── src/
 │    ├── advanced/
 │    │    ├── data/
 │    │    │    └── words.txt
 │    │    ├── merge_sort.c
 │    │    ├── quick_sort.c
 │    │    └── shell_sort.c
 │    ├── basic/
 │    │    ├── bubble_sort.c
 │    │    ├── insertion_sort.c
 │    │    └── selection_sort.c
 │    ├── main.c
 │    ├── utils.c
 │    ├── Makefile
 │    └── compile.bat
 ├── .gitignore
 └── README.md
```

---

## 🛠️ Cara Menjalankan Program

Pastikan *compiler* **GCC** (MinGW) sudah terinstal di sistem Anda.

**1. Clone Repositori**
```bash
git clone [https://github.com/](https://github.com/)[username-kalian]/[nama-repo].git
cd [nama-repo]/src
```

**2. Kompilasi & Jalankan (Pilih salah satu cara)**

* **Opsi A: Menggunakan File Batch (Windows)**
  Sangat disarankan untuk pengguna Windows. Cukup jalankan perintah:
  ```bash
  .\compile.bat
  ```
    
* **Opsi B: Menggunakan Makefile**
  Jika menggunakan terminal Linux/Mac atau memiliki *Make* di Windows:
  ```bash
  make
  .\main
  ```

* **Opsi C: Kompilasi Manual**
  ```bash
  gcc main.c utils.c basic/*.c advanced/*.c -o main
  .\main
  ```

---

## 📊 Dataset
Dataset *string* yang digunakan pada bagian *Advance Sorting* diambil dari dataset publik Kaggle: [English Words Dataset](https://www.kaggle.com/datasets/jiprud/words-en).