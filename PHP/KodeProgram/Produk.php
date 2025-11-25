<?php
// Produk.php
abstract class Produk {
    private $id;
    private $nama;
    private $harga;

    public function __construct($id, $nama, $harga) {
        $this->id = $id;
        $this->nama = $nama;
        $this->harga = $harga;
    }

    public function getId() {
        return $this->id;
    }

    public function getNama() {
        return $this->nama;
    }

    public function getHarga() {
        return $this->harga;
    }

    abstract public function getKategori();
    abstract public function getDetail();
}