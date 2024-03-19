#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi pengguna
struct User {
    string nama;
    string password;
    string alamat;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Pengguna\n";
    cout << "2. Tampilkan Pengguna\n";
    cout << "3. Ubah Data Pengguna\n";
    cout << "4. Hapus Pengguna\n";
    cout << "5. Keluar\n";
    cout << "Pilih: ";
}

// Fungsi untuk menambahkan pengguna baru
void tambahPengguna(vector<User>& users) {
    User newUser;
    cout << "\nMasukkan Nama: ";
    getline(cin, newUser.nama);
    cout << "Masukkan Password: ";
    getline(cin, newUser.password);
    cout << "Masukkan Alamat: ";
    getline(cin, newUser.alamat);
    users.push_back(newUser);
    cout << "Pengguna berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan daftar pengguna
void tampilkanPengguna(const vector<User>& users) {
    cout << "\nDaftar Pengguna:\n";
    for (const User& user : users) {
        cout << "Nama: " << user.nama << ", Password: " << user.password << ", Alamat: " << user.alamat << endl;
    }
}

// Prosedur untuk mengubah data pengguna
void ubahDataPengguna(vector<User>& users) {
    string namaPengguna;
    cout << "\nMasukkan nama pengguna yang ingin diubah: ";
    getline(cin, namaPengguna);
    for (User& user : users) {
        if (user.nama == namaPengguna) {
            cout << "Masukkan password baru: ";
            getline(cin, user.password);
            cout << "Masukkan alamat baru: ";
            getline(cin, user.alamat);
            cout << "Data pengguna berhasil diubah.\n";
            return;
        }
    }
    cout << "Pengguna dengan nama tersebut tidak ditemukan.\n";
}

// Prosedur rekursif untuk mencari pengguna dan hapus pengguna
void hapusPenggunaRekursif(vector<User>& users, size_t index = 0) {
    if (index >= users.size()) {
        cout << "Pengguna dengan nama tersebut tidak ditemukan.\n";
        return;
    }

    string namaPengguna;
    cout << "\nMasukkan nama pengguna yang ingin dihapus: ";
    getline(cin, namaPengguna);

    if (users[index].nama == namaPengguna) {
        users.erase(users.begin() + index);
        cout << "Pengguna berhasil dihapus.\n";
    } else {
        hapusPenggunaRekursif(users, index + 1);
    }
}

// Fungsi untuk melakukan login
bool login() {
    string user, pass;
    int max_percobaan = 3;

    cout << "Selamat datang di program managem akun user shopee" << endl;

    for (int i = 1; i <= max_percobaan; i++) {
        cout << "Masukkan nama pengguna: ";
        cin >> user;
        cout << "Masukkan password: ";
        cin >> pass;

        if (user == "aidil" && pass == "042") {
            cout << "Anda berhasil login" << endl;
            return true;
        } else {
            cout << "Username/Password Anda salah" << endl;
            if (i < max_percobaan) {
                cout << "Anda memiliki " << max_percobaan - i << " percobaan lagi" << endl;
            } else {
                cout << "Anda telah melebihi batas percobaan. Silakan coba lagi nanti." << endl;
                return false;
            }
        }
    }
    return false;
}

int main() {
    vector<User> users;
    
    if (!login()) {
        return 1; // Keluar dari program jika gagal login
    }

    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer
        switch (pilihan) {
            case 1:
                tambahPengguna(users);
                break;
            case 2:
                tampilkanPengguna(users);
                break;
            case 3:
                ubahDataPengguna(users);
                break;
            case 4:
                hapusPenggunaRekursif(users);
                break;
            case 5:
                cout << "Terima kasih! Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
