<?php
// Handphone.php
require_once 'Elektronik.php';

class Handphone extends Elektronik {
    private $os;
    private $camera;
    private $battery;
    private $foto_produk; // Atribut khusus PHP

    public function __construct($id, $nama, $harga, $brand, $garansi, $stok, $os, $camera, $battery, $foto_produk) {
        parent::__construct($id, $nama, $harga, $brand, $garansi, $stok);
        $this->os = $os;
        $this->camera = $camera;
        $this->battery = $battery;
        $this->foto_produk = $foto_produk;
    }

    public function getKategori() {
        return "Handphone";
    }

    public function getDetail() {
        return "OS:{$this->os}, Camera:{$this->camera}MP, {$this->battery}mAh";
    }
    
    public function getFotoProduk() {
        return $this->foto_produk;
    }
}