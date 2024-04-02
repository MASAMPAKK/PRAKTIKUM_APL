#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct untuk menyimpan informasi alamat pengguna
struct Alamat {
    string jalan;
    string kota;
    string provinsi;
};

// Struct untuk menyimpan informasi pengguna
struct Pengguna {
    string nama;
    string password;
    Alamat alamat; // Alamat digunakan di dalam struct Pengguna
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
void tambahPengguna(vector<Pengguna>& pengguna) {
    Pengguna newUser;
    cout << "\nMasukkan Nama: ";
    getline(cin, newUser.nama);
    // Validasi input tidak boleh kosong
    while (newUser.nama.empty()) {
        cout << "Nama tidak boleh kosong. Masukkan Nama: ";
        getline(cin, newUser.nama);
    }
    
    cout << "Masukkan Password: ";
    getline(cin, newUser.password);
    while (newUser.password.empty()) {
        cout << "Password tidak boleh kosong. Masukkan Password: ";
        getline(cin, newUser.password);
    }

    cout << "Masukkan Alamat (Jalan): ";
    getline(cin, newUser.alamat.jalan);
    while (newUser.alamat.jalan.empty()) {
        cout << "Alamat tidak boleh kosong. Masukkan Alamat (Jalan): ";
        getline(cin, newUser.alamat.jalan);
    }

    cout << "Masukkan Alamat (Kota): ";
    getline(cin, newUser.alamat.kota);
    while (newUser.alamat.kota.empty()) {
        cout << "Alamat tidak boleh kosong. Masukkan Alamat (Kota): ";
        getline(cin, newUser.alamat.kota);
    }

    cout << "Masukkan Alamat (Provinsi): ";
    getline(cin, newUser.alamat.provinsi);
    while (newUser.alamat.provinsi.empty()) {
        cout << "Alamat tidak boleh kosong. Masukkan Alamat (Provinsi): ";
        getline(cin, newUser.alamat.provinsi);
    }

    pengguna.push_back(newUser);
    cout << "Pengguna berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan daftar pengguna
void tampilkanPengguna(const vector<Pengguna>& pengguna) {
    cout << "\nDaftar Pengguna:\n";
    for (const Pengguna& user : pengguna) {
        cout << "Nama: " << user.nama << ", Password: " << user.password << endl;
        cout << "Alamat: " << user.alamat.jalan << ", " << user.alamat.kota << ", " << user.alamat.provinsi << endl;
    }
}

// Fungsi untuk mengubah data pengguna dengan menggunakan alamat vektor pengguna
void ubahDataPengguna(vector<Pengguna>* pengguna) {
    string namaPengguna;
    cout << "\nMasukkan nama pengguna yang ingin diubah: ";
    getline(cin, namaPengguna);
    for (Pengguna& user : *pengguna) {
        if (user.nama == namaPengguna) {
            cout << "Masukkan password baru: ";
            getline(cin, user.password);
            while (user.password.empty()) {
                cout << "Password tidak boleh kosong. Masukkan password baru: ";
                getline(cin, user.password);
            }
            cout << "Masukkan alamat baru (Jalan): ";
            getline(cin, user.alamat.jalan);
            while (user.alamat.jalan.empty()) {
                cout << "Alamat tidak boleh kosong. Masukkan alamat baru (Jalan): ";
                getline(cin, user.alamat.jalan);
            }
            cout << "Masukkan alamat baru (Kota): ";
            getline(cin, user.alamat.kota);
            while (user.alamat.kota.empty()) {
                cout << "Alamat tidak boleh kosong. Masukkan alamat baru (Kota): ";
                getline(cin, user.alamat.kota);
            }
            cout << "Masukkan alamat baru (Provinsi): ";
            getline(cin, user.alamat.provinsi);
            while (user.alamat.provinsi.empty()) {
                cout << "Alamat tidak boleh kosong. Masukkan alamat baru (Provinsi): ";
                getline(cin, user.alamat.provinsi);
            }
            cout << "Data pengguna berhasil diubah.\n";
            return;
        }
    }
    cout << "Pengguna dengan nama tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghapus pengguna dengan menggunakan pointer ke vektor pengguna
void hapusPenggunaPointer(vector<Pengguna>* pengguna, const string& namaPengguna) {
    auto it = pengguna->begin();
    while (it != pengguna->end()) {
        if (it->nama.find(namaPengguna) != string::npos) { // Memeriksa apakah bagian dari nama pengguna cocok
            it = pengguna->erase(it);
            cout << "Pengguna berhasil dihapus.\n";
            return;
        } else {
            ++it;
        }
    }
    cout << "Pengguna dengan nama tersebut tidak ditemukan.\n";
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
    vector<Pengguna> daftarPengguna;
    
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
                tambahPengguna(daftarPengguna);
                break;
            case 2:
                tampilkanPengguna(daftarPengguna);
                break;
            case 3:
                ubahDataPengguna(&daftarPengguna);
                break;
            case 4: {
                string namaPengguna;
                cout << "\nMasukkan nama pengguna yang ingin dihapus: ";
                cin.ignore(); // membersihkan buffer
                getline(cin, namaPengguna);
                hapusPenggunaPointer(&daftarPengguna, namaPengguna);
                break;
            }
            case 5:
                cout << "Terima kasih! Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
