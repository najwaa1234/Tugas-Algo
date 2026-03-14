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
    cout << "\n+=====================================+\n";
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

void bacaFile(){
    FILE *file = fopen("netfilm_db.txt","r");

    if(file==NULL) return;

    jumlah = 0;

    while(fscanf(file," %[^;];%d;%d;%f\n",
        film[jumlah].judul,
        &film[jumlah].harga,
        &film[jumlah].tahun,
        &film[jumlah].rating)!=EOF){
        jumlah++;
    }

    fclose(file);
}

void simpanFile(){
    FILE *file = fopen("netfilm_db.txt","w");

    for(int i=0;i<jumlah;i++){
        fprintf(file,"%s;%d;%d;%.1f\n",
        film[i].judul,
        film[i].harga,
        film[i].tahun,
        film[i].rating);
    }

    fclose(file);
}

void tambahFilm(){

    cin.ignore();

    cout<<"Judul Film : ";
    cin.getline(film[jumlah].judul,100);

    cout<<"Harga : ";
    cin>>film[jumlah].harga;

    cout<<"Tahun : ";
    cin>>film[jumlah].tahun;

    cout<<"Rating : ";
    cin>>film[jumlah].rating;

    jumlah++;

    simpanFile();

    cout<<"Data berhasil ditambahkan\n";
}

void tampilFilm(){

    if(jumlah==0){
        cout<<"Data kosong\n";
        return;
    }

    cout<<"\n=============================================================\n";
    cout<<left<<setw(5)<<"No"
        <<setw(25)<<"Judul"
        <<setw(10)<<"Harga"
        <<setw(10)<<"Tahun"
        <<setw(10)<<"Rating"<<endl;

    cout<<"=============================================================\n";

    for(int i=0;i<jumlah;i++){
        cout<<left<<setw(5)<<i+1
            <<setw(25)<<film[i].judul
            <<setw(10)<<film[i].harga
            <<setw(10)<<film[i].tahun
            <<setw(10)<<film[i].rating
            <<endl;
    }

    cout<<"=============================================================\n";
}

void bubbleSort(){

    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){

            if(strcmp(film[j].judul,film[j+1].judul)>0){

                Film temp = film[j];
                film[j] = film[j+1];
                film[j+1] = temp;

            }
        }
    }

    cout<<"Data berhasil diurutkan berdasarkan judul\n";
}

int main(){

    bacaFile();

    int pilih;

    do{

        menu();

        cout<<"Pilih Menu : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            tambahFilm();
            break;

        case 2:
            tampilFilm();
            break;

        case 3:
            bubbleSort();
            tampilFilm();
            break;

        }

    }while(pilih!=0);

}
