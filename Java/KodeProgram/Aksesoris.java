// Aksesoris.java
// Berisi definisi class Aksesoris, turunan dari Elektronik.
class Aksesoris extends Elektronik {
    private String jenis;
    private String warna;
    private String compatibility;

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