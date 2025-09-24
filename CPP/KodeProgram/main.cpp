#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>

// Impor semua file header class
#include "Produk.h"
#include "Elektronik.h"
#include "Laptop.h"
#include "Handphone.h"
#include "Aksesoris.h"

using namespace std;

// ===================================
// Implementasi Metode-Metode Kelas
// ===================================

// Implementasi metode-metode Produk
Produk::Produk(int _id, string _nama, double _harga)
    : id(_id), nama(_nama), harga(_harga) {}

int Produk::getId() const { return id; }
string Produk::getNama() const { return nama; }
double Produk::getHarga() const { return harga; }

// Implementasi metode-metode Elektronik
Elektronik::Elektronik(int _id, string _nama, double _harga,
                       string _brand, int _garansi, int _stok)
    : Produk(_id, _nama, _harga),
      brand(_brand), garansi(_garansi), stok(_stok) {}

string Elektronik::getBrand() const { return brand; }
int Elektronik::getGaransi() const { return garansi; }
int Elektronik::getStok() const { return stok; }

// Implementasi metode-metode Laptop
Laptop::Laptop(int _id, string _nama, double _harga,
               string _brand, int _garansi, int _stok,
               int _ram, int _storage, string _processor)
    : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
      ram(_ram), storage(_storage), processor(_processor) {}

string Laptop::getKategori() const { return "Laptop"; }
string Laptop::getDetail() const {
    return "RAM:" + to_string(ram) + "GB, Storage:" +
           to_string(storage) + "GB, " + processor;
}

// Implementasi metode-metode Handphone
Handphone::Handphone(int _id, string _nama, double _harga,
                     string _brand, int _garansi, int _stok,
                     string _os, int _camera, int _battery)
    : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
      os(_os), camera(_camera), battery(_battery) {}

string Handphone::getKategori() const { return "Handphone"; }
string Handphone::getDetail() const {
    return "OS:" + os + ", Camera:" + to_string(camera) +
           "MP, " + to_string(battery) + "mAh";
}

// Implementasi metode-metode Aksesoris
Aksesoris::Aksesoris(int _id, string _nama, double _harga,
                     string _brand, int _garansi, int _stok,
                     string _jenis, string _warna, string _compatibility)
    : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
      jenis(_jenis), warna(_warna), compatibility(_compatibility) {}

string Aksesoris::getKategori() const { return "Aksesoris"; }
string Aksesoris::getDetail() const {
    return "Jenis:" + jenis + ", Warna:" + warna +
           ", " + compatibility;
}

// ===================================
// Fungsi-Fungsi Program Utama
// ===================================

// Fungsi untuk cetak garis horizontal tabel
void printSeparator(const vector<int>& colWidths) {
    for (size_t i = 0; i < colWidths.size(); i++) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;
}

// Fungsi untuk menampilkan semua produk
void tampilkanProduk(const vector<Produk*>& daftarProduk) {
    if (daftarProduk.empty()) {
        cout << "Belum ada produk yang ditambahkan.\n";
        return;
    }

    vector<string> headers = {"ID", "Nama", "Harga", "Brand", "Garansi", "Stok", "Kategori", "Detail"};
    vector<int> colWidths(headers.size(), 0);

    for (size_t i = 0; i < headers.size(); i++) {
        colWidths[i] = headers[i].size();
    }

    for (auto p : daftarProduk) {
        colWidths[0] = max(colWidths[0], (int)to_string(p->getId()).size());
        colWidths[1] = max(colWidths[1], (int)p->getNama().size());
        colWidths[2] = max(colWidths[2], (int)to_string((long long)p->getHarga()).size());
        colWidths[6] = max(colWidths[6], (int)p->getKategori().size());
        colWidths[7] = max(colWidths[7], (int)p->getDetail().size());
        
        Elektronik* e = dynamic_cast<Elektronik*>(p);
        if (e != nullptr) {
            colWidths[3] = max(colWidths[3], (int)e->getBrand().size());
            colWidths[4] = max(colWidths[4], (int)to_string(e->getGaransi()).size());
            colWidths[5] = max(colWidths[5], (int)to_string(e->getStok()).size());
        }
    }

    printSeparator(colWidths);
    for (size_t i = 0; i < headers.size(); i++) {
        cout << " " << left << setw(colWidths[i]) << headers[i] << " |";
    }
    cout << endl;
    printSeparator(colWidths);

    for (auto p : daftarProduk) {
        Elektronik* e = dynamic_cast<Elektronik*>(p);
        cout << " " << left << setw(colWidths[0]) << p->getId() << " |";
        cout << " " << left << setw(colWidths[1]) << p->getNama() << " |";
        cout << " " << left << setw(colWidths[2]) << (long long)p->getHarga() << " |";
        if (e != nullptr) {
            cout << " " << left << setw(colWidths[3]) << e->getBrand() << " |";
            cout << " " << left << setw(colWidths[4]) << e->getGaransi() << " |";
            cout << " " << left << setw(colWidths[5]) << e->getStok() << " |";
        } else {
            cout << " " << left << setw(colWidths[3]) << "N/A" << " |";
            cout << " " << left << setw(colWidths[4]) << "N/A" << " |";
            cout << " " << left << setw(colWidths[5]) << "N/A" << " |";
        }
        cout << " " << left << setw(colWidths[6]) << p->getKategori() << " |";
        cout << " " << left << setw(colWidths[7]) << p->getDetail() << " |";
        cout << endl;
    }
    printSeparator(colWidths);
}

// Fungsi untuk tambah produk baru
void tambahProduk(vector<Produk*>& daftarProduk, int& nextId) {
    int pilihan;
    cout << "Pilih kategori produk:\n";
    cout << "1. Laptop\n2. Handphone\n3. Aksesoris\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    string nama, brand;
    double harga;
    int garansi, stok;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Harga: ";
    cin >> harga;
    cout << "Masukkan Brand: ";
    cin >> brand;
    cout << "Masukkan Garansi (bulan): ";
    cin >> garansi;
    cout << "Masukkan Stok: ";
    cin >> stok;

    if (pilihan == 1) {
        int ram, storage;
        string processor;
        cout << "Masukkan RAM (GB): ";
        cin >> ram;
        cout << "Masukkan Storage (GB): ";
        cin >> storage;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Processor: ";
        getline(cin, processor);

        daftarProduk.push_back(new Laptop(nextId++, nama, harga, brand, garansi, stok, ram, storage, processor));
    }
    else if (pilihan == 2) {
        string os;
        int camera, battery;
        cout << "Masukkan OS: ";
        cin >> os;
        cout << "Masukkan Camera (MP): ";
        cin >> camera;
        cout << "Masukkan Battery (mAh): ";
        cin >> battery;

        daftarProduk.push_back(new Handphone(nextId++, nama, harga, brand, garansi, stok, os, camera, battery));
    }
    else if (pilihan == 3) {
        string jenis, warna, compatibility;
        cout << "Masukkan Jenis: ";
        cin >> jenis;
        cout << "Masukkan Warna: ";
        cin >> warna;
        cout << "Masukkan Compatibility: ";
        cin >> compatibility;

        daftarProduk.push_back(new Aksesoris(nextId++, nama, harga, brand, garansi, stok, jenis, warna, compatibility));
    }
    else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    cout << "Produk berhasil ditambahkan!\n";
}

int main() {
    vector<Produk*> daftarProduk;
    int nextId = 1;
    int menu;

    daftarProduk.push_back(new Laptop(nextId++, "Laptop Gaming", 15000000, "ASUS", 24, 5, 16, 512, "i7"));
    daftarProduk.push_back(new Laptop(nextId++, "Laptop Ultrabook", 12000000, "Dell", 18, 3, 8, 256, "i5"));
    daftarProduk.push_back(new Handphone(nextId++, "Smartphone Pro", 8000000, "Samsung", 12, 10, "Android", 108, 5000));
    daftarProduk.push_back(new Handphone(nextId++, "iPhone 14", 15000000, "Apple", 12, 7, "iOS", 48, 4500));
    daftarProduk.push_back(new Aksesoris(nextId++, "Headphone BT", 1200000, "Sony", 6, 20, "Headset", "Hitam", "Bluetooth"));

    do {
        cout << "\n=== Menu Gerlong Electric ===";
        cout << "\n1. Tambah Produk";
        cout << "\n2. Lihat Semua Produk";
        cout << "\n3. Keluar";
        cout << "\nPilihan: ";
        cin >> menu;

        switch (menu) {
        case 1:
            tambahProduk(daftarProduk, nextId);
            break;
        case 2:
            tampilkanProduk(daftarProduk);
            break;
        case 3:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (menu != 3);

    for (auto p : daftarProduk) {
        delete p;
    }

    return 0;
}