#include "multi.h"

int main() {
    ListPenyakit LP;
    ListPasien LS;
    ListRelasi LR;

    createListPenyakit(LP);
    createListPasien(LS);
    createListRelasi(LR);

    int pilih;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Penyakit\n";
        cout << "2. Tambah Pasien\n";
        cout << "3. Hubungkan Pasien & Penyakit\n";
        cout << "4. Tampilkan Semua Data\n";
        cout << "5. Top 5 Penyakit\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        cin.ignore();

        if (pilih == 1) {
            infotypeP p;
            cout << "Nama Penyakit: ";
            getline(cin, p.namaPenyakit);
            p.penderita = 0;

            adrPenyakit P = createElmPenyakit(p);
            insertPenyakit(LP, P);
        }
        else if (pilih == 2) {
            infotypeS s;
            cout << "Nama Pasien: ";
            getline(cin, s.namaPasien);
            cout << "Umur: ";
            cin >> s.umur;
            cin.ignore();
            cout << "Alamat: ";
            getline(cin, s.alamat);

            adrPasien S = createElmPasien(s);
            insertPasien(LS, S);
        }
        else if (pilih == 3) {
            string namaPasien, namaPenyakit;
            cout << "Nama Pasien: ";
            getline(cin, namaPasien);
            cout << "Nama Penyakit: ";
            getline(cin, namaPenyakit);

            adrPasien P = findPasien(LS, namaPasien);
            adrPenyakit Q = findPenyakit(LP, namaPenyakit);

            relasiPasienDanPenyakit(LR, P, Q);
        }
        else if (pilih == 4) {
            showAllPasienPenyakit(LS, LR);
        }
        else if (pilih == 5) {
            showTop5Penyakit(LP);
        }

    } while (pilih != 0);

    return 0;
}
