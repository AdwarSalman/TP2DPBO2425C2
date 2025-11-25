// Produk.java
// Berisi definisi class dasar abstrak Produk.
abstract class Produk {
    private int id;
    private String nama;
    private double harga;

    public Produk(int id, String nama, double harga) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
    }

    public int getId() { return id; }
    public String getNama() { return nama; }
    public double getHarga() { return harga; }

    public abstract String getKategori();
    public abstract String getDetail();
}