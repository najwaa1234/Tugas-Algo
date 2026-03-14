#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std; 

struct Film{
    char judul[100];
    int harga;
    int tahun;
    float rating;
};

Film film[100];
int jumlah = 0;

void menu(){
    cout << "\n+===================================+\n";
    cout << "|      NETFLIM SYSTEM - DASHBOARD     |\n";
    cout << "+=====================================+\n";
    cout << "|  [1] Lihat Katalog Film             |\n";
    cout << "|  [2] Urutkan Rating (Quick Sort)    |\n";
    cout << "|  [3] Urutkan Abjad (Bubble Sort)    |\n";
    cout << "|  [4] Cari Film (Linear Search)      |\n";
    cout << "|  [5] Cari Film (Binary Search)      |\n";
    cout << "|  [6] Tambah Film Baru               |\n";
    cout << "|  [0] Keluar & Simpan                |\n";
    cout << "+=====================================+\n";
    cout << "Pilih Menu [0-6]: ";
}