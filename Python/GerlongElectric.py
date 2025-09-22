# GerlongElectric.py
# Implementasi TP2 dalam Python
# Program ini memanfaatkan inheritance multilevel dan polymorphism
# untuk mengelola data produk di toko elektronik.

from abc import ABC, abstractmethod  # ABC = Abstract Base Class, abstractmethod untuk membuat method abstrak

# =============================
# Base Class: Produk
# =============================
# Class Produk adalah class abstrak yang berisi atribut dasar
# Semua produk memiliki id, nama, dan harga.
class Produk(ABC):
    def __init__(self, id, nama, harga):
        self.id = id          # ID unik produk
        self.nama = nama      # Nama produk
        self.harga = harga    # Harga produk

    # Method abstrak → wajib diimplementasikan oleh child
    @abstractmethod
    def get_kategori(self):
        pass

    @abstractmethod
    def get_detail(self):
        pass


# =============================
# Turunan Level 2: Elektronik
# =============================
# Class Elektronik adalah turunan Produk
# Semua elektronik memiliki brand, garansi, dan stok
class Elektronik(Produk):
    def __init__(self, id, nama, harga, brand, garansi, stok):
        super().__init__(id, nama, harga)  # memanggil konstruktor Produk
        self.brand = brand
        self.garansi = garansi
        self.stok = stok


# =============================
# Turunan Level 3: Laptop
# =============================
class Laptop(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, ram, storage, processor):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.ram = ram
        self.storage = storage
        self.processor = processor

    def get_kategori(self):
        return "Laptop"

    def get_detail(self):
        return f"RAM:{self.ram}GB, Storage:{self.storage}GB, {self.processor}"


# =============================
# Turunan Level 3: Handphone
# =============================
class Handphone(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, os, camera, battery):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.os = os
        self.camera = camera
        self.battery = battery

    def get_kategori(self):
        return "Handphone"

    def get_detail(self):
        return f"OS:{self.os}, Camera:{self.camera}MP, {self.battery}mAh"


# =============================
# Turunan Level 3: Aksesoris
# =============================
class Aksesoris(Elektronik):
    def __init__(self, id, nama, harga, brand, garansi, stok, jenis, warna, compatibility):
        super().__init__(id, nama, harga, brand, garansi, stok)
        self.jenis = jenis
        self.warna = warna
        self.compatibility = compatibility

    def get_kategori(self):
        return "Aksesoris"

    def get_detail(self):
        return f"Jenis:{self.jenis}, Warna:{self.warna}, {self.compatibility}"


# =============================
# Utility function: cetak tabel dinamis
# =============================
def tampilkan_produk(daftar_produk):
    if not daftar_produk:
        print("Belum ada produk.")
        return

    headers = ["ID", "Nama", "Harga", "Brand", "Garansi", "Stok", "Kategori", "Detail"]

    # Hitung lebar kolom berdasarkan data terpanjang
    col_widths = [len(h) for h in headers]
    for p in daftar_produk:
        col_widths[0] = max(col_widths[0], len(str(p.id)))
        col_widths[1] = max(col_widths[1], len(p.nama))
        col_widths[2] = max(col_widths[2], len(str(int(p.harga))))
        col_widths[3] = max(col_widths[3], len(p.brand))
        col_widths[4] = max(col_widths[4], len(str(p.garansi)))
        col_widths[5] = max(col_widths[5], len(str(p.stok)))
        col_widths[6] = max(col_widths[6], len(p.get_kategori()))
        col_widths[7] = max(col_widths[7], len(p.get_detail()))

    # Cetak garis pemisah
    def print_separator():
        for w in col_widths:
            print("-" * (w + 2) + "+", end="")
        print()

    # Cetak header
    print_separator()
    for i, h in enumerate(headers):
        print(f" {h:<{col_widths[i]}} |", end="")
    print()
    print_separator()

    # Cetak isi tabel
    for p in daftar_produk:
        print(f" {p.id:<{col_widths[0]}} |", end="")
        print(f" {p.nama:<{col_widths[1]}} |", end="")
        print(f" {int(p.harga):<{col_widths[2]}} |", end="")
        print(f" {p.brand:<{col_widths[3]}} |", end="")
        print(f" {p.garansi:<{col_widths[4]}} |", end="")
        print(f" {p.stok:<{col_widths[5]}} |", end="")
        print(f" {p.get_kategori():<{col_widths[6]}} |", end="")
        print(f" {p.get_detail():<{col_widths[7]}} |", end="")
        print()
    print_separator()


# =============================
# Tambah produk baru
# =============================
def tambah_produk(daftar_produk, next_id):
    print("Pilih kategori:")
    print("1. Laptop\n2. Handphone\n3. Aksesoris")
    pilih = input("Pilihan: ")

    # Input atribut umum
    nama = input("Nama: ")
    harga = float(input("Harga: "))
    brand = input("Brand: ")
    garansi = int(input("Garansi (bulan): "))
    stok = int(input("Stok: "))

    if pilih == "1":
        ram = int(input("RAM (GB): "))
        storage = int(input("Storage (GB): "))
        processor = input("Processor: ")
        daftar_produk.append(Laptop(next_id[0], nama, harga, brand, garansi, stok, ram, storage, processor))
    elif pilih == "2":
        os = input("OS: ")
        camera = int(input("Camera (MP): "))
        battery = int(input("Battery (mAh): "))
        daftar_produk.append(Handphone(next_id[0], nama, harga, brand, garansi, stok, os, camera, battery))
    elif pilih == "3":
        jenis = input("Jenis: ")
        warna = input("Warna: ")
        compatibility = input("Compatibility: ")
        daftar_produk.append(Aksesoris(next_id[0], nama, harga, brand, garansi, stok, jenis, warna, compatibility))
    else:
        print("Pilihan salah.")
        return

    next_id[0] += 1
    print("Produk berhasil ditambahkan!")


# =============================
# Main Program
# =============================
def main():
    daftar_produk = []
    next_id = [1]  # list dipakai supaya mutable

    # Produk default (5 item)
    daftar_produk.append(Laptop(next_id[0], "Laptop Gaming", 15000000, "ASUS", 24, 5, 16, 512, "i7")); next_id[0]+=1
    daftar_produk.append(Laptop(next_id[0], "Laptop Ultrabook", 12000000, "Dell", 18, 3, 8, 256, "i5")); next_id[0]+=1
    daftar_produk.append(Handphone(next_id[0], "Smartphone Pro", 8000000, "Samsung", 12, 10, "Android", 108, 5000)); next_id[0]+=1
    daftar_produk.append(Handphone(next_id[0], "iPhone 14", 15000000, "Apple", 12, 7, "iOS", 48, 4500)); next_id[0]+=1
    daftar_produk.append(Aksesoris(next_id[0], "Headphone BT", 1200000, "Sony", 6, 20, "Headset", "Hitam", "Bluetooth")); next_id[0]+=1

    while True:
        print("\n=== Menu Gerlong Electric ===")
        print("1. Tambah Produk")
        print("2. Lihat Semua Produk")
        print("3. Keluar")
        menu = input("Pilihan: ")

        if menu == "1":
            tambah_produk(daftar_produk, next_id)
        elif menu == "2":
            tampilkan_produk(daftar_produk)
        elif menu == "3":
            print("Keluar...")
            break
        else:
            print("Pilihan salah!")


# Jalankan program
if __name__ == "__main__":
    main()
