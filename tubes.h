#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

#ifdef _WIN32
#include <bits/stdc++.h>
#endif

#define nextAnggota(P) P->nextAnggota
#define prevAnggota(P) P->prevAnggota
#define firstAnggota(L) L.first
#define lastAnggota(L) L.last
#define infoAnggota(P) P->infoAnggota
#define nextKelompok(P) P->nextKelompok
#define infoKelompok(P) P->infoKelompok
#define firstKelompok(L) L.first
#define dataAnggota(P) P->dataAnggota

struct anggota {
    int ID_anggota;
    string nama_anggota;
    string tanggal_lahir;
    string alamat_anggota;
    string no_telp_anggota;
    string email_anggota;
};

struct kelompok {
    int ID_kelompok;
    string nama_kelompok;
    string kategori_kelompok;
    string tanggal_mulai_kelompok;
    string tanggal_selesai_kelompok;
};

typedef kelompok infotype_kelompok;
typedef anggota infotype_anggota;
typedef struct elmKelompok *adr_kelompok;
typedef struct elmAnggota *adr_anggota;

struct elmAnggota {
    infotype_anggota infoAnggota;
    adr_anggota prevAnggota;
    adr_anggota nextAnggota;
};

struct listAnggota {
    adr_anggota first;
    adr_anggota last;
};

struct elmKelompok {
    infotype_kelompok infoKelompok;
    adr_kelompok nextKelompok;
    listAnggota dataAnggota; // Relasi Kelompok memiliki list Anggota
};

struct listKelompok {
    adr_kelompok first;
};

void createListKelompok(listKelompok &LKp); // LKp = List Kelompok
void createListAnggota(listAnggota &LA);    // LA = List Anggota
adr_kelompok allocateKelompok(infotype_kelompok dataKelompok);
adr_anggota allocateAnggota(infotype_anggota dataAnggota);

void insertFirstKelompok(listKelompok &LKp, adr_kelompok P);
void showAllKelompok(listKelompok LKp);
void deleteKelompokDanAnggota(listKelompok &LKp);
adr_kelompok searchKelompok(listKelompok LKp, int ID_kelompok);
void insertLastAnggota(listAnggota &LA, adr_anggota A);
void connectKelompokToAnggota(listKelompok &LKp, int ID_kelompok, adr_anggota A);
void showAllKelompokAndAnggota(listKelompok LKp);
adr_anggota searchAnggota(listAnggota LA, int ID_anggota);
void deleteAnggota(listAnggota &LA);
int countAnggotaInKelompok(listKelompok LKp, int ID_kelompok);
adr_kelompok searchAnggotaInAllKelompok(listKelompok LKp, int ID_anggota);

// Utils
void clearScreen();
void pause();
int intInput(string prompt);
void tableHorizontalSparator(vector<int> colWidth);
void tableRow(vector<int> colWidth, vector<string> data);
vector<int> colWidth(vector<vector<string>> &t);
void table(vector<vector<string>> &t);
void inisialisasi_data_perusahaan(listKelompok &LKp);

// Menu
void menu_welcome();
void menu(listKelompok &LKp);
void list_menu_utama();
void headerMenu(string title, string subtitle);
void menu_input_kelompok(listKelompok &LKp);
void menu_input_anggota(listKelompok &LKp);

#endif // TUBES_H_INCLUDED
