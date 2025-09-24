<?php
// Aksesoris.php
require_once 'Elektronik.php';

class Aksesoris extends Elektronik {
    private $jenis;
    private $warna;
    private $compatibility;
    private $foto_produk; // Atribut khusus PHP

    public function __construct($id, $nama, $harga, $brand, $garansi, $stok, $jenis, $warna, $compatibility, $foto_produk) {
        parent::__construct($id, $nama, $harga, $brand, $garansi, $stok);
        $this->jenis = $jenis;
        $this->warna = $warna;
        $this->compatibility = $compatibility;
        $this->foto_produk = $foto_produk;
    }

    public function getKategori() {
        return "Aksesoris";
    }

    public function getDetail() {
        return "Jenis:{$this->jenis}, Warna:{$this->warna}, {$this->compatibility}";
    }
    
    public function getFotoProduk() {
        return $this->foto_produk;
    }
}