<template>
  <div class="adopt-slider">
    <div v-if="loading" class="loading-message">
      Memuat daftar hewan peliharaan...
    </div>
    <div v-else-if="kittens.length === 0" class="no-data-message">
      Tidak ada data hewan peliharaan yang ditemukan. Pastikan API Server (port 5000) berjalan dan database terisi.
    </div>

    <Swiper
      v-else
      :modules="[Navigation, Pagination]"
      :slides-per-view="3"
      :centered-slides="true"
      :loop="true"
      navigation
      pagination
      class="mySwiper"
      @realIndexChange="onRealIndexChange"
    >
      <SwiperSlide
        v-for="kitten in kittens"
        :key="kitten.id" 
        class="kitten-slide"
      >
        <div class="kitten-card">
          <img :src="kitten.image || '/images/default.jpg'" :alt="kitten.name" />
          <div class="kitten-info">
            <p class="age">{{ kitten.age || 'Usia tidak diketahui' }}</p>
            <h3 class="name">{{ kitten.name }}</h3>
          </div>
        </div>
      </SwiperSlide>
    </Swiper>

    <h2 class="title">ADOPT UR KITTEN HERE</h2>
    
    <button class="cat-button" @click="goToAdoptDetail">
      <img src="/images/home/cat-button.png" alt="adopt-now" />
    </button>

    <div class="more-button-container">
      <RouterLink to="/adoption" class="see-more-btn">
        Lihat Lainnya
      </RouterLink>
    </div>
  </div>
</template>

<script setup>
import axios from 'axios'; // 👈 Tambahkan
import { ref, onMounted } from 'vue'; // 👈 Tambahkan onMounted
import { useRouter } from 'vue-router';
import { Swiper, SwiperSlide } from 'swiper/vue';
import { Navigation, Pagination } from 'swiper/modules';

// Import style Swiper
import 'swiper/css';
import 'swiper/css/navigation';
import 'swiper/css/pagination';

const router = useRouter();
const currentRealIndex = ref(0); 

// Data yang akan diisi dari API
const kittens = ref([]); // 👈 Ubah menjadi ref dan kosong
const loading = ref(true); // 👈 Tambahkan state loading
const API_URL = 'http://localhost:5000/api/cats'; // 👈 Endpoint API Anda

// Fungsi untuk mengambil data dari Backend
const fetchKittens = async () => {
    try {
        const response = await axios.get(API_URL); 
        // Asumsi data yang dikembalikan berupa array
        kittens.value = response.data; 
    } catch (error) {
        console.error("Gagal mengambil data dari server:", error);
        // Bisa tambahkan logika untuk menampilkan pesan error di UI
    } finally {
        loading.value = false;
    }
};

// Panggil fungsi saat komponen selesai di-mount
onMounted(() => {
    fetchKittens();
});

// Event handler saat slide berubah (loop-compatible)
const onRealIndexChange = (swiper) => {
  currentRealIndex.value = swiper.realIndex;
};

// Fungsi navigasi dinamis ke halaman detail
const goToAdoptDetail = () => {
  // Ambil ID dari data aktif yang sudah diambil dari API
  const activeKitten = kittens.value[currentRealIndex.value]; 
  
  if (activeKitten && activeKitten.id) {
    // Navigasi ke route detail dengan ID yang valid
    router.push(`/adopt-now/${activeKitten.id}`);
  } else {
    console.error("Data kitten tidak ditemukan atau ID tidak valid.");
  }
};
</script>

<style scoped>
/* Semua styling CSS Anda tetap sama */
.adopt-slider {
  text-align: center;
  background: #f7f1e8;
  padding: 40px 0;
}
.mySwiper {
  width: 100%;
  max-width: 900px;
  margin: 0 auto;
  padding-bottom: 50px;
}

/* posisi slide tetap seimbang */
.swiper-slide {
  display: flex;
  justify-content: center;
  transition: all 0.3s ease;
}

/* ukuran dan efek skala */
.kitten-slide {
  transform: scale(0.8);
  opacity: 0.6;
  transition: transform 0.4s ease, opacity 0.4s ease;
}

.swiper-slide-active {
  transform: scale(1.15);
  opacity: 1;
  z-index: 2;
}

.swiper-slide-prev,
.swiper-slide-next {
  transform: scale(0.9);
  opacity: 0.8;
  z-index: 1;
}

/* gaya kartu kitten */
.kitten-card {
  background: white;
  border-radius: 20px;
  overflow: hidden;
  box-shadow: 0 10px 25px rgba(0, 0, 0, 0.1);
  text-align: center;
  width: 200px;
  height: 240px;
}

.kitten-card img {
  width: 100%;
  height: 180px;
  object-fit: cover;
}

.kitten-info {
  padding: 10px 0;
}

.kitten-info .age {
  font-size: 12px;
  color: #555;
  margin: 0;
}

.kitten-info .name {
  font-size: 18px;
  font-weight: bold;
  margin: 0;
}

.title {
  font-size: 28px;
  font-weight: 800;
  margin-top: 30px;
}

.cat-button {
  background: transparent;
  border: none;
  padding: 0;
  margin-top: 10px;
  cursor: pointer;
  transition: transform 0.2s ease, opacity 0.2s ease;
}

.cat-button img {
  /* Atur ukuran gambar tombol di sini */
  width: 80px; 
  height: auto;
}

.cat-button:hover {
  transform: scale(1.1); /* Efek hover membesar */
  opacity: 0.9;
}

.more-button-container {
  margin-top: 20px;
  text-align: center;
}

.see-more-btn {
  display: inline-block;
  background-color: #ED8B3C;
  color: white;
  padding: 12px 40px;
  border-radius: 9999px;
  text-decoration: none;
  font-weight: 700;
  transition: all 0.3s ease;
}

.see-more-btn:hover {
  background-color: #d97a2b; /* Warna sedikit lebih gelap saat di-hover */
  transform: translateY(-3px); /* Tombol naik sedikit saat di-hover */
  box-shadow: 0 6px 12px rgba(237, 139, 60, 0.4); /* Bayangan lebih tegas saat hover */
}

.see-more-btn:active {
  transform: translateY(-1px); /* Efek tekan saat diklik */
  box-shadow: 0 2px 4px rgba(237, 139, 60, 0.3);
}

</style>