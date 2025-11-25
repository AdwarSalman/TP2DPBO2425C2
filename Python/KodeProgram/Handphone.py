# Handphone.py
# Turunan Level 3: Handphone
from Elektronik import Elektronik

class Handphone(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, os, camera, battery):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.__os = os
        self.__camera = camera
        self.__battery = battery

    def get_kategori(self):
        return "Handphone"

    def get_detail(self):
        return f"OS:{self.__os}, Camera:{self.__camera}MP, {self.__battery}mAh"