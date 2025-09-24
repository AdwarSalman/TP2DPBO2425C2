# GerlongElectric.py
# Driver Program
# Program ini memanfaatkan inheritance multilevel dan polymorphism
# untuk mengelola data produk di toko elektronik.

from Laptop import Laptop
from Handphone import Handphone
from Aksesoris import Aksesoris

# Utility function: cetak tabel dinamis
def tampilkan_produk(daftar_produk):
    if not daftar_produk:
        print("Belum ada produk.")
        return

    headers = ["ID", "Nama", "Harga", "Brand", "Garansi", "Stok", "Kategori", "Detail"]

    # Hitung lebar kolom berdasarkan data terpanjang
    col_widths = [len(h) for h in headers]
    for p in daftar_produk:
        col_widths[0] = max(col_widths[0], len(str(p.get_id())))
        col_widths[1] = max(col_widths[1], len(p.get_nama()))
        col_widths[2] = max(col_widths[2], len(str(int(p.get_harga()))))
        col_widths[3] = max(col_widths[3], len(p.get_brand()))
        col_widths[4] = max(col_widths[4], len(str(p.get_garansi())))
        col_widths[5] = max(col_widths[5], len(str(p.get_stok())))
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
        print(f" {p.get_id():<{col_widths[0]}} |", end="")
        print(f" {p.get_nama():<{col_widths[1]}} |", end="")
        print(f" {int(p.get_harga()):<{col_widths[2]}} |", end="")
        print(f" {p.get_brand():<{col_widths[3]}} |", end="")
        print(f" {p.get_garansi():<{col_widths[4]}} |", end="")
        print(f" {p.get_stok():<{col_widths[5]}} |", end="")
        print(f" {p.get_kategori():<{col_widths[6]}} |", end="")
        print(f" {p.get_detail():<{col_widths[7]}} |", end="")
        print()
    print_separator()


# Tambah produk baru
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


# Main Program
def main():
    daftar_produk = []
    next_id = [1]

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

if __name__ == "__main__":
    main()