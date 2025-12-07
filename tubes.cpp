#include "tubes.h"

void createListKelompok(listKelompok &LKp) {
    firstKelompok(LKp) = NULL;
}

void createListAnggota(listAnggota &LA) {
    firstAnggota(LA) = NULL;
    lastAnggota(LA) = NULL;
}

adr_kelompok allocateKelompok(infotype_kelompok dataKelompok) {
    adr_kelompok P = new elmKelompok;
    infoKelompok(P) = dataKelompok;
    nextKelompok(P) = NULL;
    createListAnggota(dataAnggota(P));
    return P;
}

adr_anggota allocateAnggota(infotype_anggota dataAnggota) {
    adr_anggota A = new elmAnggota;
    infoAnggota(A) = dataAnggota;
    nextAnggota(A) = NULL;
    prevAnggota(A) = NULL;
    return A;
}

void insertFirstKelompok(listKelompok &LKp, adr_kelompok P) {
    /*
    { I.S.: listKelompok LKp mungkin kosong, adr_kelompok P menunjuk ke
    elemen list yang akan ditambah
    F.S.: Data kelompok baru akan dimasukkan ke dalam list kelompok
    dan menjadi elemen pertama
    }
    */
    if (firstKelompok(LKp) == NULL) {
        firstKelompok(LKp) = P;
    } else {
        nextKelompok(P) = firstKelompok(LKp);
        firstKelompok(LKp) = P;
    }
}

void showAllKelompok(listKelompok LKp) {
    /*
    { I.S.: listKelompok LKp mungkin kosong
    F.S.: Menampilkan semua data kelompok dan atribut-atributnya
    }
    */
    if(firstKelompok(LKp) == NULL) {
        cout << "Kelompok Kosong" << endl;
        cout << endl;
    } else {
        adr_kelompok P = firstKelompok(LKp);
        int i = 1;
        cout << endl;

        vector<vector<string>> t;
        t.push_back({"NO","ID","NAMA", "KATEGORI", "TANGGAL MULAI", "TANGGAL SELESAI"});
        while(P != NULL) {
            t.push_back({to_string(i), to_string(infoKelompok(P).ID_kelompok), infoKelompok(P).nama_kelompok, infoKelompok(P).kategori_kelompok, infoKelompok(P).tanggal_mulai_kelompok, infoKelompok(P).tanggal_selesai_kelompok});
            P = nextKelompok(P);
            i++;
        }

        table(t);
    }
}

void deleteKelompokDanAnggota(listKelompok &LKp) {
    /*
    { I.S.: listKelompok LKp mungkin kosong
    F.S.: Data terakhir kelompok berdasarkan ID kelompok terhapus dan
    data anggota berdasarkan ID anggota terhapus
    }
    */
    if (firstKelompok(LKp) == NULL) {
        cout << "Kelompok Kosong" << endl;
    } else {
        adr_kelompok P = firstKelompok(LKp);
        adr_kelompok prevP;
        if(nextKelompok(P) == NULL) {
            prevP = NULL;
        } else {
            prevP = P;
            while (nextKelompok(nextKelompok(prevP)) != NULL) {
                prevP = nextKelompok(prevP);
            }
            P = nextKelompok(prevP);
        }

        adr_anggota A = firstAnggota(dataAnggota(P));

        if (A == NULL) {
            cout << "Anggota Tidak Ada" << endl;
        } else {
            while (firstAnggota(dataAnggota(P)) != NULL) {
                deleteAnggota(dataAnggota(P));
            }
        }

        if(prevP == NULL) {
            adr_kelompok tempP = P;
            firstKelompok(LKp) = NULL;
        } else {
            adr_kelompok tempP = P;
            nextKelompok(prevP) = NULL;
        }
        cout << "Kelompok terakhir berhasil dihapus" << endl;
    }
    cout << endl;
}

adr_kelompok searchKelompok(listKelompok LKp, int ID_kelompok) {
    /*
    { Mengembalikan nilai address kelompok dari
    data kelompok berdasarkan ID kelompok
    }
    */
    if(firstKelompok(LKp) == NULL) {
        return NULL;
    } else {
        adr_kelompok P = firstKelompok(LKp);
        while(P != NULL && infoKelompok(P).ID_kelompok != ID_kelompok) {
            P = nextKelompok(P);
        }
        return P;
    }
}

void insertLastAnggota(listAnggota &LA, adr_anggota A) {
    /*
    { I.S.: listAnggota LA mungkin kosong, adr_anggota A menunjuk ke
    elemen list yang akan ditambah
    F.S.: Data anggota baru akan dimasukkan ke dalam list anggota
    dan menjadi elemen terakhir
    }
    */
    if (firstAnggota(LA) == NULL) {
        firstAnggota(LA) = A;
        lastAnggota(LA) = A;
    } else {
        adr_anggota Q = lastAnggota(LA);
        nextAnggota(Q) = A;
        prevAnggota(A) = Q;
        lastAnggota(LA) = A;
    }
}

void connectKelompokToAnggota(listKelompok &LKp, int ID_kelompok, adr_anggota A) {
    /*
    { I.S.: listKelompok LKp dan listAnggota LA mungkin kosong
    F.S.: Data kelompok dengan data anggota terhubung berdasarkan
    listKelompok dengan ID_kelompok
    }
    */

    adr_kelompok P = searchKelompok(LKp, ID_kelompok);
    if (P != NULL) {
        insertLastAnggota(dataAnggota(P), A);
    } else {
        cout << "Kelompok tidak ditemukan." << endl;
    }
}

void showAllKelompokAndAnggota(listKelompok LKp) {
    /*
    { I.S.: listKelompok LKp mungkin kosong
    F.S.: Menampilkan semua data kelompok dan data anggota
    }
    */
    adr_kelompok P = firstKelompok(LKp);
    int countKelompok = 1;
    if(P == NULL) {
        cout << "Kelompok Kosong" << endl;
        cout << endl;
    }
    cout << endl;
    while (P != NULL) {
        string kelompokKe = "Data kelompok ke-" + to_string(countKelompok);
        headerMenu(kelompokKe, "");
        cout << "ID Kelompok\t\t: " << infoKelompok(P).ID_kelompok << endl;
        cout << "Nama Kelompok\t\t: " << infoKelompok(P).nama_kelompok << endl;
        cout << "Kategori Kelompok\t: " << infoKelompok(P).kategori_kelompok << endl;
        cout << "Tanggal Mulai Kelompok\t: " << infoKelompok(P).tanggal_mulai_kelompok << endl;
        cout << "Tanggal Selesai Kelompok: " << infoKelompok(P).tanggal_selesai_kelompok << endl;
        cout << endl;
        cout << "Data Anggota:" << endl;
        countKelompok++;

        adr_anggota A = firstAnggota(dataAnggota(P));
        if (A == NULL) {
            cout << "Tidak ada anggota untuk kelompok ini." << endl;
        } else {
            int i = 1;
            vector<vector<string>> t;
            t.push_back({"NO","ID","NAMA", "TANGGAL LAHIR", "ALAMAT", "NO TELP", "EMAIL"});
            while (A != NULL) {
                t.push_back({to_string(i), to_string(infoAnggota(A).ID_anggota), infoAnggota(A).nama_anggota, infoAnggota(A).tanggal_lahir, infoAnggota(A).alamat_anggota, infoAnggota(A).no_telp_anggota, infoAnggota(A).email_anggota});
                i++;
                A = nextAnggota(A);
            }

            table(t);

        }
        P = nextKelompok(P);

        cout << "=================================================" << endl;
    }

}

adr_anggota searchAnggota(listAnggota LA, int ID_anggota) {
    /*
    { I.S.: listAnggota LA dan listKelompok LKp mungkin kosong
    F.S.: Data anggota yang ditemukan berdasarkan listKelompok
    dan ID_kelompok akan ditampilkan
    }
    */
    if(firstAnggota(LA) == NULL) {
        return NULL;
    } else {
        adr_anggota A = firstAnggota(LA);
        while(A != NULL && infoAnggota(A).ID_anggota != ID_anggota) {
            A = nextAnggota(A);
        }
        return A;
    }
}

adr_kelompok searchAnggotaInAllKelompok(listKelompok LKp, int ID_anggota) {
    if(firstKelompok(LKp) == NULL) {
        return NULL;
    } else {
        adr_kelompok P = firstKelompok(LKp);
        while(P != NULL) {
            adr_anggota A = searchAnggota(dataAnggota(P), ID_anggota);
            if(A != NULL) {
                return P;
            }
            P = nextKelompok(P);
        }
        return NULL;
    }
}

void deleteAnggota(listAnggota &LA) {
    /*
    { I.S.: listKelompok LKp mungkin kosong
    F.S.: Data anggota pertama terhapus pada data kelompok tertentu
    }
    */
    if (firstAnggota(LA) == NULL) {
        cout << "Anggota Tidak Ada" << endl;
    } else if(firstAnggota(LA) == lastAnggota(LA)) {
        adr_anggota tempA = firstAnggota(LA);
        firstAnggota(LA) = NULL;
        lastAnggota(LA) = NULL;
    } else {
        adr_anggota tempA = firstAnggota(LA);
        firstAnggota(LA) = nextAnggota(firstAnggota(LA));
        prevAnggota(firstAnggota(LA)) = NULL;
        nextAnggota(tempA) = NULL;
    }
}

int countAnggotaInKelompok(listKelompok LKp, int ID_kelompok) {
    /*
    { Mengembalikan nilai jumlah data anggota
    dari data kelompok tertentu }
    */
    int jumlahAnggota = 0;
    adr_kelompok P = searchKelompok(LKp, ID_kelompok);
    if (P == NULL) {
        cout << "Kelompok dengan ID " << ID_kelompok << " tidak ditemukan." << endl;
        return -1;
    }
    adr_anggota A = firstAnggota(dataAnggota(P));
    while (A != NULL) {
        jumlahAnggota++;
        A = nextAnggota(A);
    }
    return jumlahAnggota;
}
