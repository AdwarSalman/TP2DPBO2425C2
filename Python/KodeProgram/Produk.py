# Produk.py
# Base Class: Produk
from abc import ABC, abstractmethod

class Produk(ABC):
    def __init__(self, id, nama, harga):
        self.__id = id
        self.__nama = nama
        self.__harga = harga

    def get_id(self):
        return self.__id

    def get_nama(self):
        return self.__nama

    def get_harga(self):
        return self.__harga

    @abstractmethod
    def get_kategori(self):
        pass

    @abstractmethod
    def get_detail(self):
        pass