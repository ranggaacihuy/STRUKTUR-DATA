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

//insert list
void insertPenyakit(ListPenyakit &LP, adrPenyakit P) {
    if (LP.first == nullptr) {
        LP.first = P;
        LP.last = P;
    } else {
        LP.last->next = P;
        LP.last = P;
    }
}

void insertPasien(ListPasien &LS, adrPasien S) {
    if (LS.first == nullptr) {
        LS.first = S;
    } else {
        S->next = LS.first;
        LS.first = S;
    }
}

void insertRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }
}

// delete
void deletePasien(ListPasien &LS, ListRelasi &LR, string namaPasien) {
    adrPasien P = LS.first;
    adrPasien prevP = nullptr;

    while (P != nullptr && P->info.nama != namaPasien) {
        prevP = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Pasien tidak ditemukan" << endl;
        return;
    }

    adrRelasi R = LR.first;
    adrRelasi prevR = nullptr;

    while (R != nullptr) {
        if (R->pasien == P) {
            adrRelasi temp = R;

            if (prevR == nullptr) {
                LR.first = R->next;
                R = LR.first;
            } else {
                prevR->next = R->next;
                R = prevR->next;
            }

            delete temp;
        } else {
            prevR = R;
            R = R->next;
        }
    }

    if (prevP == nullptr) {
        LS.first = P->next;
    } else {
        prevP->next = P->next;
    }

    delete P;
    cout << "Pasien berhasil dihapus" << endl;
}

void deletePenyakit(ListPenyakit &LP, ListRelasi &LR, string namaPenyakit) {
     adrPenyakit Q = LP.first;

    while (Q != nullptr && Q->info.nama != namaPenyakit) {
        Q = Q->next;
    }

    if (Q == nullptr) {
        cout << "Penyakit tidak ditemukan" << endl;
        return;
    }

    adrRelasi R = LR.first;
    adrRelasi prevR = nullptr;

    while (R != nullptr) {
        if (R->penyakit == Q) {
            adrRelasi temp = R;

            if (prevR == nullptr) {
                LR.first = R->next;
                R = LR.first;
            } else {
                prevR->next = R->next;
                R = prevR->next;
            }

            delete temp;
        } else {
            prevR = R;
            R = R->next;
        }
    }

    if (Q->prev != nullptr) {
        Q->prev->next = Q->next;
    } else {
        LP.first = Q->next;
    }

    if (Q->next != nullptr) {
        Q->next->prev = Q->prev;
    } else {
        LP.last = Q->prev;
    }

    delete Q;
    cout << "Penyakit berhasil dihapus" << endl;
}

// search
adrPasien findPasien(const ListPasien &LS, string nama) {
    adrPasien P = LS.first;
    while (P != nullptr) {
        if (P->info.nama == nama) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrPenyakit findPenyakit(const ListPenyakit &LP, string nama) {
    adrPenyakit P = LP.first;

    while (P != nullptr) {
        if (P->info.nama == nama) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// show
void showAllPasienPenyakit(const ListPasien &LS, const ListRelasi &LR) {
    adrPasien P = LS.first;

    while (P != nullptr) {
        cout << "Pasien : " << P->info.nama << endl;
        cout << "Penyakit : ";

        adrRelasi R = LR.first;
        bool ada = false;

        while (R != nullptr) {
            if (R->pasien == P) {
                cout << R->penyakit->info.nama << ", ";
                ada = true;
            }
            R = R->next;
        }

        if (!ada) {
            cout << "-";
        }

        cout << endl << "------------------" << endl;
        P = P->next;
    }
}

void showPasienDenganPenyakit(const ListRelasi &LR, string namaPenyakit) {
    adrRelasi R = LR.first;
    bool ketemu = false;
    cout << "Pasien dengan penyakit " << namaPenyakit << ":" << endl;
    while (R != nullptr) {
        if (R->penyakit->info.nama == namaPenyakit) {
            cout << "- " << R->pasien->info.nama << endl;
            ketemu = true;
        }
        R = R->next;
    }
    if (!ketemu) {
        cout << "Tidak ada pasien dengan penyakit tersebut." << endl;
    }
}

void showPenyakitPadaPasien(const ListRelasi &LR, string namaPasien) {
    adrRelasi R = LR.first;
    bool ketemu = false;
    cout << "Penyakit yang dimiliki pasien " << namaPasien << ":" << endl;
    while (R != nullptr) {
        if (R->pasien->info.nama == namaPasien) {
            cout << "- " << R->penyakit->info.nama << endl;
            ketemu = true;
        }
        R = R->next;
    }
    if (!ketemu) {
        cout << "Pasien tidak memiliki penyakit atau tidak ditemukan." << endl;
    }
}

void showTop5Penyakit(const ListPenyakit &LP) {
    adrPenyakit P;
     adrPenyakit top[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    P = LP.first;
    while (P != nullptr) {
        for (int i = 0; i < 5; i++) {
            if (top[i] == nullptr || P->info.jumlah > top[i]->info.jumlah) {
                for (int j = 4; j > i; j--) {
                    top[j] = top[j - 1];
                }
                top[i] = P;
                break;
            }
        }
        P = P->next;
    }

    cout << "Top 5 Penyakit Terbanyak:" << endl;
    for (int i = 0; i < 5; i++) {
        if (top[i] != nullptr) {
            cout << i + 1 << ". "
                 << top[i]->info.nama
                 << " (" << top[i]->info.jumlah << " pasien)" << endl;
        }
    }
}

// relasi
void relasiPasienDanPenyakit(ListRelasi &LR, adrPasien P, adrPenyakit Q) {
     if (P == nullptr || Q == nullptr) {
        cout << "Data pasien atau penyakit tidak ditemukan" << endl;
        return;
    }

    adrRelasi R = createElmRelasi(P, Q);

    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }

    Q->info.jumlah++;
}

