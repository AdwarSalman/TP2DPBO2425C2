<template>
  <main class="min-h-screen bg-white p-6 flex flex-col items-center pb-20 mt-10">
    
    <header class="w-full max-w-sm flex flex-col items-center pt-8 pb-6">
      <h1 class="text-4xl font-extrabold text-[#3a2f1c] mb-2" style="font-family: 'Handwriting Font', cursive;">
        Kelompok 20
      </h1>
      <div class="flex flex-col items-center">
        <ol>
          <li class="text-xl font-medium text-gray-700 mb-3">
          Muhammad Adwar Salman - 2401539  
          </li>
          <li class="text-xl font-medium text-gray-700 mb-3">
          Yassar Muwaffaq - 2410896  
          </li>
          <li class="text-xl font-medium text-gray-700 mb-3">
          Firda Ridzki Utami - 2401626  
          </li>
          <li class="text-xl font-medium text-gray-700 mb-3">
          Ervina Kusnanda - 2409082  
          </li>
        </ol>
        <div class="flex space-x-4 text-gray-600">
          <a href="#" target="_blank" aria-label="Facebook">
            <svg class="w-7 h-7 hover:text-gray-900 transition" fill="currentColor" viewBox="0 0 24 24"><path d="M14 11h2.5l-.5-3H14V6c0-.6.4-1 1-1h2V.5h-3C8.96 1.48 9 5.09 9 5.5v2.5H6.5v3H9v8.5h4.5V11H14z"/></svg>
          </a>
          <a href="#" target="_blank" aria-label="YouTube">
            <svg class="w-7 h-7 hover:text-gray-900 transition" fill="currentColor" viewBox="0 0 24 24"><path d="M21.5 6.5a4.3 4.3 0 00-4.3-4.3H6.8A4.3 4.3 0 002.5 6.5v11A4.3 4.3 0 006.8 21.8h10.4A4.3 4.3 0 0021.5 17.5v-11zM9.5 16.5v-9L16 12l-6.5 4.5z"/></svg>
          </a>
          <a href="#" target="_blank" aria-label="TikTok">
            <svg class="w-7 h-7 hover:text-gray-900 transition" fill="currentColor" viewBox="0 0 24 24"><path d="M19.5 2h-15C2.5 2 1 3.5 1 5.5v13C1 20.5 2.5 22 4.5 22h15c2 0 3.5-1.5 3.5-3.5v-13C23 3.5 21.5 2 19.5 2zm-4 13.5v-7h-1.5v7h1.5zM12 15.5v-7H8.5v7H12zM5.5 15.5v-7H4v7h1.5zM19.5 8h-1.5V6h1.5v2zM19.5 15.5h-1.5v-5h1.5v5zM15.5 6h-1.5V4h1.5v2zM12 6h-1.5V4H12v2zM8.5 6H7V4h1.5v2z"/></svg>
          </a>
        </div>
      </div>
    </header>

    <div class="w-full max-w-md space-y-4">
      <div v-for="link in links" :key="link.id" class="relative">
        <a
          :href="link.url"
          target="_blank"
          class="flex items-center w-full p-4 bg-white border border-gray-200 rounded-xl shadow-md hover:shadow-lg transition duration-300 relative overflow-hidden"
          :class="{
            'h-20': link.type === 'featured',
            'h-14': link.type === 'regular'
          }"
          :style="linkStyle(link.type)"
          @click="trackClick(link.id)"
        >
          <img v-if="link.image" :src="link.image" :alt="link.text" class="w-12 h-12 object-cover rounded-md mr-4 flex-shrink-0" />
          
          <div v-else class="w-12 h-12 flex items-center justify-center rounded-md mr-4 flex-shrink-0 text-white font-bold text-xl bg-gray-400">
            {{ link.text.substring(0, 2).toUpperCase() }}
          </div>
          
          <span class="text-gray-700 font-semibold text-center flex-grow truncate">
            {{ link.text }}
          </span>
          
          <svg class="w-5 h-5 text-gray-400 ml-auto" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 12h.01M12 12h.01M19 12h.01M6 12a1 1 0 11-2 0 1 1 0 012 0zm7 0a1 1 0 11-2 0 1 1 0 012 0zm7 0a1 1 0 11-2 0 1 1 0 012 0z" />
          </svg>
        </a>
      </div>
    </div>
  </main>

  <nav class="fixed bottom-0 left-0 right-0 z-50 bg-white shadow-2xl border-t border-gray-100">
    <div class="max-w-xl mx-auto flex justify-around items-center h-16 sm:h-20 px-4">
      <a 
        v-for="item in navItems" 
        :key="item.name" 
        :href="item.route" 
        class="flex flex-col items-center justify-center p-2 text-gray-500 hover:text-gray-900 transition-colors"
      >
        <svg class="w-6 h-6 sm:w-7 sm:h-7" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" :d="item.iconPath" />
        </svg>
        <span class="text-xs font-medium mt-1 hidden sm:block">{{ item.name }}</span>
      </a>
    </div>
  </nav>
</template>

<script setup>
import { ref } from 'vue';

const links = ref([
  // Data Tautan (dibiarkan sama)
  { 
    id: 1, 
    text: 'Landing Page', 
    url: '/', 
    type: 'featured', 
  },
  { 
    id: 2, 
    text: 'Adoption Page', 
    url: '/adoption', 
    type: 'regular', 
    image: '' 
  },
  { 
    id: 3, 
    text: 'Donate Page', 
    url: '/donate', 
    type: 'regular', 
    image: '' 
  },
  { 
    id: 4, 
    text: 'Adoptable Cats', 
    url: '/adopt-now/1', 
    type: 'regular', 
  },
  { 
    id: 5, 
    text: 'Dashboard Admin', 
    url: '/dashboard', 
    type: 'regular', 
  },
  { 
    id: 6, 
    text: 'Report & Rescue', 
    url: '/report-rescue', 
    type: 'regular', 
  },
  { 
    id: 7, 
    text: 'News & Articles', 
    url: '/news', 
    type: 'regular', 
  },
  { 
    id: 8, 
    text: 'Profile Page', 
    url: '/news', 
    type: 'regular', 
  },
  { 
    id: 9, 
    text: 'Terms and Conditions', 
    url: '/terms', 
    type: 'regular', 
  },
  { 
    id: 10, 
    text: 'Login Page', 
    url: '/login', 
    type: 'regular', 
  },
  { 
    id: 10, 
    text: 'Sign Up Page', 
    url: '/signup', 
    type: 'regular', 
  },
]);

// Data untuk Tombol Navigasi Bawah

const linkStyle = (type) => {
  if (type === 'featured') {
    return {
      backgroundColor: '#f9f9f9',
      border: '2px solid #3a2f1c',
    };
  }
  return {};
};

const trackClick = (id) => {
  console.log(`Link ID ${id} clicked.`);
};
</script>

<style scoped>
/* Pastikan body/main container memiliki padding di bawah agar konten tidak tertutup nav bar */
.pb-20 {
    padding-bottom: 5rem; /* Memberi ruang di bagian bawah (sesuai tinggi nav bar) */
}

/* Kustomisasi font (jika diperlukan) */
/* Contoh:
.font-extrabold {
    font-family: 'Handwriting Font', cursive;
}
*/
</style>