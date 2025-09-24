<?php
// Laptop.php
require_once 'Elektronik.php';

class Laptop extends Elektronik {
    private $ram;
    private $storage;
    private $processor;
    private $foto_produk; // Atribut khusus PHP

    public function __construct($id, $nama, $harga, $brand, $garansi, $stok, $ram, $storage, $processor, $foto_produk) {
        parent::__construct($id, $nama, $harga, $brand, $garansi, $stok);
        $this->ram = $ram;
        $this->storage = $storage;
        $this->processor = $processor;
        $this->foto_produk = $foto_produk;
    }

    public function getKategori() {
        return "Laptop";
    }

    public function getDetail() {
        return "RAM:{$this->ram}GB, Storage:{$this->storage}GB, {$this->processor}";
    }
    
    public function getFotoProduk() {
        return $this->foto_produk;
    }
}