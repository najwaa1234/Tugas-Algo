#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

struct mhs{
    char nim[20];
    char nama[30];
    float ipk;
};

void input(){
    mhs data;
    FILE *file;
    char namaFile[30];
    int n;

    printf("INPUT DATA\n");
    printf("Jumlah data yang akan diinput (max 100) : ");
    scanf("%d",&n);

    printf("Nama file penyimpanan : ");
    scanf("%s",namaFile);

    file = fopen(namaFile,"w");

    for(int i=0;i<n;i++){
        printf("\nData ke-%d\n",i+1);

        printf("NIM   : ");
        scanf("%s",data.nim);

        printf("Nama  : ");
        scanf("%s",data.nama);

        printf("IPK   : ");
        scanf("%f",&data.ipk);

        fprintf(file,"%s %s %f\n",data.nim,data.nama,data.ipk);
    }

    fclose(file);

    printf("\nData berhasil disimpan\n");
}

void tampil(){
    mhs data;
    FILE *file;
    char namaFile[30];

    printf("TAMPIL DATA\n");
    printf("==================================\n");
    printf("Nama file yang akan ditampilkan : ");
    scanf("%s",namaFile);

    file = fopen(namaFile,"r");

    if(file==NULL){
        printf("Error==================================\n");
        return;
    }

    printf("\nDATA MAHASISWA\n\n");

    while(fscanf(file,"%s %s %f",data.nim,data.nama,&data.ipk)!=EOF){
        printf("NIM   : %s\n",data.nim);
        printf("Nama  : %s\n",data.nama);
        printf("IPK   : %.2f\n\n",data.ipk);
    }

    fclose(file);
}

void sequential(){
    mhs data;
    FILE *file;
    char namaFile[30];
    char cari[20];
    int ketemu=0;

    printf("SEQUENSIAL SEARCH\n");
    printf("==================\n\n");

    printf("Data yang akan dicari dari file : ");
    scanf("%s",namaFile);

    file = fopen(namaFile,"r");

    if(file==NULL){
        printf("Error\n");
        return;
    }

    printf("NIM yang dicari : ");
    scanf("%s",cari);

    while(fscanf(file,"%s %s %f",data.nim,data.nama,&data.ipk)!=EOF){
        if(strcmp(data.nim,cari)==0){
            printf("\nData ditemukan\n");
            printf("NIM   : %s\n",data.nim);
            printf("Nama  : %s\n",data.nama);
            printf("IPK   : %.2f\n",data.ipk);
            ketemu=1;
        }
    }

    if(ketemu==0)
        printf("%s tidak ditemukan\n",cari);

    fclose(file);
}

void insertion(){
    mhs data[100],temp;
    FILE *file;
    char namaFile[30];
    int n=0;

    printf("Data yang akan disorting dari file : ");
    scanf("%s",namaFile);

    file = fopen(namaFile,"r");

    if(file==NULL){
        printf("Error\n");
        return;
    }

    while(fscanf(file,"%s %s %f",data[n].nim,data[n].nama,&data[n].ipk)!=EOF){
        n++;
    }

    fclose(file);

    for(int i=1;i<n;i++){
        temp=data[i];
        int j=i-1;

        while(j>=0 && data[j].ipk>temp.ipk){
            data[j+1]=data[j];
            j--;
        }

        data[j+1]=temp;
    }

    printf("\nData urut by IPK dengan INSERTION SORT\n\n");

    for(int i=0;i<n;i++){
        printf("NIM   : %s\n",data[i].nim);
        printf("Nama  : %s\n",data[i].nama);
        printf("IPK   : %.2f\n\n",data[i].ipk);
    }
}

int main(){

    int pilih;
    char ulang;

    do{

        printf("\nMENU UTAMA\n");
        printf("1. Input Data\n");
        printf("2. Tampil Data\n");
        printf("3. Searching\n");
        printf("4. Sorting\n");
        printf("5. Exit\n");
        printf("Pilih : ");
        scanf("%d",&pilih);

        system("cls");

        switch(pilih){

        case 1:
            input();
            printf("\nKembali ke Menu Utama(y/t)? ");
            scanf(" %c",&ulang);
            break;

        case 2:
            tampil();
            printf("\nKembali ke Menu Utama(y/t)? ");
            scanf(" %c",&ulang);
            break;

        case 3:
            do{
                sequential();
                printf("\nUlangi (y/t) : ");
                scanf(" %c",&ulang);
            }while(ulang=='y');
            ulang='y';
            break;

        case 4:
            do{
                printf("Pilih : 4\n");
                insertion();
                printf("\nUlangi (y/t) : ");
                scanf(" %c",&ulang);
            }while(ulang=='y');
            ulang='y';
            break;

        case 5:
            printf("Program selesai\n");
            return 0;

        default:
            printf("Pilihan salah\n");
        }

    }while(ulang=='y');

}
