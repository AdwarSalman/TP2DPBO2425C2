// GerlongElectric.java
// File ini berisi main program untuk menampilkan menu interaktif.
import java.util.*;

public class GerlongElectric {
    private static Scanner sc = new Scanner(System.in);

    private static void printSeparator(int[] colWidths) {
        for (int width : colWidths) {
            for (int i = 0; i < width + 2; i++) System.out.print("-");
            System.out.print("+");
        }
        System.out.println();
    }

    private static void tampilkanProduk(List<Elektronik> daftarProduk) {
        if (daftarProduk.isEmpty()) {
            System.out.println("Belum ada produk yang ditambahkan.");
            return;
        }

        String[] headers = {"ID", "Nama", "Harga", "Brand", "Garansi", "Stok", "Kategori", "Detail"};
        int[] colWidths = new int[headers.length];

        for (int i = 0; i < headers.length; i++) {
            colWidths[i] = headers[i].length();
        }

        for (Elektronik p : daftarProduk) {
            colWidths[0] = Math.max(colWidths[0], String.valueOf(p.getId()).length());
            colWidths[1] = Math.max(colWidths[1], p.getNama().length());
            colWidths[2] = Math.max(colWidths[2], String.valueOf((long)p.getHarga()).length());
            colWidths[3] = Math.max(colWidths[3], p.getBrand().length());
            colWidths[4] = Math.max(colWidths[4], String.valueOf(p.getGaransi()).length());
            colWidths[5] = Math.max(colWidths[5], String.valueOf(p.getStok()).length());
            colWidths[6] = Math.max(colWidths[6], p.getKategori().length());
            colWidths[7] = Math.max(colWidths[7], p.getDetail().length());
        }

        printSeparator(colWidths);
        for (int i = 0; i < headers.length; i++) {
            System.out.printf(" %-" + colWidths[i] + "s |", headers[i]);
        }
        System.out.println();
        printSeparator(colWidths);

        for (Elektronik p : daftarProduk) {
            System.out.printf(" %-" + colWidths[0] + "s |", p.getId());
            System.out.printf(" %-" + colWidths[1] + "s |", p.getNama());
            System.out.printf(" %-" + colWidths[2] + "s |", (long)p.getHarga());
            System.out.printf(" %-" + colWidths[3] + "s |", p.getBrand());
            System.out.printf(" %-" + colWidths[4] + "s |", p.getGaransi());
            System.out.printf(" %-" + colWidths[5] + "s |", p.getStok());
            System.out.printf(" %-" + colWidths[6] + "s |", p.getKategori());
            System.out.printf(" %-" + colWidths[7] + "s |", p.getDetail());
            System.out.println();
        }
        printSeparator(colWidths);
    }

    private static void tambahProduk(List<Elektronik> daftarProduk, int[] nextId) {
        System.out.println("Pilih kategori:");
        System.out.println("1. Laptop\n2. Handphone\n3. Aksesoris");
        System.out.print("Pilihan: ");
        int pilih = sc.nextInt(); sc.nextLine();

        System.out.print("Nama: "); String nama = sc.nextLine();
        System.out.print("Harga: "); double harga = sc.nextDouble(); sc.nextLine();
        System.out.print("Brand: "); String brand = sc.nextLine();
        System.out.print("Garansi (bulan): "); int garansi = sc.nextInt();
        System.out.print("Stok: "); int stok = sc.nextInt(); sc.nextLine();

        if (pilih == 1) {
            System.out.print("RAM (GB): "); int ram = sc.nextInt();
            System.out.print("Storage (GB): "); int storage = sc.nextInt(); sc.nextLine();
            System.out.print("Processor: "); String proc = sc.nextLine();
            daftarProduk.add(new Laptop(nextId[0]++, nama, harga, brand, garansi, stok, ram, storage, proc));
        } else if (pilih == 2) {
            System.out.print("OS: "); String os = sc.nextLine();
            System.out.print("Camera (MP): "); int cam = sc.nextInt();
            System.out.print("Battery (mAh): "); int bat = sc.nextInt(); sc.nextLine();
            daftarProduk.add(new Handphone(nextId[0]++, nama, harga, brand, garansi, stok, os, cam, bat));
        } else if (pilih == 3) {
            System.out.print("Jenis: "); String jenis = sc.nextLine();
            System.out.print("Warna: "); String warna = sc.nextLine();
            System.out.print("Compatibility: "); String comp = sc.nextLine();
            daftarProduk.add(new Aksesoris(nextId[0]++, nama, harga, brand, garansi, stok, jenis, warna, comp));
        } else {
            System.out.println("Pilihan salah.");
        }
    }

    public static void main(String[] args) {
        List<Elektronik> daftarProduk = new ArrayList<>();
        int[] nextId = {1};
        int menu;

        daftarProduk.add(new Laptop(nextId[0]++, "Laptop Gaming", 15000000, "ASUS", 24, 5, 16, 512, "i7"));
        daftarProduk.add(new Laptop(nextId[0]++, "Laptop Ultrabook", 12000000, "Dell", 18, 3, 8, 256, "i5"));
        daftarProduk.add(new Handphone(nextId[0]++, "Smartphone Pro", 8000000, "Samsung", 12, 10, "Android", 108, 5000));
        daftarProduk.add(new Handphone(nextId[0]++, "iPhone 14", 15000000, "Apple", 12, 7, "iOS", 48, 4500));
        daftarProduk.add(new Aksesoris(nextId[0]++, "Headphone BT", 1200000, "Sony", 6, 20, "Headset", "Hitam", "Bluetooth"));

        do {
            System.out.println("\n=== Menu Gerlong Electric ===");
            System.out.println("1. Tambah Produk");
            System.out.println("2. Lihat Semua Produk");
            System.out.println("3. Keluar");
            System.out.print("Pilihan: ");
            menu = sc.nextInt(); sc.nextLine();

            if (menu == 1) tambahProduk(daftarProduk, nextId);
            else if (menu == 2) tampilkanProduk(daftarProduk);
            else if (menu == 3) System.out.println("Keluar...");
            else System.out.println("Pilihan salah!");
        } while (menu != 3);
    }
}