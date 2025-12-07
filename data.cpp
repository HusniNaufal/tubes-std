#include "tubes.h"

void inisialisasi_data_perusahaan(listKelompok &LKp){
    adr_kelompok kelompok;
    adr_kelompok P;

    // Dummy data kelompok
    infotype_kelompok dataKelompok;
    dataKelompok.ID_kelompok = 1;
    dataKelompok.nama_kelompok = "Website Development";
    dataKelompok.kategori_kelompok = "Teknologi";
    dataKelompok.tanggal_mulai_kelompok = "10-10-2023";
    dataKelompok.tanggal_selesai_kelompok = "11-11-2023";
    P = searchKelompok(LKp, dataKelompok.ID_kelompok);
    if(P == NULL) {
        kelompok = allocateKelompok(dataKelompok);
        insertFirstKelompok(LKp, kelompok);
    }

    dataKelompok.ID_kelompok = 2;
    dataKelompok.nama_kelompok = "Games Development";
    dataKelompok.kategori_kelompok = "Teknologi";
    dataKelompok.tanggal_mulai_kelompok = "04-10-2022";
    dataKelompok.tanggal_selesai_kelompok = "11-01-2023";
    P = searchKelompok(LKp, dataKelompok.ID_kelompok);
    if(P == NULL) {
        kelompok = allocateKelompok(dataKelompok);
        insertFirstKelompok(LKp, kelompok);
    }

    dataKelompok.ID_kelompok = 3;
    dataKelompok.nama_kelompok = "Data Research";
    dataKelompok.kategori_kelompok = "Visualisation";
    dataKelompok.tanggal_mulai_kelompok = "09-03-2024";
    dataKelompok.tanggal_selesai_kelompok = "04-05-2024";
    P = searchKelompok(LKp, dataKelompok.ID_kelompok);
    if(P == NULL) {
        kelompok = allocateKelompok(dataKelompok);
        insertFirstKelompok(LKp, kelompok);
    }


    // Dummy data anggota
    infotype_anggota dataAnggota;
    dataAnggota.ID_anggota = 1;
    dataAnggota.nama_anggota = "Billy";
    dataAnggota.tanggal_lahir = "10-01-1990";
    dataAnggota.alamat_anggota = "Jl.Chaonima";
    dataAnggota.no_telp_anggota = "081234567890";
    dataAnggota.email_anggota = "billy@anggota.com";
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 3, allocateAnggota(dataAnggota));
    }

    dataAnggota.ID_anggota = 2;
    dataAnggota.nama_anggota = "Azziz";
    dataAnggota.tanggal_lahir = "15-02-1985";
    dataAnggota.alamat_anggota = "Jl.Cimaung_Banjir" ;
    dataAnggota.no_telp_anggota = "082345678901";
    dataAnggota.email_anggota = "azziz@anggota.com";
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 1, allocateAnggota(dataAnggota));
    }

    dataAnggota.ID_anggota = 3;
    dataAnggota.nama_anggota = "Calwa";
    dataAnggota.tanggal_lahir = "20-03-1995";
    dataAnggota.alamat_anggota = "Jl.MotionIme";
    dataAnggota.no_telp_anggota = "083456789012";
    dataAnggota.email_anggota = "calwa@anggota.com";
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 1, allocateAnggota(dataAnggota));
    }

    dataAnggota.ID_anggota = 4;
    dataAnggota.nama_anggota = "Falah";
    dataAnggota.tanggal_lahir = "25-04-1992";
    dataAnggota.alamat_anggota = "Jl.Bogor_No_9";
    dataAnggota.no_telp_anggota = "084567890123";
    dataAnggota.email_anggota = "falah@anggota.com" ;
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 2, allocateAnggota(dataAnggota));
    }

    dataAnggota.ID_anggota = 5;
    dataAnggota.nama_anggota = "Hilmi" ;
    dataAnggota.tanggal_lahir = "30-05-1988" ;
    dataAnggota.alamat_anggota = "Jl.Garut" ;
    dataAnggota.no_telp_anggota = "085678901234" ;
    dataAnggota.email_anggota = "hilmi@anggota.com" ;
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 3, allocateAnggota(dataAnggota));
    }

    dataAnggota.ID_anggota = 6;
    dataAnggota.nama_anggota = "Irham" ;
    dataAnggota.tanggal_lahir = "30-05-1988";
    dataAnggota.alamat_anggota = "Jl.Cisumdawu" ;
    dataAnggota.no_telp_anggota = "085678901234" ;
    dataAnggota.email_anggota = "irham@anggota.com" ;
    P = searchAnggotaInAllKelompok(LKp, dataAnggota.ID_anggota);
    if(P == NULL) {
        connectKelompokToAnggota(LKp, 3, allocateAnggota(dataAnggota));
    }
}
