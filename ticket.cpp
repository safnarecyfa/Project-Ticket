#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Data {
    string NIP;
    string pass;
};

bool LogIn = false;

bool login(int log);

int main() {
        LogIn = login(3);

    if (LogIn) {
        system("cls");
        cout << "Haloo";
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

    cout << "Masukkan NIP : ";
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
        cout << "Selamat Datang" << endl;
        getch();
        return true;
    } else {
            cout << "Ayo coba lagi! \n Sisa percobaan: " << log-1 << endl;
            system("pause");
            system("cls");
            return login(log-1);
        }
}