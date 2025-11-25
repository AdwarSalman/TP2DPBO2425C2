// Laptop.h
#ifndef LAPTOP_H
#define LAPTOP_H

#include "Elektronik.h"

class Laptop : public Elektronik {
private:
    int ram;
    int storage;
    string processor;

public:
    Laptop(int _id, string _nama, double _harga,
           string _brand, int _garansi, int _stok,
           int _ram, int _storage, string _processor);

    string getKategori() const override;
    string getDetail() const override;
};

#endif