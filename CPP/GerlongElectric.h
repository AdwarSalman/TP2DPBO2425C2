#include <iostream>   // untuk input-output (cout, cin)
#include <iomanip>    // untuk formatting tabel (setw, setprecision)
#include <string>     // untuk tipe data string
using namespace std;

// =============================
// Base Class: Produk
// Level 1 dari inheritance
// =============================
class Produk {
protected:
    int id;         // ID unik produk
    string nama;    // Nama produk
    double harga;   // Harga produk

public:
    Produk(int _id, string _nama, double _harga)
        : id(_id), nama(_nama), harga(_harga) {}

    virtual ~Produk() {}

    int getId() const { return id; }
    string getNama() const { return nama; }
    double getHarga() const { return harga; }

    // Pure virtual functions (harus dioverride child)
    virtual string getKategori() const = 0;
    virtual string getDetail() const = 0;
    virtual void displayRow() const = 0;
};

// =============================
// Turunan Level 2: Elektronik
// Semua produk elektronik punya brand, garansi, stok
// =============================
class Elektronik : public Produk {
protected:
    string brand;   // Merk produk
    int garansi;   // Lama garansi (bulan)
    int stok;      // Jumlah unit tersedia

public:
    Elektronik(int _id, string _nama, double _harga,
               string _brand, int _garansi, int _stok)
        : Produk(_id, _nama, _harga),
          brand(_brand), garansi(_garansi), stok(_stok) {}

    string getBrand() const { return brand; }
    int getGaransi() const { return garansi; }
    int getStok() const { return stok; }
};

// =============================
// Turunan Level 3: Laptop
// =============================
class Laptop : public Elektronik {
private:
    int ram;        // RAM (GB)
    int storage;    // Storage (GB)
    string processor;

public:
    Laptop(int _id, string _nama, double _harga,
           string _brand, int _garansi, int _stok,
           int _ram, int _storage, string _processor)
        : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
          ram(_ram), storage(_storage), processor(_processor) {}

    string getKategori() const override { return "Laptop"; }

    string getDetail() const override {
        return "RAM:" + to_string(ram) + "GB, Storage:" +
               to_string(storage) + "GB, " + processor;
    }

    void displayRow() const override {
        cout << left << setw(3) << id
             << setw(20) << nama
             << setw(10) << fixed << setprecision(0) << harga
             << setw(10) << brand
             << setw(8) << garansi
             << setw(6) << stok
             << setw(12) << getKategori()
             << setw(40) << getDetail()
             << endl;
    }
};

// =============================
// Turunan Level 3: Handphone
// =============================
class Handphone : public Elektronik {
private:
    string os;
    int camera;   // MP
    int battery;  // mAh

public:
    Handphone(int _id, string _nama, double _harga,
              string _brand, int _garansi, int _stok,
              string _os, int _camera, int _battery)
        : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
          os(_os), camera(_camera), battery(_battery) {}

    string getKategori() const override { return "Handphone"; }

    string getDetail() const override {
        return "OS:" + os + ", Camera:" + to_string(camera) +
               "MP, " + to_string(battery) + "mAh";
    }

    void displayRow() const override {
        cout << left << setw(3) << id
             << setw(20) << nama
             << setw(10) << fixed << setprecision(0) << harga
             << setw(10) << brand
             << setw(8) << garansi
             << setw(6) << stok
             << setw(12) << getKategori()
             << setw(40) << getDetail()
             << endl;
    }
};

// =============================
// Turunan Level 3: Aksesoris
// =============================
class Aksesoris : public Elektronik {
private:
    string jenis;
    string warna;
    string compatibility;

public:
    Aksesoris(int _id, string _nama, double _harga,
              string _brand, int _garansi, int _stok,
              string _jenis, string _warna, string _compatibility)
        : Elektronik(_id, _nama, _harga, _brand, _garansi, _stok),
          jenis(_jenis), warna(_warna), compatibility(_compatibility) {}

    string getKategori() const override { return "Aksesoris"; }

    string getDetail() const override {
        return "Jenis:" + jenis + ", Warna:" + warna +
               ", " + compatibility;
    }

    void displayRow() const override {
        cout << left << setw(3) << id
             << setw(20) << nama
             << setw(10) << fixed << setprecision(0) << harga
             << setw(10) << brand
             << setw(8) << garansi
             << setw(6) << stok
             << setw(12) << getKategori()
             << setw(40) << getDetail()
             << endl;
    }
};

