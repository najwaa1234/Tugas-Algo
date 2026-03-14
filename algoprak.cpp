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
    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.ignore(1000,'\n');
    cin.get();
}

void menu(){
    cout << "\n-------------------------------------------\n";
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
    FILE *file = fopen(namaFile,"r");
    if(file == NULL) return;

    jumlahFilm = 0;

    while(fscanf(file," %99[^;];%d;%d;%f\n",
        dataFilm[jumlahFilm].judul,
        &dataFilm[jumlahFilm].harga,
        &dataFilm[jumlahFilm].tahun,
        &dataFilm[jumlahFilm].rating) != EOF){
        jumlahFilm++;
    }

    fclose(file);
}

void saveFile(){
    FILE *file = fopen(namaFile,"w");

    if(file == NULL){
        cout<<"File tidak bisa dibuka\n";
        return;
    }

    for(int i=0;i<jumlahFilm;i++){
        fprintf(file,"%s;%d;%d;%.1f\n",
        dataFilm[i].judul,
        dataFilm[i].harga,
        dataFilm[i].tahun,
        dataFilm[i].rating);
    }

    fclose(file);
}

void tampilKatalog(){

    cout<<"\nNETFLIM CONTENT KATALOG\n";

    cout<<setfill('-')<<setw(60)<<"-"<<endl;
    cout<<setfill(' ');

    cout<<left
        <<setw(5)<<"ID"
        <<setw(25)<<"JUDUL FILM"
        <<setw(10)<<"HARGA"
        <<setw(10)<<"TAHUN"
        <<setw(5)<<"RATE"<<endl;

    cout<<setfill('-')<<setw(60)<<"-"<<endl;
    cout<<setfill(' ');

    if(jumlahFilm==0){
        cout<<"Data film kosong\n";
        return;
    }

    for(int i=0;i<jumlahFilm;i++){

        cout<<left
            <<setw(5)<<i+1
            <<setw(25)<<dataFilm[i].judul
            <<setw(10)<<dataFilm[i].harga
            <<setw(10)<<dataFilm[i].tahun
            <<setw(5)<<dataFilm[i].rating
            <<endl;
    }

    cout<<setfill('-')<<setw(60)<<"-"<<endl;
}

void bubbleSortJudul(){

    for(int i=0;i<jumlahFilm-1;i++){
        for(int j=0;j<jumlahFilm-1-i;j++){

            int k=0;

            while(dataFilm[j].judul[k]==dataFilm[j+1].judul[k] &&
                  dataFilm[j].judul[k]!='\0'){
                k++;
            }

            if(dataFilm[j].judul[k] > dataFilm[j+1].judul[k]){

                Film temp=dataFilm[j];
                dataFilm[j]=dataFilm[j+1];
                dataFilm[j+1]=temp;
            }
        }
    }
}

void quickSortRating(int kiri,int kanan){

    if(kiri>=kanan) return;

    int i=kiri;
    int j=kanan;

    float pivot=dataFilm[(kiri+kanan)/2].rating;

    while(i<=j){

        while(dataFilm[i].rating>pivot) i++;
        while(dataFilm[j].rating<pivot) j--;

        if(i<=j){

            Film temp=dataFilm[i];
            dataFilm[i]=dataFilm[j];
            dataFilm[j]=temp;

            i++;
            j--;
        }
    }

    if(kiri<j) quickSortRating(kiri,j);
    if(i<kanan) quickSortRating(i,kanan);
}

int linearSearchJudul(char cari[]){

    for(int i=0;i<jumlahFilm;i++){

        int j=0;

        while(dataFilm[i].judul[j]==cari[j] &&
              dataFilm[i].judul[j]!='\0'){
            j++;
        }

        if(dataFilm[i].judul[j]=='\0' &&
           cari[j]=='\0'){
            return i;
        }
    }

    return -1;
}

int main(){

    int pilih;

    //bacaFile();

    do{

        menu();
        cin>>pilih;

        switch(pilih){

        case 1:
            tampilKatalog();
            pauseProgram();
            break;

        case 2:
            if(jumlahFilm>0)
                quickSortRating(0,jumlahFilm-1);

            tampilKatalog();
            pauseProgram();
            break;

        case 3:
            bubbleSortJudul();
            tampilKatalog();
            pauseProgram();
            break;

        case 0:
            saveFile();
            cout<<"Data disimpan\n";
            break;

        }

    }while(pilih!=0);

    return 0;
}
