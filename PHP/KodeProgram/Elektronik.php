<?php
// Elektronik.php
require_once 'Produk.php';

abstract class Elektronik extends Produk {
    private $brand;
    private $garansi;
    private $stok;

    public function __construct($id, $nama, $harga, $brand, $garansi, $stok) {
        parent::__construct($id, $nama, $harga);
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
}