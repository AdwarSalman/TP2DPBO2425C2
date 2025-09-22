#include "GerlongElectric.h"
#include <vector>
#include <algorithm>
#include <limits> // untuk numeric_limits saat clear input

using namespace std;

// Fungsi untuk cetak garis horizontal tabel
void printSeparator(const vector<int>& colWidths) {
    for (size_t i = 0; i < colWidths.size(); i++) {
        cout << string(colWidths[i] + 2, '-') << "+";
    }
    cout << endl;
}

// Fungsi untuk menampilkan semua produk
void tampilkanProduk(const vector<Elektronik*>& daftarProduk) {
    if (daftarProduk.empty()) {
        cout << "Belum ada produk yang ditambahkan.\n";
        return;
    }

    // Header tabel
    vector<string> headers = {"ID", "Nama", "Harga", "Brand", "Garansi", "Stok", "Kategori", "Detail"};
    vector<int> colWidths(headers.size(), 0);

    // Panjang minimal = header
    for (size_t i = 0; i < headers.size(); i++) {
        colWidths[i] = headers[i].size();
    }

    // Bandingkan dengan isi data
    for (auto p : daftarProduk) {
        colWidths[0] = max(colWidths[0], (int)to_string(p->getId()).size());
        colWidths[1] = max(colWidths[1], (int)p->getNama().size());
        colWidths[2] = max(colWidths[2], (int)to_string((long long)p->getHarga()).size());
        colWidths[3] = max(colWidths[3], (int)((Elektronik*)p)->getBrand().size());
        colWidths[4] = max(colWidths[4], (int)to_string(((Elektronik*)p)->getGaransi()).size());
        colWidths[5] = max(colWidths[5], (int)to_string(((Elektronik*)p)->getStok()).size());
        colWidths[6] = max(colWidths[6], (int)p->getKategori().size());
        colWidths[7] = max(colWidths[7], (int)p->getDetail().size());
    }

    // Cetak header
    printSeparator(colWidths);
    for (size_t i = 0; i < headers.size(); i++) {
        cout << " " << left << setw(colWidths[i]) << headers[i] << " |";
    }
    cout << endl;
    printSeparator(colWidths);

    // Cetak isi
    for (auto p : daftarProduk) {
        cout << " " << left << setw(colWidths[0]) << p->getId() << " |";
        cout << " " << left << setw(colWidths[1]) << p->getNama() << " |";
        cout << " " << left << setw(colWidths[2]) << (long long)p->getHarga() << " |";
        cout << " " << left << setw(colWidths[3]) << ((Elektronik*)p)->getBrand() << " |";
        cout << " " << left << setw(colWidths[4]) << ((Elektronik*)p)->getGaransi() << " |";
        cout << " " << left << setw(colWidths[5]) << ((Elektronik*)p)->getStok() << " |";
        cout << " " << left << setw(colWidths[6]) << p->getKategori() << " |";
        cout << " " << left << setw(colWidths[7]) << p->getDetail() << " |";
        cout << endl;
    }

    printSeparator(colWidths);
}

// Fungsi untuk tambah produk baru
void tambahProduk(vector<Elektronik*>& daftarProduk, int& nextId) {
    int pilihan;
    cout << "Pilih kategori produk:\n";
    cout << "1. Laptop\n2. Handphone\n3. Aksesoris\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    // Input atribut umum
    string nama, brand;
    double harga;
    int garansi, stok;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
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

    // Input atribut khusus sesuai kategori
    if (pilihan == 1) { // Laptop
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
    else if (pilihan == 2) { // Handphone
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
    else if (pilihan == 3) { // Aksesoris
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
    vector<Elektronik*> daftarProduk;
    int nextId = 1;
    int menu;

    // Tambah 5 produk default (hardcode)
    daftarProduk.push_back(new Laptop(nextId++, "Laptop Gaming", 15000000, "ASUS", 24, 5, 16, 512, "i7"));
    daftarProduk.push_back(new Laptop(nextId++, "Laptop Ultrabook", 12000000, "Dell", 18, 3, 8, 256, "i5"));
    daftarProduk.push_back(new Handphone(nextId++, "Smartphone Pro", 8000000, "Samsung", 12, 10, "Android", 108, 5000));
    daftarProduk.push_back(new Handphone(nextId++, "iPhone 14", 15000000, "Apple", 12, 7, "iOS", 48, 4500));
    daftarProduk.push_back(new Aksesoris(nextId++, "Headphone BT", 1200000, "Sony", 6, 20, "Headset", "Hitam", "Bluetooth"));

    do {
        cout << "\n=== Menu Gerlong Electric ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Semua Produk\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
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

    // Bersihkan memory
    for (auto p : daftarProduk) {
        delete p;
    }

    return 0;
}
