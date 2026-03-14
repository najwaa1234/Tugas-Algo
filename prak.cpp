#include <stdio.h>
#include <string.h>

struct Film{
    char judul[100];
    double harga;
    int tahun;
    double rating;
};

struct Film film[100];
int n = 0;

void loadFile(){
    FILE *file = fopen("netfilm_db.txt","r");

    if(file == NULL){
        return;
    }

    while(fscanf(file," %[^;];%lf;%d;%lf\n",
        film[n].judul,
        &film[n].harga,
        &film[n].tahun,
        &film[n].rating) != EOF){
        n++;
    }

    fclose(file);
}

void saveFile(){
    FILE *file = fopen("netfilm_db.txt","w");

    for(int i=0;i<n;i++){
        fprintf(file,"%s;%.0lf;%d;%.1lf\n",
        film[i].judul,
        film[i].harga,
        film[i].tahun,
        film[i].rating);
    }

    fclose(file);
}

void tambahFilm(){
    printf("Judul : ");
    getchar();
    fgets(film[n].judul,100,stdin);
    film[n].judul[strcspn(film[n].judul,"\n")] = 0;

    printf("Harga : ");
    scanf("%lf",&film[n].harga);

    printf("Tahun : ");
    scanf("%d",&film[n].tahun);

    printf("Rating : ");
    scanf("%lf",&film[n].rating);

    n++;
}

void tampilFilm(){
    printf("\nDaftar Film\n");
    for(int i=0;i<n;i++){
        printf("%d. %s | %.0lf | %d | %.1lf\n",
        i+1,
        film[i].judul,
        film[i].harga,
        film[i].tahun,
        film[i].rating);
    }
}

void bubbleSort(){
    struct Film temp;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(film[j].judul,film[j+1].judul) > 0){
                temp = film[j];
                film[j] = film[j+1];
                film[j+1] = temp;
            }
        }
    }
}

void quickSort(int low,int high){
    int i = low;
    int j = high;
    double pivot = film[(low+high)/2].rating;
    struct Film temp;

    while(i<=j){
        while(film[i].rating > pivot) i++;
        while(film[j].rating < pivot) j--;

        if(i<=j){
            temp = film[i];
            film[i] = film[j];
            film[j] = temp;
            i++;
            j--;
        }
    }

    if(low<j) quickSort(low,j);
    if(i<high) quickSort(i,high);
}

void linearSearch(char cari[]){
    int ketemu = 0;

    for(int i=0;i<n;i++){
        if(strcmp(film[i].judul,cari)==0){
            printf("Film ditemukan: %s\n",film[i].judul);
            ketemu = 1;
        }
    }

    if(!ketemu){
        printf("Film tidak ditemukan\n");
    }
}

void binarySearch(char cari[]){
    int kiri=0, kanan=n-1;

    while(kiri<=kanan){
        int tengah=(kiri+kanan)/2;
        int hasil = strcmp(cari,film[tengah].judul);

        if(hasil==0){
            printf("Film ditemukan: %s\n",film[tengah].judul);
            return;
        }
        else if(hasil>0){
            kiri = tengah+1;
        }
        else{
            kanan = tengah-1;
        }
    }

    printf("Film tidak ditemukan\n");
}

int main(){
    int menu;
    char cari[100];

    loadFile();

    do{
        printf("\n=== NETFILM ===\n");
        printf("1. Tambah Film\n");
        printf("2. Tampilkan Film\n");
        printf("3. Sort Judul (Bubble)\n");
        printf("4. Sort Rating (Quick)\n");
        printf("5. Cari Film\n");
        printf("6. Simpan\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&menu);

        if(menu==1){
            tambahFilm();
        }
        else if(menu==2){
            tampilFilm();
        }
        else if(menu==3){
            bubbleSort();
        }
        else if(menu==4){
            quickSort(0,n-1);
        }
        else if(menu==5){
            getchar();
            printf("Masukkan judul: ");
            fgets(cari,100,stdin);
            cari[strcspn(cari,"\n")] = 0;

            if(n<30){
                linearSearch(cari);
            }else{
                bubbleSort();
                binarySearch(cari);
            }
        }
        else if(menu==6){
            saveFile();
        }

    }while(menu!=0);

    saveFile();
}