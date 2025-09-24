// Handphone.java
// Berisi definisi class Handphone, turunan dari Elektronik.
class Handphone extends Elektronik {
    private String os;
    private int camera;
    private int battery;

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