// Aksesoris.h
#ifndef AKSESORIS_H
#define AKSESORIS_H

#include "Elektronik.h"

class Aksesoris : public Elektronik {
private:
    string jenis;
    string warna;
    string compatibility;

public:
    Aksesoris(int _id, string _nama, double _harga,
              string _brand, int _garansi, int _stok,
              string _jenis, string _warna, string _compatibility);

    string getKategori() const override;
    string getDetail() const override;
};

#endif