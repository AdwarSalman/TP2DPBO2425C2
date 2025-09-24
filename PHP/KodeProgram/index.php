<?php
session_start();

// kosongkan session jika rusak
if (!isset($_SESSION['produk'])) {
    $_SESSION['produk'] = [];
}

// load semua class
require_once 'Aksesoris.php';
require_once 'Laptop.php';
require_once 'Handphone.php';

// tambah produk default (hanya sekali)
if (empty($_SESSION['produk'])) {
    $_SESSION['produk'][] = new Aksesoris(1, "Headset Gaming", 250000, "Rexus", 12, 10, "Headset", "Hitam", "PC/HP", "foto1.jpg");
    $_SESSION['produk'][] = new Aksesoris(2, "Mouse Wireless", 150000, "Logitech", 12, 20, "Mouse", "Putih", "Laptop/PC", "foto2.jpg");
    $_SESSION['produk'][] = new Laptop(3, "ASUS ROG", 15000000, "ASUS", 24, 5, "Intel i7", "16GB", "512GB SSD", "foto3.jpg");
    $_SESSION['produk'][] = new Handphone(4, "Samsung Galaxy S23", 12000000, "Samsung", 12, 15, "Android", "6.1\"", "128GB", "foto4.jpg");
    $_SESSION['produk'][] = new Handphone(5, "iPhone 14", 18000000, "Apple", 12, 8, "iOS", "6.1\"", "256GB", "foto5.jpg");
}

// handle tambah produk
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $kategori = $_POST['kategori'];

    if ($kategori === "Aksesoris") {
        $produk = new Aksesoris(
            count($_SESSION['produk']) + 1,
            $_POST['nama'],
            $_POST['harga'],
            $_POST['brand'],
            $_POST['garansi'],
            $_POST['stok'],
            $_POST['jenis'],
            $_POST['warna'],
            $_POST['compatibility'],
            $_POST['foto']
        );
        $_SESSION['produk'][] = $produk;
    }
    elseif ($kategori === "Laptop") {
        $produk = new Laptop(
            count($_SESSION['produk']) + 1,
            $_POST['nama'],
            $_POST['harga'],
            $_POST['brand'],
            $_POST['garansi'],
            $_POST['stok'],
            $_POST['prosesor'],
            $_POST['ram'],
            $_POST['storage'],
            $_POST['foto']
        );
        $_SESSION['produk'][] = $produk;
    }
    elseif ($kategori === "Handphone") {
        $produk = new Handphone(
            count($_SESSION['produk']) + 1,
            $_POST['nama'],
            $_POST['harga'],
            $_POST['brand'],
            $_POST['garansi'],
            $_POST['stok'],
            $_POST['os'],
            $_POST['layar'],
            $_POST['storage'],
            $_POST['foto']
        );
        $_SESSION['produk'][] = $produk;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Toko Elektronik</title>
</head>
<body>
    <h1>Daftar Produk</h1>
    <?php foreach ($_SESSION['produk'] as $p): ?>
        <div style="border:1px solid #ccc; padding:10px; margin:10px;">
            <img src="img/<?= $p->getFotoProduk() ?>" width="100"><br>
            <strong><?= $p->getKategori() ?> - <?= $p->getNama() ?></strong><br>
            Harga: Rp<?= number_format($p->getHarga(),0,',','.') ?><br>
            Brand: <?= $p->getBrand() ?><br>
            Detail: <?= $p->getDetail() ?><br>
        </div>
    <?php endforeach; ?>

    <h2>Tambah Produk</h2>
    <form method="post">
        Kategori:
        <select name="kategori">
            <option value="Aksesoris">Aksesoris</option>
            <option value="Laptop">Laptop</option>
            <option value="Smartphone">Smartphone</option>
        </select><br><br>

        Nama: <input type="text" name="nama"><br>
        Harga: <input type="number" name="harga"><br>
        Brand: <input type="text" name="brand"><br>
        Garansi (bulan): <input type="number" name="garansi"><br>
        Stok: <input type="number" name="stok"><br>
        Foto: <input type="text" name="foto" placeholder="fotoX.jpg"><br><br>

        <!-- Field khusus Aksesoris -->
        Jenis: <input type="text" name="jenis"><br>
        Warna: <input type="text" name="warna"><br>
        Compatibility: <input type="text" name="compatibility"><br><br>

        <!-- Field khusus Laptop -->
        Prosesor: <input type="text" name="prosesor"><br>
        RAM: <input type="text" name="ram"><br>
        Storage: <input type="text" name="storage"><br><br>

        <!-- Field khusus Smartphone -->
        OS: <input type="text" name="os"><br>
        Layar: <input type="text" name="layar"><br>
        Storage (HP): <input type="text" name="storage"><br><br>

        <button type="submit">Tambah</button>
    </form>
</body>
</html>
