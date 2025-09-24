// Laptop.java
// Berisi definisi class Laptop, turunan dari Elektronik.
class Laptop extends Elektronik {
    private int ram;
    private int storage;
    private String processor;

    public Laptop(int id, String nama, double harga,
                  String brand, int garansi, int stok,
                  int ram, int storage, String processor) {
        super(id, nama, harga, brand, garansi, stok);
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