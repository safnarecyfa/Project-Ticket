#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Data {
    string NIP;
    string pass;
};

struct tiket {
    string nama;
    string tanggal;
    string hari;
    string jenis;
    int jmlDewasa;
    int jmlAnakKecil = 0;
    int jmlBayi = 0;
    int jmlTiketBiasa;
    int jmlTiketTerusan;
    int hargab;
    int hargat;
    int total;
};

tiket daftarTiket[100];
int jumlahTiket = 0;

bool LogIn = false;

bool login(int log);
void menuUtama();
void pesantiket();

int main() {
        LogIn = login(3);

    if (LogIn) {
        system("cls");
        menuUtama();
    } else {
        cout << "bye bye";
    }
    
    return 0;
}

bool login(int log) {
    if (log == 0) {
        return false;
    }
    
    Data main;

    string NIPbenar[] = {"1", "2", "3"};
        int jumlahNIP = sizeof(NIPbenar) / sizeof(NIPbenar[0]);
    string passbenar[] = {"1", "2", "3"};
        int jumlahpass = sizeof(passbenar) / sizeof(passbenar[0]);

    bool NIP_valid = false;
    bool pass_valid = false;

    cout << "Masukkan NIP      : ";
        getline(cin, main.NIP);
    cout << "Masukkan Password : ";
        getline(cin, main.pass);

        NIP_valid = false;
        pass_valid = false;

    for (int i = 0; i < jumlahNIP; i++) {
        if (main.NIP == NIPbenar[i]) {
            NIP_valid = true;
            break;
        }
    }

    for (int j = 0; j < jumlahpass; j++) {
        if (main.pass == passbenar[j]) {
            pass_valid = true;
            break;
        }
    }

    if (NIP_valid && pass_valid) {
        system("cls");
        cout << "Selamat Datang di Wahhoo Admin !" << endl;
        getch();
        return true;
    } else {
            cout << "Ayo coba lagi! \n Sisa percobaan: " << log-1 << endl;
            system("pause");
            system("cls");
            return login(log-1);
        }
}

void menuUtama(){
    int pilih;
    system("cls");
    cout << "==== DATA PEMESANAN TIKET ====" << endl;
    cout << "1. Pemesanan Tiket" << endl;
    cout << "2. Keluar" << endl << endl;
    cout << "Masukkan pilihan : " ; cin >> pilih;

    if (pilih == 1) {
        pesantiket();
    } 
    else if (pilih == 2) {
        cout << "Terima kasih telah menggunakan program ini!" << endl;
        system ("pause");
        return; 
    } 
    else {
        cout << "Pilihan tidak valid! Coba lagi." << endl;
        cin.ignore();
        cin.get(); 
    }

}

void pesantiket(){    
    system("cls");
    tiket pesan;
    char adaAnak;

    if (jumlahTiket >= 100) {
        cout << "Maaf, kapasitas tiket penuh!" << endl;
        system("pause");
        menuUtama();
        return;
    }

    cout << ">>>>>>>>>>>  DATA PEMESANAN TIKET  <<<<<<<<<<<" << endl << endl;
    cout << "Masukkan Nama Pemesan         : ";
    cin.ignore();
    getline(cin, pesan.nama);
    
    cout << "Tanggal Pesan (dd/mm/yyyy)    : ";
    getline(cin, pesan.tanggal);
    
    cout << "Hari Pemesanan (Senin-Minggu) : ";
    getline(cin, pesan.hari);
    cout << endl;
    
    cout << "Jumlah Pelanggan (Dewasa)     : ";
    cin >> pesan.jmlDewasa;
    cin.ignore();
    
    cout << "Apakah ada anak kecil dala rombongan? (y/n) : ";
    cin >> adaAnak;
    cin.ignore();
    
    if (adaAnak == 'y' || adaAnak == 'Y') {
        cout << "     Masukkan Jumlah Anak Usia 2 - 10 Tahun     : ";
        cin >> pesan.jmlAnakKecil;
        cin.ignore();
        cout << "     Masukkan Jumlah Anak Usia di Bawah 2 Tahun : ";
        cin >> pesan.jmlBayi;
        cin.ignore();
        cout << endl;
    }

    cout << "--- Daftar Pesanan Tiket ---" << endl;
    cout << "  Tiket Biasa   : ";
    cin >> pesan.jmlTiketBiasa;
    cin.ignore();
    cout << "  Tiket Terusan : ";
    cin >> pesan.jmlTiketTerusan; cout << endl;

    if (pesan.hari == "Sabtu" || pesan.hari == "Minggu") {
        pesan.hargab = 55000;
        pesan.hargat = 70000;
    } else {
        pesan.hargab = 45000;
        pesan.hargat = 60000;
    }

    //total harga
    pesan.total = (pesan.jmlTiketBiasa * pesan.hargab) + (pesan.jmlTiketTerusan * pesan.hargat);
    //total harga anak kecil
    pesan.total += (pesan.jmlAnakKecil * (pesan.hargab / 2));

    //diskon
    int totaltiket = pesan.jmlDewasa + pesan.jmlAnakKecil + pesan.jmlBayi;
    if (totaltiket > 10) {
        pesan.total -= pesan.total * 0.25;
    }

    cout << "============= RINCIAN PEMESANAN ============" << endl;
    cout << "Total Tiket Biasa   : " << pesan.jmlTiketBiasa << " x " << pesan.hargab << " = Rp " << pesan.jmlTiketBiasa * pesan.hargab << endl;
    cout << "Total Tiket Terusan : " << pesan.jmlTiketTerusan << " x " << pesan.hargat << " = Rp " << pesan.jmlTiketTerusan * pesan.hargat << endl;
    cout << "Diskon Anak (2-10)  : " << pesan.jmlAnakKecil << " x " << pesan.hargab / 2 << " = Rp " << pesan.jmlAnakKecil * (pesan.hargab / 2) << endl;

    if (totaltiket > 10) {
        int potongan = pesan.total * 0.25;
        cout << "Diskon Jumlah (>10) : 25% dari Rp " << pesan.total << " = Rp " << potongan << endl;
        pesan.total -= potongan;
    } else {
        cout << "Diskon Jumlah (>10) : - " << endl;
    }

    cout << "Total Harga         : Rp " << pesan.total << endl << endl;

    system("pause");
    menuUtama();
}