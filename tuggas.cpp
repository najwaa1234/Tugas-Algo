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
      cout << namaCari << " ditemukan pada index ke-" << i << " dengan harga " << dataBuku[i].harga << endl;
   else
      cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
   cout << endl;

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
      cout << namaCari << " ditemukan pada index ke-" << i << " dengan harga " << dataBuku[i].harga << endl;
   cout << endl;

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
      cout << namaCari << " ditemukan pada index ke-" << tengah << " dengan harga " << dataBuku[tengah].harga << endl;
   else
      cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
}
