#include <iostream>
using namespace std;

int main() {
	//file text
	const char* filename = "data.bin"; 
	FILE* file_ptr = fopen(filename, "wb"); //membuka
	
	if (file_ptr == NULL) {
		cout << "gagal membaca file!";
		exit(1); 
	}
	cout << "file berhasil dibaca!";
	
	//operasi disini
	//fprint
	//~ fprintf(file_ptr, "%s", "praktikum algo 2!");
	//~ //fputs
	//~ fputs("praktikum algo!", file_ptr);
	
	//~ int angka = 100;
	//~ //fwrite
	//~ fwrite(&angka, sizeof(int), 1, file_ptr);
	
	//fread
	fread(hasil_baca, sizeof(int), 1, file_ptr);
	//fread
	fread(hasil_baca, sizeof(int), 1, file_ptr);
	
	//tutup file
	fclose(file_ptr);
	
}


