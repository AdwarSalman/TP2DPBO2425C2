# Laptop.py
# Turunan Level 3: Laptop
from Elektronik import Elektronik

class Laptop(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, ram, storage, processor):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.__ram = ram
        self.__storage = storage
        self.__processor = processor

    def get_kategori(self):
        return "Laptop"

    def get_detail(self):
        return f"RAM:{self.__ram}GB, Storage:{self.__storage}GB, {self.__processor}"