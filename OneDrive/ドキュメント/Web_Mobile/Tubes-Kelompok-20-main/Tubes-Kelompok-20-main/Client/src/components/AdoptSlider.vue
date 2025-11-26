<template>
  <div class="adopt-slider">
    <div v-if="loading" class="loading-message">
      Memuat daftar kucing...
    </div>

    <div v-else-if="kittens.length === 0" class="no-data-message">
      Tidak ada data kucing saat ini.
    </div>

    <Swiper
      v-else
      :modules="[Navigation, Pagination]"
      :slides-per-view="3"
      :centered-slides="true"
      :loop="shouldLoop"
      navigation
      pagination
      class="mySwiper"
      @realIndexChange="onRealIndexChange"
      :breakpoints="{
        320: { slidesPerView: 1, spaceBetween: 10 },
        640: { slidesPerView: 2, spaceBetween: 20 },
        1024: { slidesPerView: 3, spaceBetween: 30 }
      }"
    >
      <SwiperSlide
        v-for="kitten in kittens"
        :key="kitten.id"
        class="kitten-slide"
      >
        <div class="kitten-card">
          <img 
            :src="kitten.imageUrl" 
            :alt="kitten.name" 
            @error="$event.target.src = '/images/default.jpg'" 
          />
          <div class="kitten-info">
            <p class="age">{{ kitten.age || 'Usia ?' }}</p>
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
import axios from 'axios';
import { ref, onMounted, computed } from 'vue';
import { useRouter } from 'vue-router';
import { Swiper, SwiperSlide } from 'swiper/vue';
import { Navigation, Pagination } from 'swiper/modules';
import 'swiper/css';
import 'swiper/css/navigation';
import 'swiper/css/pagination';

const router = useRouter();
const currentRealIndex = ref(0);
const kittens = ref([]);
const loading = ref(true);

// URL API Backend
const API_URL = 'http://localhost:5000/api/cats';

// Computed: Hanya aktifkan loop jika jumlah data lebih dari slidesPerView (3)
// Ini mencegah glitch visual pada Swiper
const shouldLoop = computed(() => kittens.value.length > 3);

const fetchKittens = async () => {
  try {
    const response = await axios.get(API_URL);
    
    // Mapping data dari backend
    // Di route.js kamu, backend mengirim: { ..., image_url: "http://localhost:5000/..." }
    kittens.value = response.data.map(cat => ({
      ...cat,
      // Prioritaskan image_url dari backend, jika null pakai default
      imageUrl: cat.image_url || '/images/default.jpg' 
    }));

  } catch (err) {
    console.error("Gagal mengambil data:", err);
  } finally {
    loading.value = false;
  }
};

onMounted(() => {
  fetchKittens();
});

const onRealIndexChange = (swiper) => {
  currentRealIndex.value = swiper.realIndex;
};

const goToAdoptDetail = () => {
  // Pastikan array tidak kosong
  if (kittens.value.length === 0) return;

  const activeKitten = kittens.value[currentRealIndex.value];
  
  if (activeKitten && activeKitten.id) {
    router.push(`/adopt-now/${activeKitten.id}`);
  } else {
    console.warn("Data kitten tidak valid untuk navigasi.");
  }
};
</script>

<style scoped>
/* Pastikan container swiper memiliki lebar pasti */
.adopt-slider {
  width: 100%;
  max-width: 1200px; /* Sesuaikan */
  margin: 0 auto;
  position: relative;
  text-align: center;
  padding: 2rem 0;
}

.loading-message, .no-data-message {
  text-align: center;
  padding: 50px;
  font-size: 1.2rem;
  color: #666;
}

/* Kustomisasi Swiper agar tidak 'gepeng' */
.mySwiper {
  width: 100%;
  padding-bottom: 50px; /* Ruang untuk pagination */
}

.kitten-slide {
  display: flex;
  justify-content: center;
  align-items: center;
  transition: transform 0.3s;
}

/* Efek slide tengah lebih besar (opsional, karena centered-slides=true) */
.swiper-slide-active .kitten-card {
  transform: scale(1.1);
  z-index: 10;
  box-shadow: 0 10px 20px rgba(0,0,0,0.2);
}

.kitten-card {
  background: white;
  border-radius: 15px;
  overflow: hidden;
  width: 250px; /* Lebar kartu fix */
  height: 350px;
  box-shadow: 0 4px 6px rgba(0,0,0,0.1);
  transition: all 0.3s ease;
  position: relative;
}

.kitten-card img {
  width: 100%;
  height: 70%;
  object-fit: cover;
}

.kitten-info {
  padding: 1rem;
  text-align: left;
}

.kitten-info .age {
  font-size: 0.9rem;
  color: #888;
  margin-bottom: 0.2rem;
}

.kitten-info .name {
  font-size: 1.2rem;
  font-weight: bold;
  color: #333;
}

.title {
  font-family: 'Poppins', sans-serif; /* Sesuaikan font kamu */
  font-size: 2rem;
  font-weight: 800;
  margin: 2rem 0 1rem;
  color: #333;
}

.cat-button {
  background: none;
  border: none;
  cursor: pointer;
  transition: transform 0.2s;
}

.cat-button:hover {
  transform: scale(1.05);
}

.cat-button img {
  width: 150px; /* Sesuaikan ukuran tombol gambar */
}

.more-button-container {
  margin-top: 1rem;
}

.see-more-btn {
  text-decoration: none;
  color: #666;
  font-weight: 600;
  border-bottom: 2px solid transparent;
  transition: border-color 0.3s;
}

.see-more-btn:hover {
  border-color: #FCD34D; /* Warna kuning */
  color: #333;
}
</style>