# Aksesoris.py
# Turunan Level 3: Aksesoris
from Elektronik import Elektronik

class Aksesoris(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, jenis, warna, compatibility):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.__jenis = jenis
        self.__warna = warna
        self.__compatibility = compatibility

    def get_kategori(self):
        return "Aksesoris"

    def get_detail(self):
        return f"Jenis:{self.__jenis}, Warna:{self.__warna}, {self.__compatibility}"