// Elektronik.h
#ifndef ELEKTRONIK_H
#define ELEKTRONIK_H

#include "Produk.h"

class Elektronik : public Produk {
private:
    string brand;
    int garansi;
    int stok;

public:
    Elektronik(int _id, string _nama, double _harga,
               string _brand, int _garansi, int _stok);

    string getBrand() const;
    int getGaransi() const;
    int getStok() const;
};

#endif