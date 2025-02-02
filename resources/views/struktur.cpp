#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[255];
    char npm[255];
    char tempat_lahir[255];
    char tanggal_lahir[255];
    char prodi[255];
} Mahasiswa;

Mahasiswa mhs[100];
int count = 0;

void tambahData(const char nama[], const char npm[], const char tempat_lahir[], const char tanggal_lahir[], const char prodi[]) {
    if (count < 100) {
        strcpy(mhs[count].nama, nama);
        strcpy(mhs[count].npm, npm);
        strcpy(mhs[count].tempat_lahir, tempat_lahir);
        strcpy(mhs[count].tanggal_lahir, tanggal_lahir);
        strcpy(mhs[count].prodi, prodi);
        count++;
        printf("Data berhasil ditambahkan.\n");
    } else {
        printf("Tidak bisa menambah data, kapasitas penuh.\n");
    }
}

void tampilData() {
    if (count == 0) {
        printf("Data tidak ada.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Mahasiswa ke-%d:\n", i + 1);
            printf("Nama: %s\n", mhs[i].nama);
            printf("NPM: %s\n", mhs[i].npm);
            printf("Tempat Lahir: %s\n", mhs[i].tempat_lahir);
            printf("Tanggal Lahir: %s\n", mhs[i].tanggal_lahir);
            printf("Prodi: %s\n", mhs[i].prodi);
            printf("\n");
        }
    }
}

void hapusData(int index) {
    if (index < 0 || index >= count) {
        printf("Indeks mahasiswa tidak valid.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        mhs[i] = mhs[i + 1];
    }
    count--;
    printf("Mahasiswa pada indeks %d berhasil dihapus.\n", index + 1);
}

int main() {
    printf("Daftar Mahasiswa:\n");
    tampilData();

    tambahData("Bagas", "062023232232", "Bandung", "2000-01-01", "Informatika");
    tambahData("Susan", "062020103232", "Majalengka", "2002-01-02", "Industri");