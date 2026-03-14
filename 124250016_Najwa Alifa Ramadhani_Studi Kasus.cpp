#include <iostream>
using namespace std;

struct Buku {
	string nama;
	int harga;
};

int main() {
	
	const int N = 5;
	
	Buku dataBuku[6] = {
		{"Cake Shop", 85000},
		{"Hello Cello", 99000},
		{"Hiranya dan Margonda", 90000},
		{"Lotus In The Mud", 110000},
		{"Malioboro at Midnight", 100000}
};

	int i, awal, tengah, akhir;
	bool found;
	string namaCari;
	
	//header toko buku
	cout << "=======================================" << endl;
	cout << "   SELAMAT DATANG DI TOKO BUKU MERAH   " << endl;
	cout << "=======================================" << endl;
	cout << endl;
	
	//menampilkan daftar buku
	cout << "-------- DAFTAR BUKU --------" << endl;
    cout << "No  Nama Buku                " << endl;
    cout << "-----------------------------" << endl;
    cout << "1.  Cake Shop                " << endl;
    cout << "2.  Hello Cello              " << endl;
    cout << "3.  Hiranya dan Margonda     " << endl;
    cout << "4.  Lotus In The Mud         " << endl;
    cout << "5.  Malioboro at Midnight    " << endl;
    cout << "-----------------------------" << endl;
    cout << endl;
	
	cout << "Nama Buku Yang Dicari : ";
	getline(cin, namaCari);
	cout << endl;
	
	//1. SEQUENTIAL SEARCH NON SENTINEL
	
	found = false;
	i = 0;
	while((i < N) & (!found)) {
		if(dataBuku[i].nama == namaCari) {
			found = true;
		} else {
			i = i + 1;
		}
	}
	if(found) {
		cout << "Buku ditemukan!"<< endl;
		cout << "Nama : " << dataBuku[i].nama << endl;
		cout << "Harga : Rp" << dataBuku[i].harga << endl;
	} else { 
		cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
	}
	cout << endl;
	
	//2. SEQUENTIAL SEARCH DENGAN SENTINEL
	
	dataBuku[N].nama = namaCari; //sentinel
	i = 0;
	while(dataBuku[i].nama != namaCari) {
		i = i + 1;
	}
	if(i > N-1) { 
		cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
	} else {
		cout << "Buku ditemukan!"<< endl;
		cout << "Nama : " << dataBuku[i].nama << endl;
		cout << "Harga : Rp" << dataBuku[i].harga << endl;
	}
	cout << endl;
		
	//3. BINARY SEARCH
	
	found = false;
	awal = 0;
	akhir = N - 1;
	
	while((!found) & (awal <= akhir)) {
		tengah = (awal + akhir) / 2; //untuk mencari index tengah
		if(namaCari == dataBuku[tengah].nama) {
			found = true;
		} else if(namaCari < dataBuku[tengah].nama) {
				akhir = tengah - 1; //mencari dibagian kiri
		} else if(namaCari > dataBuku[tengah].nama) { 
				awal = tengah + 1; //mencari dibagian kanan
			}
		}
		if(found) {
			cout << "Buku ditemukan!"<< endl;
			cout << "Nama : " << dataBuku[i].nama << endl;
			cout << "Harga : Rp" << dataBuku[i].harga << endl;
		} else { 
			cout << "tidak ada " << namaCari << " dalam data Buku" << endl;
		}
		cout << "-----------------------------------------" << endl;
}
	
	
		

