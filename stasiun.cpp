#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//datauser
typedef struct {
    string nama, username, password;
} datauser;

string akun[100][3];
int banyakuser = 0;
const int maks = 100;

//jadwal kereta
typedef struct {
    string nama; int kode;
    string tujuan;
    string jberangkat;
    string jtiba;
    string jalurperon;
} jadwal;

typedef struct {
    int tanggal;
    int bulan;
    int tahun;
} waktu;

typedef struct {
    string tujuan, kota;
} stujuan;

void regist();
void daftar();
void login();
void menu_utama(); 
void jadwalkereta();
void pesantiket();
void tujuan ();

int main() {
    regist();
    return 0;
}

void regist(){
    int pilihan;
    while (true) {
        system("cls");
        cout << "===== PROGRAM LOGIN & REGISTER =====" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Register" << endl;
        cout << "[3] Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                login();
                break;
            case 2:
                daftar();
                break;
            case 3:
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                cin.get();
        }
    }
}

// Fungsi untuk mendaftar akun baru
void daftar() {
    system("cls");
    if (banyakuser >= maks) {
        cout << "Maaf, kapasitas pengguna penuh!" << endl;
        return;
    }
    
    datauser ds;
    
    cout << "===== REGISTER AKUN =====" << endl;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, ds.nama);
    cout << "Masukkan Username: ";
    getline(cin, ds.username);
    cout << "Masukkan Password: ";
    getline(cin, ds.password);
    
    // Periksa apakah username sudah ada
    for (int i = 0; i < banyakuser; i++) {
        if (akun[i][1] == ds.username) {
            cout << "Username sudah digunakan, silahkan coba lagi!" << endl;
            cin.get();
            return;
        }
    }
    
    // Simpan data ke array
    akun[banyakuser][0] = ds.nama;
    akun[banyakuser][1] = ds.username;
    akun[banyakuser][2] = ds.password;
    banyakuser++;
    
    cout << "Akun berhasil didaftarkan!" << endl;
    cin.get();
}

// Fungsi untuk login
void login() {
    system("cls");
    string username, password;
    int percobaan = 0;
    
    cout << "===== LOGIN =====" << endl;
    
    while (percobaan < 3) {
        cin.ignore();
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);
        
        bool login = false;
        for (int i = 0; i < banyakuser; i++) {
            if (akun[i][1] == username && akun[i][2] == password) {
                cout << "Login berhasil! Selamat datang, " << akun[i][0] << "!" << endl;
                cin.get();
                menu_utama();
                return;
            }
        }
        
        if (banyakuser == 0) {
            cout << "Belum ada akun yang terdaftar. Silakan daftar terlebih dahulu." << endl;
            cin.get();
            return;
        }

        // Jika username dan password tidak ditemukan
        if (!login) {
            cout << "Username atau Password salah, atau Anda belum register!" << endl;
            percobaan++;
            cout << "Kesempatan Login = " << (3 - percobaan) << endl;

            if (percobaan >= 3) {
                cout << "Anda ingin kembali ke menu awal? (y/n): ";
                char pilihan;
                cin >> pilihan;
                if (pilihan == 'y' || pilihan == 'Y') {
                    return; // Kembali ke menu awal
                } else {
                    cout << "Terima kasih telah menggunakan program ini ! " << endl;
                    return;
                }
            }
        }
    }
}

void menu_utama(){
    system("cls");
    int pilih;
    cout << endl;
    cout << "============================================================" << endl;
    cout << "|    SELAMAT DATANG DI STASIUN TEMPOE DOELOE YOGYAKARTA    |" << endl;
    cout << "============================================================" << endl << endl;
    
    cout << "                    Apa yang Anda cari ?                    " << endl;
    cout << "       _______ 1 _______              ______ 2 ______       " << endl;
    cout << "       | JADWAL KERETA |              | PESAN TIKET |       " << endl;
    cout << "       `````````````````              ```````````````       " << endl << endl;
    
    cout << "Masukkan pilihan (1/2) : " ; cin >> pilih;

    if (pilih == 1) {
        jadwalkereta();
        menu_utama(); 
    } 
    else if (pilih == 2) {
        pesantiket();  
        menu_utama(); 
    } 
    else if (pilih == 3) {
        cout << "Terima kasih telah menggunakan program ini!" << endl;
        system ("pause");
        regist();
        return; 
    } 
    else {
        cout << "Pilihan tidak valid! Coba lagi." << endl;
        cin.ignore();
        cin.get();
        menu_utama(); 
    }
}
    
void jadwalkereta(){
    system("cls");
    jadwal kereta[6];
    int jumlahjadwal = 0;

    jadwal datakereta[6] = {
        {"Argo Ngawi", 257, "Argopuro", "Today, 08:15", "Today, 16:06", "1"},
        {"Taksaka", 160, "Pasar Senen", "Today, 21:15", "Tomorrow, 04:15", "2"},
        {"Gajahwong", 102, "Bogor", "Today, 22:07", "Tomorrow, 05:15", "3"},
        {"Bengawan", 155, "Sidoarjo", "Today, 07:37", "Today, 15.32", "4"},
        {"Gaya Baru Malam Selatan", 169, "Kiaracondong", "Today, 11.52", "Today, 17.20", "5"},
        {"Jaka Tingkir", 203, "Gambir", "Today, 09:37", "Today, 18.28", "6"},
        };

    for (int i = 0; i < 6; i++)
    {
        kereta[jumlahjadwal++] = datakereta[i];
    }
    
    cout << "                                     >>>>>  JADWAL KERETA  <<<<" << endl << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "|  NO |       NAMA KERETA       |  KODE |    TUJUAN    |  JAM BERANGKAT |     JAM TIBA    | JALUR PERON |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < jumlahjadwal; i++) {
        cout << "| " << setw(2) << i + 1 << ". | " 
             << setw(23) << setfill(' ') << setiosflags(ios::left) << kereta[i].nama << " | " 
             << setw(5) << setfill(' ') << setiosflags(ios::left) << kereta[i].kode << " | " 
             << setw(12) << setfill(' ') << setiosflags(ios::left) << kereta[i].tujuan << " | " 
             << setw(14) << setfill(' ') << setiosflags(ios::left) << kereta[i].jberangkat << " | " 
             << setw(15) << setfill(' ') << setiosflags(ios::left) << kereta[i].jtiba << " | " 
             << setw(11) << setfill(' ') << setiosflags(ios::left) << kereta[i].jalurperon << " |" << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl << endl;

    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get(); 
}
    
void pesantiket(){
    system ("cls");
    waktu pesan;
    cout << "Silahkan lengkapi data pemesanan !" << endl;
    cout << "Tanggal : " ; cin >> pesan.tanggal;
    cout << "Bulan   : " ; cin >> pesan.bulan;
    cout << "Tahun   : " ; cin >> pesan.tahun;
    cout << endl;
    
    if (pesan.tanggal < 1 || pesan.tanggal > 31 || pesan.bulan < 1 || pesan.bulan > 12 || pesan.tahun < 2024 || pesan.tahun > 2026){
        cout << "Tanggal tidak valid, mohon coba lagi" << endl;
        system("pause");
        pesantiket();
        return;  
    }


    tujuan ();
    cin.ignore();  
    cin.get();  
    menu_utama();

}

void tujuan (){
    stujuan kereta_b[6] = {
        {"Stasiun Argopuro", "Banyuwangi, Jawa Timur"},
        {"Stasiun Pasar Senen", "Jakarta Pusat, DKI Jakarta"},
        {"Stasiun Bogor", "Kota Bogor, Jawa Barat"},
        {"Stasiun Sidoarjo", "Sidoarjo, Jawa Timur"},
        {"Stasiun Kiaracondong", "Bandung, Jawa Barat"},
        {"Stasiun Gambir", "Jakarta Pusat, DKI Jakarta"}
    };
    
    int jumlahtiket = sizeof(kereta_b) / sizeof(kereta_b[0]);
    string cari;
    
    cout << "Masukkan Tujuan (DKI Jakarta / Jawa Barat / Jawa Timur) : ";
    cin.ignore(); 
    getline(cin, cari);
    cout << endl;
    
    bool ditemukan = false;
    cout << "Hasil Pencarian : " << endl;
    
    for (int i = 0; i < jumlahtiket; i++) {
        if (kereta_b[i].kota.find(cari) != string::npos) {
            cout << "- " << kereta_b[i].tujuan << " (" << kereta_b[i].kota << ")" << endl;
            ditemukan = true;
        }
    }
    
    if (!ditemukan) {
        cout << "Maaf, tujuan tidak ditemukan!\n";
    }
}



