#include <iostream>
using namespace std;

struct Buku {
   string nama;
   int harga;
};

int main() {
   const int N = 5;

   Buku dataBuku[6] = {
      {"Cake Shop",              85000},
      {"Hello Cello",            99000},
      {"Hiranya dan Margonda",   90000},
      {"Lotus In The Mud",      110000},
      {"Malioboro at Midnight", 100000}
   };

   int i, awal, tengah, akhir;
   bool found;
   string namaCari;

   // Header toko
   cout << "=======================================" << endl;
   cout << "    SELAMAT DATANG DI TOKO BUKU MERAH   " << endl;
   cout << "=======================================" << endl;
   cout << endl;

   // Daftar buku
   cout << "------------ DAFTAR BUKU --------------" << endl;
   cout << "No  Nama Buku                  Harga  " << endl;
   cout << "---------------------------------------" << endl;
   cout << "1.  Cake Shop                  Rp" << dataBuku[0].harga << endl;
   cout << "2.  Hello Cello                Rp" << dataBuku[1].harga << endl;
   cout << "3.  Hiranya dan Margonda       Rp" << dataBuku[2].harga << endl;
   cout << "4.  Lotus In The Mud           Rp" << dataBuku[3].harga << endl;
   cout << "5.  Malioboro at Midnight      Rp" << dataBuku[4].harga << endl;
   cout << "---------------------------------------" << endl;
   cout << endl;

   cout << "Nama buku yang dicari = ";
   getline(cin, namaCari);
   cout << endl;

   // =====================================================
   // 1. SEQUENTIAL SEARCH BELUM URUT NON SENTINEL
   // =====================================================
   found = false;
   i = 0;
   while((i < N) & (!found))
   {
      if(dataBuku[i].nama == namaCari)
         found = true;
      else
         i = i + 1;
   }
   if(found)
      cout << namaCari << " ditemukan pada index ke-" << i << " dengan harga Rp" << dataBuku[i].harga << endl;
   else
      cout << "tidak ada " << namaCari << " dalam data Buku" << endl;

   // =====================================================
   // 2. SEQUENTIAL SEARCH BELUM URUT SENTINEL
   // =====================================================
   dataBuku[N].nama = namaCari;   // sentinel
   i = 0;
   while(dataBuku[i].nama != namaCari)
      i = i + 1;
   if(i > N-1)
      cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
   else
      cout << namaCari << " ditemukan pada index ke-" << i << " dengan harga Rp" << dataBuku[i].harga << endl;

   // =====================================================
   // 3. BINARY SEARCH (DATA HARUS SUDAH URUT)
   // =====================================================
   found = false;
   awal  = 0;
   akhir = N - 1;
   while((!found) & (awal <= akhir))
   {
      tengah = (awal + akhir) / 2;
      if(namaCari == dataBuku[tengah].nama)
         found = true;
      else
      {
         if(namaCari < dataBuku[tengah].nama)
            akhir = tengah - 1;  // awal tetap
         else
            awal = tengah + 1;   // akhir tetap
      }
   }
   if(found)
      cout << namaCari << " ditemukan pada index ke-" << tengah << " dengan harga Rp" << dataBuku[tengah].harga << endl;
   else
      cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
   cout << "------------------------------------------------------------" << endl;
}
