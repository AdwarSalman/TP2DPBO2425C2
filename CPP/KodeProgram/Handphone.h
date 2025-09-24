// Handphone.h
#ifndef HANDPHONE_H
#define HANDPHONE_H

#include "Elektronik.h"

class Handphone : public Elektronik {
private:
    string os;
    int camera;
    int battery;

public:
    Handphone(int _id, string _nama, double _harga,
              string _brand, int _garansi, int _stok,
              string _os, int _camera, int _battery);

    string getKategori() const override;
    string getDetail() const override;
};

#endif