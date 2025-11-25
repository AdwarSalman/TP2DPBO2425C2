<template>
  <header
    :class="[ 
      'fixed top-0 left-0 w-full z-50 transition-all duration-500 ease-in-out bg-white/30 backdrop-blur-xl border-b border-white/20 shadow-sm',
      scrolledDown ? 'translate-y-0' : '-translate-y-full'
    ]"
  >
    <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
      <div class="flex justify-between items-center h-16">
        
        <!-- Brand -->
        <router-link to="/" class="flex items-center space-x-2">
          <img
            src="/images/navbar/logoKucing.png"
            alt="Logo"
            class="h-10 w-10 rounded-full bg-gray-200 object-contain"
          />
          <span class="text-xl font-semibold text-gray-800 leading-none">Adopt Center</span>
        </router-link>

        <!-- Nav Links (Desktop) -->
        <nav class="hidden md:flex space-x-6">
          <router-link to="/" class="text-gray-900 hover:text-gray-800 transition">Home</router-link>
          <router-link to="/adoption" class="text-gray-900 hover:text-gray-800 transition">Adopt</router-link>

          <button @click="scrollToSection('about')" class="text-gray-900 hover:text-gray-800 transition">
            About Us
          </button>
          <button @click="scrollToSection('faq')" class="text-gray-900 hover:text-gray-800 transition">FAQ</button>

          <router-link to="/donate" class="text-gray-900 hover:text-gray-800 transition">Donate</router-link>
          <router-link to="/dashboard" class="text-gray-900 hover:text-gray-800 transition">Dashboard</router-link>
          <router-link to="/all-pages" class="text-gray-900 hover:text-gray-800 transition">Semua Halaman</router-link>
        </nav>

        <!-- Right Side (Desktop) -->
        <div class="hidden md:flex items-center space-x-4">

          <!-- BELUM LOGIN -->
          <template v-if="!isLoggedIn">
          <router-link
            to="/login"
            class="px-4 py-1.5 bg-[#ED8B3C] text-white rounded-full hover:bg-orange-600 transition shadow-md"
          >
            Log in
          </router-link>

          <router-link
            to="/sign-up"
            class="px-4 py-1.5 border border-[#ED8B3C] text-[#ED8B3C] rounded-full hover:bg-[#ED8B3C] hover:text-white transition"
          >
            Sign up
          </router-link>
        </template>

          <!-- SUDAH LOGIN -->
          <template v-else>
            <div class="relative group flex items-center space-x-2">
              <img
                :src="user?.profile_image || '/images/home/Cat 9.jpg'"
                class="h-8 w-8 rounded-full object-cover cursor-pointer"
              />
              <span class="text-gray-900 font-medium cursor-pointer">
                {{ user?.name || user?.username || "User" }}
              </span>

              <!-- Dropdown -->
              <div
                class="absolute right-0 top-10 w-36 bg-white rounded-xl shadow-lg border border-gray-100 opacity-0 invisible group-hover:opacity-100 group-hover:visible transition-all duration-300"
              >
                <router-link
                  to="/profile"
                  class="block px-4 py-2 text-gray-700 hover:bg-gray-100 rounded-t-xl"
                >
                  Profile
                </router-link>

                <button
                  @click="handleLogout"
                  class="w-full text-left block px-4 py-2 text-gray-700 hover:bg-gray-100 rounded-b-xl"
                >
                  Logout
                </button>
              </div>
            </div>
          </template>

        </div>

        <!-- Mobile Menu Button -->
        <button @click="mobileOpen = !mobileOpen" class="md:hidden text-gray-700">
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="currentColor" class="w-7 h-7">
            <path
              v-if="!mobileOpen"
              stroke-linecap="round"
              stroke-linejoin="round"
              stroke-width="2"
              d="M4 6h16M4 12h16M4 18h16"
            />
            <path
              v-else
              stroke-linecap="round"
              stroke-linejoin="round"
              stroke-width="2"
              d="M6 18L18 6M6 6l12 12"
            />
          </svg>
        </button>

      </div>
    </div>

    <!-- Mobile Menu -->
    <transition name="slide-fade">
      <div v-if="mobileOpen" class="md:hidden bg-white/30 backdrop-blur-xl border-t border-white/20 shadow-md pb-3">
        <nav class="flex flex-col px-4 py-3 space-y-2">

          <router-link to="/" class="text-gray-900 hover:text-gray-800 transition">Home</router-link>
          <router-link to="/adoption" class="text-gray-900 hover:text-gray-800 transition">Adopt</router-link>

          <button @click="handleMobileClick('about')" class="text-gray-900 text-left hover:text-gray-800 transition">
            About Us
          </button>
          <button @click="handleMobileClick('faq')" class="text-gray-900 text-left hover:text-gray-800 transition">
            FAQ
          </button>

          <router-link to="/donate" class="text-gray-900 hover:text-gray-800 transition">Donate</router-link>
          <router-link to="/dashboard" class="text-gray-900 hover:text-gray-800 transition">Dashboard</router-link>
          <router-link to="/all-pages" class="text-gray-900 hover:text-gray-800 transition">Semua Halaman</router-link>

          <!-- Auth Mobile -->
          <div v-if="!isLoggedIn" class="pt-3 border-t border-black">
            <router-link to="/login" class="block py-2 text-blue-600 font-medium">Login</router-link>
            <router-link to="/sign-up" class="block py-2 text-blue-600 font-medium">Sign Up</router-link>
          </div>

            <div v-else class="pt-3 border-t border-black">
              <router-link to="/profile" class="block py-2 text-gray-800 font-medium">Profile</router-link>
              <button @click="handleLogout" class="block w-full text-left py-2 text-gray-800 font-medium">Logout</button>
            </div>

        </nav>
      </div>
    </transition>
  </header>
</template>

<script setup>
import { ref, computed, onMounted, onUnmounted, watch } from 'vue'
import { useRoute, useRouter } from 'vue-router'
import { useAuth } from "@/composables/useAuth";

const { user, isLoggedIn, logout } = useAuth();
const router = useRouter()
const route = useRoute()

const scrolledDown = ref(true)
const lastScrollY = ref(0)
const mobileOpen = ref(false)

// scroll hide/show navbar
const handleScroll = () => {
  const currentY = window.scrollY
  scrolledDown.value = !(currentY > lastScrollY.value && currentY > 100)
  lastScrollY.value = currentY
}

onMounted(() => {
  window.addEventListener('scroll', handleScroll)
})

onUnmounted(() => {
  window.removeEventListener('scroll', handleScroll)
})

// detect if current page is auth page
const isAuthPage = computed(() => ['/login', '/sign-up'].includes(route.path))

watch(route, () => {
  mobileOpen.value = false
})

const scrollToSection = async (sectionId) => {
  if (route.path !== '/') {
    await router.push({ path: '/', query: { section: sectionId } })
  } else {
    const section = document.getElementById(sectionId)
    if (section) section.scrollIntoView({ behavior: 'smooth', block: 'start' })
  }
}

const handleMobileClick = async (sectionId) => {
  mobileOpen.value = false
  await scrollToSection(sectionId)
}

const handleLogout = async () => {
  logout(); // dari composable — ini clear localStorage + token axios
  router.push('/');
}
</script>

<style scoped>
.slide-fade-enter-active,
.slide-fade-leave-active {
  transition: all 0.3s ease;
}
.slide-fade-enter-from,
.slide-fade-leave-to {
  transform: translateY(-10px);
  opacity: 0;
}
</style>
