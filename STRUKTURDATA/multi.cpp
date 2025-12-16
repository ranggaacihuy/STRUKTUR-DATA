#include "multi.h"

//create list
void createListPenyakit(ListPenyakit &LP) {
    LP.first = nullptr;
    LP.last = nullptr;
}

void createListPasien(ListPasien &LS) {
    LS.first = nullptr;
}

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

//create node
adrPenyakit createElmPenyakit(infotypeP x) {
    adrPenyakit P = new elmPenyakit;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

adrPasien createElmPasien(infotypeS x) {
    adrPasien P = new elmPasien;
    P->info = x;
    P->next = nullptr;
    return P;
}

adrRelasi createElmRelasi(adrPasien P, adrPenyakit Q) {
    adrRelasi R = new elmRelasi;
    R->pasien = P;
    R->penyakit = Q;
    R->next = nullptr;
    return R;
}
