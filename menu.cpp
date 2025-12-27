#include "tubes.h"

void headerMenu(const string title, const string subtitle = "") {
    int width = 49;
    cout << string(width, '=') << endl;

    int titlePadding = (width - title.length() - 4) / 2;
    cout << "**" << string(titlePadding, ' ') << title << string(titlePadding + (width - title.length() - 4) % 2, ' ') << "**" << endl;

    if (!subtitle.empty()) {
        int subtitlePadding = (width - subtitle.length() - 4) / 2;
        cout << "**" << string(subtitlePadding, ' ') << subtitle << string(subtitlePadding + (width - subtitle.length() - 4) % 2, ' ') << "**" << endl;
    }

    cout << string(width, '=') << endl;
}

void menu(listKelompok &LKp) {
    int choice;
    do {
        clearScreen();
        headerMenu("Menu Utama");
        list_menu_utama();
        choice = intInput("Pilih: ");
        cout << endl;

        if (choice == 1) {
            menu_input_kelompok(LKp);
        }
        else if (choice == 2) {
            clearScreen();
            headerMenu("List data kelompok");
            showAllKelompok(LKp);
            pause();
        }
        else if (choice == 3) {
            // int id; // Variabel ini tidak dipakai di blok ini, saya komen agar rapi
            deleteKelompokDanAnggota(LKp);
            pause();
        }
        else if (choice == 4) {
            clearScreen();
            headerMenu("Cari Kelompok");
            cout << endl;
            int id;
            id = intInput("Masukkan ID Kelompok yang dicari: ");
            adr_kelompok P = searchKelompok(LKp, id);
            if (P != NULL) {
                cout << "Kelompok ditemukan.\n" << endl;
                cout << "ID Kelompok\t\t: " << infoKelompok(P).ID_kelompok << endl;
                cout << "Nama Kelompok\t\t: " << infoKelompok(P).nama_kelompok << endl;
                cout << "Kategori Kelompok\t: " << infoKelompok(P).kategori_kelompok << endl;
                cout << "Tanggal Mulai Kelompok\t: " << infoKelompok(P).tanggal_mulai_kelompok << endl;
                cout << "Tanggal Selesai Kelompok: " << infoKelompok(P).tanggal_selesai_kelompok << endl;
            } else {
                cout << "Kelompok tidak ditemukan." << endl;
            }
            cout << endl;
            pause();
        }
        else if (choice == 5) {
            menu_input_anggota(LKp);
        }
        else if (choice == 6) {
            clearScreen();
            headerMenu("Data kelompok dan anggotanya");
            showAllKelompokAndAnggota(LKp);
            pause();
        }
        else if (choice == 7) {
            clearScreen();
            headerMenu("Hitung Jumlah Anggota di Kelompok");
            cout << endl;
            int id;
            id = intInput("Masukkan ID Kelompok: ");
            cout << endl;

            adr_kelompok p = searchKelompok(LKp, id);
            if(p == NULL) {
                cout << "Kelompok dengan id: " << id << " tidak ditemukan." << endl;
            } else {
                int totalAnggota = countAnggotaInKelompok(LKp, id);
                if(totalAnggota != -1) {
                    cout << "Total Anggota di kelompok dengan ID " << id << " adalah " << totalAnggota << endl;
                }
            }
            cout << endl;

            pause();
        }
        else if (choice == 8) {
            clearScreen();
            headerMenu("Cari Anggota di Kelompok Tertentu");
            cout << endl;

            int ID_anggota, ID_kelompok;
            ID_kelompok = intInput("Masukkan ID Kelompok: ");
            adr_kelompok P = searchKelompok(LKp, ID_kelompok);

            if(P != NULL) {
                ID_anggota = intInput("Masukkan ID Anggota: ");
                adr_anggota K = searchAnggota(dataAnggota(P), ID_anggota);
                if(K == NULL) {
                    cout << "Data anggota dengan id: " << ID_anggota << " pada kelompok ini tidak ditemukan" << endl;
                } else {
                    cout << endl;
                    cout << "Data anggota ditemukan " << endl;
                    cout << endl;
                    cout << "ID Anggota\t\t: " << infoAnggota(K).ID_anggota << endl;
                    cout << "Nama Anggota\t\t: " << infoAnggota(K).nama_anggota << endl;
                    cout << "Tanggal Lahir Anggota\t: " << infoAnggota(K).tanggal_lahir << endl;
                    cout << "Alamat Anggota\t\t: " << infoAnggota(K).alamat_anggota << endl;
                    cout << "No Telp Anggota\t\t: " << infoAnggota(K).no_telp_anggota << endl;
                    cout << "Email Anggota\t\t: " << infoAnggota(K).email_anggota << endl;
                }
            } else {
                cout << "Kelompok dengan id: " << ID_kelompok << " tidak ditemukan." << endl;
            }
            cout << endl;

            pause();
        }
        else if (choice == 9) {
            clearScreen();
            headerMenu("Hapus Anggota Pertama di Kelompok");
            cout << endl;

            int ID_anggota, ID_kelompok;
            ID_kelompok = intInput("Masukkan ID Kelompok: ");
            adr_kelompok P = searchKelompok(LKp, ID_kelompok);

            if (P == NULL) {
                cout << "Kelompok tidak ditemukan" << endl;
            } else {
                cout << endl;
                if(firstAnggota(dataAnggota(P)) != NULL) {
                    cout << "Anggota pertama pada kelompok (ID: " << ID_kelompok << ") berhasil di hapus" << endl;
                }
                deleteAnggota(dataAnggota(P));
            }
            cout << endl;

            pause();
        }
        else if (choice == 10) {
            inisialisasi_data_perusahaan(LKp);
            cout << "Data berhasil diinisialisasi" << endl;
            pause();
        }
        else if (choice == 11) {
            clearScreen();
            headerMenu("Jumlah Anggota Tiap Kelompok");
            showKelompokWithMemberCount(LKp);
            pause();
        }
        else if (choice == 12) {
            clearScreen();
            headerMenu("Ranking Kelompok (Anggota Terbanyak)");
            showKelompokSortedByAnggota(LKp);
            pause();
        }
        else if (choice == 13) {
            clearScreen();
            headerMenu("Statistik Rata-rata");
            calculateAverageAnggota(LKp);
            pause();
        }
    } while (choice != 0);

}

void menu_welcome() {
    cout << " ===================================================" << endl;
    cout << "*                    Selamat Datang                *" << endl;
    cout << "*       Di Aplikasi Manajemen Kelompok & Anggota   *" << endl;
    cout << "*                     By Kelompok 1                *" << endl;
    cout << "*   Mochammad Kresna Satriawansyah - 103012430030  *" << endl;
    cout << "*        Muhammad Husni Naufal K - 103012400034    *" << endl;
    cout << " ===================================================" << endl;

    cout << endl;

    cout << "Masukkan (Ya) untuk melanjutkan" << endl;
}

void list_menu_utama() {
    cout << "=================================================" << endl;
    cout << "1. Tambah Kelompok" << endl;
    cout << "2. Tampilkan Semua Kelompok" << endl;
    cout << "3. Hapus Kelompok Terakhir dan Anggotanya" << endl;
    cout << "4. Cari Kelompok" << endl;
    cout << "5. Tambah Anggota ke Kelompok" << endl;
    cout << "6. Tampilkan Semua Kelompok dan Anggotanya" << endl;
    cout << "7. Hitung Jumlah Anggota di Kelompok" << endl;
    cout << "8. Cari Anggota di Kelompok Tertentu" << endl;
    cout << "9. Hapus Anggota Pertama di Kelompok" << endl;
    cout << "10. Inisialisasi data" << endl;
    cout << "11. Tampilkan Jumlah Anggota Tiap Kelompok" << endl;
    cout << "12. Tampilkan Kelompok Terurut (Terbanyak -> Sedikit)" << endl;
    cout << "13. Tampilkan Rata-rata Anggota Kelompok" << endl;
    cout << "0. Keluar" << endl;
    cout << "=================================================" << endl;

}

void menu_input_kelompok(listKelompok &LKp) {
    clearScreen();
    headerMenu("Tambah data kelompok");
    cout << endl;

    infotype_kelompok data;
    int id_kelompok;

    id_kelompok = intInput("ID Kelompok\t: ");
    adr_kelompok p = searchKelompok(LKp, id_kelompok);
    if(p != NULL) {
        cout << "Kelompok dengan id: " << id_kelompok << " sudah ada." << endl;
    } else {
        data.ID_kelompok = id_kelompok;
        cin.ignore();
        cout << "Nama Kelompok\t: ";
        getline(cin, data.nama_kelompok);
        cout << "Kategori Kelompok\t: ";
        getline(cin, data.kategori_kelompok);
        cout << "Tanggal Mulai\t: ";
        getline(cin, data.tanggal_mulai_kelompok);
        cout << "Tanggal Selesai\t: ";
        getline(cin, data.tanggal_selesai_kelompok);
        insertFirstKelompok(LKp, allocateKelompok(data));
        cout << endl;
        cout << "Data berhasil ditambahkan\n" << endl;
    }

    pause();
}

void menu_input_anggota(listKelompok &LKp) {
    clearScreen();
    headerMenu("Tambah data anggota");
    cout << endl;

    int id_kelompok;
    id_kelompok = intInput("Masukkan ID Kelompok: ");
    adr_kelompok p = searchKelompok(LKp, id_kelompok);

    if(p == NULL) {
        cout << "Kelompok dengan id: " << id_kelompok << " tidak ditemukan." << endl;
        pause();
    } else {
        infotype_anggota data;
        int id_anggota;
        id_anggota = intInput("ID Anggota\t: ");
        adr_anggota k = searchAnggota(dataAnggota(p), id_anggota);
        if(k != NULL) {
            cout << "Anggota dengan id: " << id_anggota << " sudah ada." << endl;
        } else {
            adr_kelompok kelompokAnggota = searchAnggotaInAllKelompok(LKp, id_anggota);
            if(kelompokAnggota != NULL) {
                cout << "Data anggota ditemukan pada kelompok dengan id: " << infoKelompok(kelompokAnggota).ID_kelompok << endl;
                k = searchAnggota(dataAnggota(kelompokAnggota), id_anggota);
                cout << endl;
                cout << "ID Anggota\t\t: " << infoAnggota(k).ID_anggota << endl;
                cout << "Nama Anggota\t\t: " << infoAnggota(k).nama_anggota << endl;
                cout << "Tanggal Lahir Anggota\t: " << infoAnggota(k).tanggal_lahir << endl;
                cout << "Alamat Anggota\t\t: " << infoAnggota(k).alamat_anggota << endl;
                cout << "No Telp Anggota\t: " << infoAnggota(k).no_telp_anggota << endl;
                cout << "Email Anggota\t\t: " << infoAnggota(k).email_anggota << endl;
                cout << endl;
                cout << "Apakah anda ingin menambahkan anggota ini ke dalam kelompok dengan id: " << id_kelompok << " ?" << endl;

                string input;
                cout << "Masukkan (Ya) untuk melanjutkan" << endl;
                cin >> input;
                if(input == "Ya" || input == "YA" || input == "ya") {
                    infotype_anggota dataAnggota = infoAnggota(k);
                    connectKelompokToAnggota(LKp, id_kelompok, allocateAnggota(dataAnggota));
                    cout << "Data berhasil ditambahkan" << endl;
                }
            } else {
                data.ID_anggota = id_anggota;
                cin.ignore();
                cout << "Nama Anggota\t: ";
                getline(cin, data.nama_anggota);
                cout << "Tanggal Lahir\t: ";
                getline(cin, data.tanggal_lahir);
                cout << "Alamat\t\t: ";
                getline(cin, data.alamat_anggota);
                cout << "No. Telp\t: ";
                getline(cin, data.no_telp_anggota);
                cout << "Email\t\t: ";
                getline(cin, data.email_anggota);
                connectKelompokToAnggota(LKp, id_kelompok, allocateAnggota(data));
                cout << endl;
                cout << "Data berhasil ditambahkan\n" << endl;
            }
        }

        pause();
    }
}

