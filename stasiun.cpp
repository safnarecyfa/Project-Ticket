#include <iostream>
using namespace std;

typedef struct {
    string nama, username, password;
} datauser;

string akun[100][3];
int banyak_user = 0;
const int max_user = 100;

void daftar();
void login();
void menu_utama(); 

int main() {
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
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                cin.get();
        }
    }
}

// Fungsi untuk mendaftar akun baru
void daftar() {
    system("cls");
    if (banyak_user >= max_user) {
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
    for (int i = 0; i < banyak_user; i++) {
        if (akun[i][1] == ds.username) {
            cout << "Username sudah digunakan, silahkan coba lagi!" << endl;
            cin.get();
            return;
        }
    }

    // Simpan data ke array
    akun[banyak_user][0] = ds.nama;
    akun[banyak_user][1] = ds.username;
    akun[banyak_user][2] = ds.password;
    banyak_user++;

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

        // Periksa apakah username dan password cocok
        bool login = false;
        for (int i = 0; i < banyak_user; i++) {
            if (akun[i][1] == username && akun[i][2] == password) {
                cout << "Login berhasil! Selamat datang, " << akun[i][0] << "!" << endl;
                cin.get();
                menu_utama();
                return;
            }
        }

        if (banyak_user == 0) {
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

// Fungsi menu_utama (contoh sederhana)
void menu_utama() {
    system("cls");
    cout << ".....menu utama." << endl;
    cin.get();
}