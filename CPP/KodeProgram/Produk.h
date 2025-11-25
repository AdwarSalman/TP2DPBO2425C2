// Produk.h
#ifndef PRODUK_H
#define PRODUK_H

#include <iostream>
#include <string>

using namespace std;

class Produk {
private:
    int id;
    string nama;
    double harga;

public:
    Produk(int _id, string _nama, double _harga);
    virtual ~Produk() {}

    int getId() const;
    string getNama() const;
    double getHarga() const;

    virtual string getKategori() const = 0;
    virtual string getDetail() const = 0;
};

#endif