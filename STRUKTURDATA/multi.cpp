#include "multi.h"

// Create List
void createListPenyakit(ListPenyakit &LP) {
    LP.first = nullptr;
    LP.last = nullptr;
}

void createListPasien(ListPasien &LS) {
    LS.first = nullptr;
    LS.last = nullptr;
}

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

// Create Node
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
    P->prev = nullptr;
    return P;
}

adrRelasi createElmRelasi(adrPasien P, adrPenyakit Q) {
    adrRelasi R = new elmRelasi;
    R->pasien = P;
    R->penyakit = Q;
    R->next = nullptr;
    return R;
}

// Insert
void insertPenyakit(ListPenyakit &LP, adrPenyakit P) {
    if (LP.first == nullptr) {
        LP.first = LP.last = P;
    } else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}

void insertPasien(ListPasien &LS, adrPasien S) {
    if (LS.first == nullptr) {
        LS.first = LS.last = S;
    } else {
        S->next = LS.first;
        LS.first->prev = S;
        LS.first = S;
    }
}

void insertRelasi(ListRelasi &LR, adrRelasi R) {
    R->next = LR.first;
    LR.first = R;
}

// Delete
void deletePasien(ListPasien &LS, ListRelasi &LR, string namaPasien) {
    adrPasien P = LS.first;

    while (P != nullptr && P->info.namaPasien != namaPasien) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Pasien tidak ditemukan\n";
        return;
    }

    // hapus relasi
    adrRelasi R = LR.first;
    adrRelasi prevR = nullptr;

    while (R != nullptr) {
        if (R->pasien == P) {
            adrRelasi temp = R;
            if (prevR == nullptr) {
                LR.first = R->next;
            } else {
                prevR->next = R->next;
            }
            R = R->next;
            temp->penyakit->info.penderita--;
            delete temp;
        } else {
            prevR = R;
            R = R->next;
        }
    }

    // hapus pasien
    if (P->prev != nullptr)
        P->prev->next = P->next;
    else
        LS.first = P->next;

    if (P->next != nullptr)
        P->next->prev = P->prev;
    else
        LS.last = P->prev;

    delete P;
}

void deletePenyakit(ListPenyakit &LP, ListRelasi &LR, string namaPenyakit) {
    adrPenyakit Q = LP.first;

    while (Q != nullptr && Q->info.namaPenyakit != namaPenyakit) {
        Q = Q->next;
    }

    if (Q == nullptr) {
        cout << "Penyakit tidak ditemukan\n";
        return;
    }

    // hapus relasi
    adrRelasi R = LR.first;
    adrRelasi prevR = nullptr;

    while (R != nullptr) {
        if (R->penyakit == Q) {
            adrRelasi temp = R;
            if (prevR == nullptr)
                LR.first = R->next;
            else
                prevR->next = R->next;

            R = R->next;
            delete temp;
        } else {
            prevR = R;
            R = R->next;
        }
    }

    // hapus penyakit
    if (Q->prev != nullptr)
        Q->prev->next = Q->next;
    else
        LP.first = Q->next;

    if (Q->next != nullptr)
        Q->next->prev = Q->prev;
    else
        LP.last = Q->prev;

    delete Q;
}

// Search
adrPasien findPasien(const ListPasien &LS, string nama) {
    adrPasien P = LS.first;
    while (P != nullptr) {
        if (P->info.namaPasien == nama)
            return P;
        P = P->next;
    }
    return nullptr;
}

adrPenyakit findPenyakit(const ListPenyakit &LP, string nama) {
    adrPenyakit P = LP.first;
    while (P != nullptr) {
        if (P->info.namaPenyakit == nama)
            return P;
        P = P->next;
    }
    return nullptr;
}

// Show
void showAllPasienPenyakit(const ListPasien &LS, const ListRelasi &LR) {
    adrPasien P = LS.first;

    while (P != nullptr) {
        cout << "Pasien: " << P->info.namaPasien << endl;
        cout << "Penyakit: ";

        adrRelasi R = LR.first;
        bool ada = false;

        while (R != nullptr) {
            if (R->pasien == P) {
                cout << R->penyakit->info.namaPenyakit << ", ";
                ada = true;
            }
            R = R->next;
        }

        if (!ada) cout << "-";
        cout << endl << "------------------\n";
        P = P->next;
    }
}

void showPasienDenganPenyakit(const ListRelasi &LR, string namaPenyakit) {
    adrRelasi R = LR.first;
    while (R != nullptr) {
        if (R->penyakit->info.namaPenyakit == namaPenyakit) {
            cout << R->pasien->info.namaPasien << endl;
        }
        R = R->next;
    }
}

void showPenyakitPadaPasien(const ListRelasi &LR, string namaPasien) {
    adrRelasi R = LR.first;
    while (R != nullptr) {
        if (R->pasien->info.namaPasien == namaPasien) {
            cout << R->penyakit->info.namaPenyakit << endl;
        }
        R = R->next;
    }
}

void showTop5Penyakit(const ListPenyakit &LP) {
    adrPenyakit top[5] = {nullptr};

    adrPenyakit P = LP.first;
    while (P != nullptr) {
        for (int i = 0; i < 5; i++) {
            if (top[i] == nullptr || P->info.penderita > top[i]->info.penderita) {
                for (int j = 4; j > i; j--)
                    top[j] = top[j - 1];
                top[i] = P;
                break;
            }
        }
        P = P->next;
    }

    cout << "Top 5 Penyakit:\n";
    for (int i = 0; i < 5; i++) {
        if (top[i] != nullptr) {
            cout << i + 1 << ". "
                 << top[i]->info.namaPenyakit
                 << " (" << top[i]->info.penderita << " pasien)\n";
        }
    }
}

// Relasi
void relasiPasienDanPenyakit(ListRelasi &LR, adrPasien P, adrPenyakit Q) {
    if (P == nullptr || Q == nullptr) {
        cout << "Relasi gagal\n";
        return;
    }

    adrRelasi R = createElmRelasi(P, Q);
    insertRelasi(LR, R);
    Q->info.penderita++;
}
