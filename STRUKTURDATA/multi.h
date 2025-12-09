#ifndef MULTI_H
#define MULTI_H

#include <iostream>
#include <string>
using namespace std;

typedef Penyakit infotypeP;
typedef Pasien infotypeS;
typedef elmPenyakit* adrPenyakit;
typedef elmPasien* adrPasien;
typedef elmRelasi* adrRelasi;

// node penyakit
struct Penyakit {
    string namaPenyakit;
    int penderita;
};

// node pasien
struct Pasien {
    string namaPasien;
    int umur;
    string alamat;
};

// node list penyakit
struct elmPenyakit {
    infotypeP info;
    elmPenyakit *next;
    elmPenyakit *prev;
};

// node list pasien
struct elmPasien {
    infotypeS info;
    elmPasien *next;
    elmPasien *prev;
};

// node list relasi
struct elmRelasi {
    adrPasien pasien;
    adrPenyakit penyakit;
    elmRelasi *next;
};

// list
struct ListPenyakit {
    adrPenyakit first;
    adrPenyakit last;
};

struct ListPasien {
    adrPasien first;
    adrPasien last;
};

struct ListRelasi {
    adrRelasi first;
};


// create list
void createListPenyakit(ListPenyakit &LP);
void createListPasien(ListPasien &LS);
void createListRelasi(ListRelasi &LR);

// create node
adrPenyakit createElmPenyakit(infotypeP x);
adrPasien createElmPasien(infotypeS x);
adrRelasi createElmRelasi(adrPasien P, adrPenyakit Q);

// insert
void insertPenyakit(ListPenyakit &LP, adrPenyakit P);
void insertPasien(ListPasien &LS, adrPasien S);
void insertRelasi(ListRelasi &LR, adrRelasi R);

// delete
void deletePasien(ListPasien &LS, ListRelasi &LR, string namaPasien);
void deletePenyakit(ListPenyakit &LP, ListRelasi &LR, string namaPenyakit);

// search
adrPasien findPasien(const ListPasien &LS, string nama);
adrPenyakit findPenyakit(const ListPenyakit &LP, string nama);

// show
void showAllPasienPenyakit(const ListPasien &LS, const ListRelasi &LR);
void showPasienDenganPenyakit(const ListRelasi &LR, string namaPenyakit);
void showPenyakitPadaPasien(const ListRelasi &LR, string namaPasien);
void showTop5Penyakit(const ListPenyakit &LP);

// relasi
void relasiPasienDanPenyakit(ListRelasi &LR, adrPasien P, adrPenyakit Q);

#endif
