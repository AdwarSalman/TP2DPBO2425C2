// Produk.java
// Berisi definisi semua class produk yang digunakan dalam program
// Mulai dari class dasar (Produk), class abstrak Elektronik, hingga turunan konkret
// Laptop, Handphone, dan Aksesoris

// =============================
// Base Class: Produk
// =============================
// Produk adalah class abstrak yang berisi atribut dasar yang pasti dimiliki semua produk.
// Class ini tidak bisa di-instantiate langsung, tapi diwariskan oleh class lain.
abstract class Produk {
    // Atribut umum
    protected int id;        // ID unik produk
    protected String nama;   // Nama produk
    protected double harga;  // Harga produk

    // Konstruktor
    public Produk(int id, String nama, double harga) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
    }

    // Getter untuk mengakses atribut privat/protected
    public int getId() { return id; }
    public String getNama() { return nama; }
    public double getHarga() { return harga; }

    // Method abstrak → harus diimplementasi oleh child class
    public abstract String getKategori(); // Mengembalikan kategori produk
    public abstract String getDetail();   // Mengembalikan detail khusus produk
}

// =============================
// Turunan Level 2: Elektronik
// =============================
// Class Elektronik adalah turunan dari Produk. 
// Semua produk elektronik punya brand, garansi, dan stok.
abstract class Elektronik extends Produk {
    protected String brand;  // Merk produk
    protected int garansi;   // Lama garansi dalam bulan
    protected int stok;      // Jumlah stok yang tersedia

    // Konstruktor memanggil konstruktor Produk dengan super()
    public Elektronik(int id, String nama, double harga,
                      String brand, int garansi, int stok) {
        super(id, nama, harga); // memanggil konstruktor Produk
        this.brand = brand;
        this.garansi = garansi;
        this.stok = stok;
    }

    // Getter
    public String getBrand() { return brand; }
    public int getGaransi() { return garansi; }
    public int getStok() { return stok; }
}

// =============================
// Turunan Level 3: Laptop
// =============================
// Laptop adalah turunan dari Elektronik.
// Laptop memiliki atribut tambahan: RAM, Storage, dan Processor.
class Laptop extends Elektronik {
    private int ram;        // RAM dalam GB
    private int storage;    // Storage dalam GB
    private String processor; // Nama processor

    public Laptop(int id, String nama, double harga,
                  String brand, int garansi, int stok,
                  int ram, int storage, String processor) {
        super(id, nama, harga, brand, garansi, stok); // memanggil konstruktor Elektronik
        this.ram = ram;
        this.storage = storage;
        this.processor = processor;
    }

    @Override
    public String getKategori() { return "Laptop"; }

    @Override
    public String getDetail() {
        return "RAM:" + ram + "GB, Storage:" + storage + "GB, " + processor;
    }
}

// =============================
// Turunan Level 3: Handphone
// =============================
// Handphone juga turunan dari Elektronik.
// Atribut tambahannya adalah OS, Kamera, dan Baterai.
class Handphone extends Elektronik {
    private String os;     // Sistem operasi (Android/iOS)
    private int camera;    // Resolusi kamera dalam MP
    private int battery;   // Kapasitas baterai dalam mAh

    public Handphone(int id, String nama, double harga,
                     String brand, int garansi, int stok,
                     String os, int camera, int battery) {
        super(id, nama, harga, brand, garansi, stok);
        this.os = os;
        this.camera = camera;
        this.battery = battery;
    }

    @Override
    public String getKategori() { return "Handphone"; }

    @Override
    public String getDetail() {
        return "OS:" + os + ", Camera:" + camera + "MP, " + battery + "mAh";
    }
}

// =============================
// Turunan Level 3: Aksesoris
// =============================
// Aksesoris adalah elektronik tambahan seperti headphone, charger, dll.
// Atribut tambahannya adalah Jenis, Warna, dan Compatibility.
class Aksesoris extends Elektronik {
    private String jenis;        // Jenis aksesoris (Headset, Charger, dll.)
    private String warna;        // Warna produk
    private String compatibility; // Kompatibilitas (contoh: Bluetooth, USB-C)

    public Aksesoris(int id, String nama, double harga,
                     String brand, int garansi, int stok,
                     String jenis, String warna, String compatibility) {
        super(id, nama, harga, brand, garansi, stok);
        this.jenis = jenis;
        this.warna = warna;
        this.compatibility = compatibility;
    }

    @Override
    public String getKategori() { return "Aksesoris"; }

    @Override
    public String getDetail() {
        return "Jenis:" + jenis + ", Warna:" + warna + ", " + compatibility;
    }
}
