// Elektronik.java
// Berisi definisi class abstrak Elektronik, turunan dari Produk.
abstract class Elektronik extends Produk {
    private String brand;
    private int garansi;
    private int stok;

    public Elektronik(int id, String nama, double harga,
                      String brand, int garansi, int stok) {
        super(id, nama, harga);
        this.brand = brand;
        this.garansi = garansi;
        this.stok = stok;
    }

    public String getBrand() { return brand; }
    public int getGaransi() { return garansi; }
    public int getStok() { return stok; }
}