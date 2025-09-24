JANJI
Saya Muhammad Adwar Salman dengan NIM 2401539 mengerjakan Tugas Praktikum 2 dalam mata kuliah Desain Pemrograman Berbasis Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

🏗️ Desain Diagram Kelas

Penjelasan Class, Atribut, dan Methods
1. Class Produk (abstract)
Atribut:
id : int
nama : String
harga : double
Method:
getId()
getNama()
getHarga()
getDetail() → abstract, wajib dioverride di subclass.

2. Class Elektronik (extends Produk)
Atribut tambahan:
brand : String
garansi : int
stok : int
Method:
getBrand()
getGaransi()
getStok()
getDetail() → override abstract method.

3. Class Laptop (extends Elektronik)
Atribut tambahan:
ram : int
storage : int
processor : String
Method:
getDetail() → menampilkan kombinasi spesifikasi laptop.

4. Class Handphone (extends Elektronik)

Atribut tambahan:
os : String
camera : int
battery : int
Method:
getDetail() → menampilkan OS, kamera, dan kapasitas baterai.

5. Class Aksesoris (extends Elektronik)
Atribut tambahan:
jenis : String
warna : String
compatibility : String
Method:
getDetail() → menampilkan jenis, warna, dan kompatibilitas.

6. Class GerlongElectric (main program)

Method utama:

main() → menjalankan menu utama.

tambahProduk() → input produk baru sesuai kategori.

tampilkanProduk() → menampilkan semua produk dalam tabel.

printSeparator() → membantu format tabel.

Saya mendesain OOP dengan model multilevel inheritance, dengan penjelasan sebagai berikut
Pertama, pada class Produk saya menjadikannya sebagai base class (induk paling atas), yang berisi atribut umum dari setiap produk seperti id, nama, dan harga. Semua barang elektronik tentu saja merupakan produk, sehingga Produk menjadi dasar utama dari semua turunan.

Kedua, terdapat class Elektronik yang menjadi anak dari Produk (intermediary class). Di sini, saya menambahkan atribut yang lebih spesifik untuk barang elektronik, seperti brand, garansi, dan stok. Elektronik diposisikan sebagai penghubung karena semua Laptop, Handphone, dan Aksesoris pasti merupakan bagian dari Elektronik, dan otomatis juga merupakan Produk.

Ketiga, terdapat class Laptop, Handphone, dan Aksesoris yang menjadi cucu dari Produk sekaligus anak dari Elektronik (derived class).

Pada Laptop, ditambahkan atribut ram, storage, dan processor yang mendefinisikan spesifikasi laptop.
Pada Handphone, ditambahkan atribut os, camera, dan battery yang sesuai dengan karakteristik handphone.
Pada Aksesoris, ditambahkan atribut jenis, warna, dan compatibility yang merepresentasikan aksesoris pendukung perangkat elektronik.
Dengan model ini, setiap subclass bisa mewarisi atribut dan method dari atasnya, tetapi juga menambahkan detail khusus sesuai dengan kategori produknya.

<img width="851" height="689" alt="Screenshot 2025-09-24 233249" src="https://github.com/user-attachments/assets/cd33b65e-dacf-40ab-ba99-02eaeb82afeb" />

🔄 Alur Program

Inisialisasi produk default → beberapa laptop, handphone, dan aksesoris dimasukkan ke dalam ArrayList.

Menu utama:

1. Tambah Produk → user memilih kategori produk (Laptop, Handphone, Aksesoris), lalu mengisi atribut sesuai kategori. Objek baru ditambahkan ke list.

2. Lihat Semua Produk → menampilkan data produk dalam bentuk tabel rapi.

3. Keluar → program berhenti.

Looping menu berlangsung hingga user memilih keluar.

📷 Dokumentasi Program
CPP

<img width="1362" height="829" alt="Screenshot 2025-09-24 231851" src="https://github.com/user-attachments/assets/81ea4201-6c88-4942-a8ad-8c7fd2d7684f" />


Java

<img width="1416" height="822" alt="Screenshot 2025-09-24 232244" src="https://github.com/user-attachments/assets/8f6a93b5-ea5d-4c85-9e2d-94b79a25fa63" />


Python

<img width="1416" height="822" alt="Screenshot 2025-09-24 232244" src="https://github.com/user-attachments/assets/4d448a76-382c-450f-9889-898b2fb19a42" />

PHP

<img width="1919" height="704" alt="image" src="https://github.com/user-attachments/assets/d54eae36-3a6d-472d-8339-dc8a2de1e47a" />
