#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const char namaFile[] = "netflim_db.txt";

struct Film{
	char judul[100];
	int harga;
	int tahun;
	float rating;
};

Film dataFilm[100];
int jumlahFilm = 0;

void pauseProgram(){
	cout << "\nTekan enter untuk melanjutkan..." << endl;
	cin.ignore();
	cin.get();
}

void menu(){
	cout << "-------------------------------------------\n";
	cout << "|       NETFLIM SYSTEM - DASHBOARD        |\n";
	cout << "-------------------------------------------\n";
	cout << "| [1] Lihat Katalog Film                  |\n";
	cout << "| [2] Urutkan Rating (Quick Sort)         |\n";
	cout << "| [3] Urutkan Judul (Bubble Sort)         |\n";
	cout << "| [4] Cari Film (Linear Search)           |\n";
	cout << "| [5] Cari Film (Binary Search)           |\n";
	cout << "| [6] Tambah Film Baru                    |\n";
	cout << "| [0] Keluar & Simpan                     |\n";
	cout << "-------------------------------------------\n";
	cout << "Pilih Menu > ";
}

void bacaFile(){
	FILE *file = fopen(namaFile, "r");
	if(file == NULL) 
	return;
	
	jumlahFilm = 0;
	
	while(fscanf(file, " %99[^;];%d;%d;%f", dataFilm[jumlahFilm].judul, &dataFilm[jumlahFilm].harga, &dataFilm[jumlahFilm].tahun, &dataFilm[jumlahFilm].rating) != EOF && jumlahFilm < 100) {
		jumlahFilm++;
	}
	fclose(file);
}

void saveFile(){
	FILE *file = fopen(namaFile, "w");
	if(file == NULL) {
		cout << "File tidak bisa dibuka" << endl;
		return;
	}
	for(int i=0; i < jumlahFilm; i++){
		fprintf(file, "%s;%d;%d;%.1f\n", dataFilm[i].judul, dataFilm[i].harga, dataFilm[i].tahun, dataFilm[i].rating);
	}
	fclose(file);
}

void tampilKatalog(){
	cout << "\n";
	cout << "N E T F I L M  C O N T E N T  K A T A L O G" << endl;
	cout << setfill('-') << setw(56) << "-" << endl;
	cout << setfill(' ');
	cout << left << setw(5) << "ID" << setw(25) << "JUDUL FILM" << setw(12) << "HARGA" << setw(8) << "TAHUN" << setw(6) << "RATING" << endl;
	cout << setfill('-') << setw(56) << "-" << endl;
	cout << setfill(' ');
	
	if(jumlahFilm == 0){
		cout << "Data film masih kosong" << endl;
		return;
	}
	for(int i=0; i < jumlahFilm; i++){
		cout << left << setw(5) << i+1 << setw(25) << dataFilm[i].judul << "Rp " << setw(9) << dataFilm[i].harga << setw(8) << dataFilm[i].tahun << setw(6) << dataFilm[i].rating << endl;
	}
	cout << setfill('-') << setw(56) << "-" << endl;
}

void bubbleSortJudul(){
	for(int i=0; i < jumlahFilm-1; i++){
		for (int j=0; j < jumlahFilm-1-i; j++){
		int k = 0;
		
		while(dataFilm[j].judul[k] == dataFilm[j+1].judul[k] && dataFilm[j].judul[k] != '\0'){
			k++;
		}
		
		if(dataFilm[j].judul[k] > dataFilm[j+1].judul[k]){
			Film temp = dataFilm[j];
			dataFilm[j] = dataFilm[j+1];
			dataFilm[j+1] =  temp;
			}
		}
	}
	
}

void quickSortRating(int kiri, int kanan){
	int i = kiri;
	int j = kanan;
	
	float pivot = dataFilm[(kiri+kanan) / 2].rating;
	while(i <= j){
		while(dataFilm[i].rating > pivot) i++;
		while(dataFilm[j].rating < pivot) j--;
		
		if(i <= j){
			Film temp = dataFilm[i];
			dataFilm[i] = dataFilm[j];
			dataFilm[j] = temp;
			i++;
			j--;
		}
	}
	
	if(kiri < j) quickSortRating(kiri, j);
	if(i < kanan) quickSortRating(i, kanan);
}

void linearSearchJudul(){
	char cari[100];
	bool found;
	int i, j;
	
	cin.ignore();
	cout << "\nMasukkan Judul : ";
	cin.getline(cari, 100);
	
	found = false;
	i = 0;
	
	while(i < jumlahFilm && !found){
		j = 0;
	while(dataFilm[i].judul[j] == cari[j] && cari[j] != '\0'){
		j++;
	}
	if(dataFilm[i].judul[j] == cari[j])
		found = true;
	else i++;
	}
	cout << "Keyword Judul  : " << cari << endl;
	
	if(found){
		cout << "[ FOUND ] " << dataFilm[i].judul << " (" << dataFilm[i].tahun << ")" << endl;
	}
	else{
		cout << "[ NOT FOUND ] Film tidak ditemukan" << endl;
	}
}

void binarySearchJudul(){
	char cari[100];
	int kiri, kanan, tengah;
	bool found;
	
	bubbleSortJudul(); //data harus terurut
	
	cin.ignore();
	cout << "\nMasukkan Judul : ";
	cin.getline(cari, 100);
	
	kiri = 0;
	kanan = jumlahFilm - 1;
	found = false;
	
	while(kiri <= kanan && !found){
		tengah = (kiri + kanan) / 2;
		
	int k = 0;
	while(dataFilm[tengah].judul[k] == cari[k] && cari[k] != '\0'){
		k++;
	}
	if(dataFilm[tengah].judul[k] == cari[k])
		found = true;
	else if (dataFilm[tengah].judul[k] < cari[k])
		kiri = tengah + 1;
	else
		kanan = tengah - 1;
	}
	if(found){
		cout << "[ FOUND ] " << dataFilm[tengah].judul << " (" << dataFilm[tengah].tahun << ")" << endl;
	}
	else{
		cout << "[!] Judul yang dimasukkan tidak ada dalam data" << endl;
	}
}

void tambahFilm(){
	if(jumlahFilm >= 100){
		cout <<"Kapasitas data penuh" << endl;
		return;
	}
	cin.ignore(1000, '\n');
	
	cout << "\nMasukkan Judul Film : ";
	cin.getline(dataFilm[jumlahFilm].judul, 100);
	cout << "Masukkan Harga : ";
	cin >> dataFilm[jumlahFilm].harga;
	cout << "Masukkan Tahun : ";
	cin >> dataFilm[jumlahFilm].tahun;
	cout << "Masukkan Rating : ";
	cin >> dataFilm[jumlahFilm].rating;
	jumlahFilm++;
	
	saveFile();
	cout << "Data berhasil ditambahkan" << endl;
	cout << "--------------------------------------" << endl;
}

int main(){
	int pilih;
	bacaFile();
	
	do {
		menu();
		cin >> pilih;
		
		switch(pilih) {
			case 1: 
				tampilKatalog();
				pauseProgram();
				break;
			case 2: 
				quickSortRating(0, jumlahFilm-1);
				tampilKatalog();
				cout << "[ INFO ] Data film sudah diurutkan berdasarkan rating." << endl;
				pauseProgram();
				break;
			case 3: 
				bubbleSortJudul();
				tampilKatalog();
				cout << "[ INFO ] Data film sudah diurutkan berdsarkan abjad (A-Z)" << endl;
				pauseProgram();
				break;
			case 4: 
				linearSearchJudul();
				pauseProgram();
				break;
			case 5: 
				binarySearchJudul();
				pauseProgram();
				break;
			case 6: 
				tambahFilm();
				pauseProgram();
				 break;
			case 0: 	
				saveFile();
				cout << "\nData berhasil disimpan. Program selesai" << endl;
				break;
			}
				 
				} while(pilih !=0);
				 
				 return 0;
}
