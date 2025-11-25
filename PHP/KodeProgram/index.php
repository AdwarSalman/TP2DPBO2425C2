<?php
session_start();

// ==================== CLASS ====================
abstract class Produk {
    protected $nama;
    protected $harga;
    protected $foto;

    public function __construct($nama, $harga, $foto) {
        $this->nama = $nama;
        $this->harga = $harga;
        $this->foto = $foto;
    }

    public function getNama() {
        return $this->nama;
    }

    public function getHarga() {
        return $this->harga;
    }

    public function getFoto() {
        return $this->foto;
    }

    abstract public function getInfo();
}

class Elektronik extends Produk {
    protected $brand;
    protected $garansi;
    protected $stok;

    public function __construct($nama, $harga, $foto, $brand, $garansi, $stok) {
        parent::__construct($nama, $harga, $foto);
        $this->brand = $brand;
        $this->garansi = $garansi;
        $this->stok = $stok;
    }

    public function getBrand() {
        return $this->brand;
    }

    public function getGaransi() {
        return $this->garansi;
    }

    public function getStok() {
        return $this->stok;
    }

    public function getInfo() {
        return "Brand: {$this->brand}, Garansi: {$this->garansi} bulan, Stok: {$this->stok}";
    }
}

class Laptop extends Elektronik {
    private $processor;

    public function __construct($nama, $harga, $foto, $brand, $garansi, $stok, $processor) {
        parent::__construct($nama, $harga, $foto, $brand, $garansi, $stok);
        $this->processor = $processor;
    }

    public function getInfo() {
        return parent::getInfo() . ", Processor: {$this->processor}";
    }
}

class Handphone extends Elektronik {
    private $ram;

    public function __construct($nama, $harga, $foto, $brand, $garansi, $stok, $ram) {
        parent::__construct($nama, $harga, $foto, $brand, $garansi, $stok);
        $this->ram = $ram;
    }

    public function getInfo() {
        return parent::getInfo() . ", RAM: {$this->ram} GB";
    }
}

// ==================== DATA DEFAULT ====================
if (!isset($_SESSION['produk_list'])) {
    $_SESSION['produk_list'] = [
        new Laptop("Laptop A", 7000000, "foto1.jpg", "Asus", 24, 10, "Intel i5"),
        new Laptop("Laptop B", 9000000, "foto2.jpg", "Acer", 12, 5, "Intel i7"),
        new Handphone("HP X", 5000000, "foto3.jpg", "Samsung", 12, 20, 8),
        new Handphone("HP Y", 3000000, "foto4.jpg", "Xiaomi", 6, 15, 6),
        new Handphone("HP Z", 10000000, "foto5.jpg", "Apple", 24, 8, 12)
    ];
}

// ==================== HANDLE FORM ====================
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nama = $_POST['nama'];
    $harga = $_POST['harga'];
    $brand = $_POST['brand'];
    $garansi = $_POST['garansi'];
    $stok = $_POST['stok'];
    $kategori = $_POST['kategori'];

    // --- Handle file upload ---
    $foto = "default.jpg"; // fallback
    if (isset($_FILES['foto']) && $_FILES['foto']['error'] == 0) {
        $target_dir = "img/";
        $foto = basename($_FILES["foto"]["name"]);
        $target_file = $target_dir . $foto;
        move_uploaded_file($_FILES["foto"]["tmp_name"], $target_file);
    }

    if ($kategori === "Laptop") {
        $processor = $_POST['processor'];
        $produk_baru = new Laptop($nama, $harga, $foto, $brand, $garansi, $stok, $processor);
    } elseif ($kategori === "Handphone") {
        $ram = $_POST['ram'];
        $produk_baru = new Handphone($nama, $harga, $foto, $brand, $garansi, $stok, $ram);
    }

    $_SESSION['produk_list'][] = $produk_baru;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Toko Elektronik</title>
</head>
<body>
    <h2>Tambah Produk</h2>
    <!-- enctype wajib biar bisa upload file -->
    <form method="post" enctype="multipart/form-data">
        Nama: <input type="text" name="nama" required><br>
        Harga: <input type="number" name="harga" required><br>
        Foto: <input type="file" name="foto" accept="image/*"><br>
        Brand: <input type="text" name="brand" required><br>
        Garansi (bulan): <input type="number" name="garansi" required><br>
        Stok: <input type="number" name="stok" required><br>
        Kategori:
        <select name="kategori" required>
            <option value="Laptop">Laptop</option>
            <option value="Handphone">Handphone</option>
        </select><br>
        Processor (untuk Laptop): <input type="text" name="processor"><br>
        RAM (untuk Handphone): <input type="number" name="ram"><br>
        <button type="submit">Tambah</button>
    </form>

    <h2>Daftar Produk</h2>
    <table border="1" cellpadding="10">
        <tr>
            <th>Foto</th>
            <th>Nama</th>
            <th>Harga</th>
            <th>Info</th>
        </tr>
        <?php foreach ($_SESSION['produk_list'] as $produk): ?>
        <tr>
            <td><img src="img/<?php echo $produk->getFoto(); ?>" width="100"></td>
            <td><?php echo $produk->getNama(); ?></td>
            <td>Rp <?php echo number_format($produk->getHarga(), 0, ',', '.'); ?></td>
            <td><?php echo $produk->getInfo(); ?></td>
        </tr>
        <?php endforeach; ?>
    </table>
</body>
</html>
