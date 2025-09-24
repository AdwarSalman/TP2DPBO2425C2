# Elektronik.py
# Turunan Level 2: Elektronik
from Produk import Produk

class Elektronik(Produk):
    def __init__(self, id, nama, harga, brand, garansi, stok):
        super().__init__(id, nama, harga)
        self.__brand = brand
        self.__garansi = garansi
        self.__stok = stok

    def get_brand(self):
        return self.__brand

    def get_garansi(self):
        return self.__garansi

    def get_stok(self):
        return self.__stok