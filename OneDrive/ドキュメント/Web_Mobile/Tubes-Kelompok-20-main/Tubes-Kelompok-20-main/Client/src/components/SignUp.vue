<template>
  <div
    class="min-h-screen w-full bg-[#f7f1e8] bg-repeat"
    :style="{ backgroundSize: '60px' }"
  >
    <Navbar />

    <div class="flex justify-center items-start pt-20 relative">
      <img
        :src="catImage"
        alt="cat"
        class="absolute top-8 hidden lg:block w-48 object-contain z-10"
      />

      <div
        class="bg-[#FCD34D] w-[450px] rounded-xl shadow-lg px-8 pt-10 pb-8 text-center relative mt-10 z-20"
      >
        <h2 class="font-bold text-2xl mb-2 text-gray-900">CREATE ACCOUNT</h2>
        <p class="text-gray-800 text-sm mb-6">Join our community today</p>

        <div class="flex items-center justify-center gap-3 mb-6">
          <span class="h-px bg-gray-400 w-full"></span>
        </div>

        <form @submit.prevent="handleSignup" class="flex flex-col gap-4">
          <div v-for="field in formFields" :key="field.model" class="text-left">
            <input
              :type="field.type"
              v-model="formData[field.model]"
              :placeholder="field.placeholder"
              class="w-full px-4 py-3 rounded-lg bg-white border border-gray-300 text-gray-800 placeholder-gray-500 outline-none focus:ring-2 focus:ring-orange-500 focus:border-transparent transition"
              required
            />
          </div>

          <button
            type="submit"
            :disabled="isLoading"
            class="w-full mt-4 bg-white text-gray-600 font-bold py-3 rounded-lg hover:bg-gray-800 hover:text-white transition shadow-md disabled:opacity-50"
          >
            {{ isLoading ? "CREATING ACCOUNT..." : "CREATE ACCOUNT" }}
          </button>
        </form>

        <p class="text-sm mt-6 text-gray-800">
          Already have an account?
          <router-link
            to="/login"
            class="font-bold underline text-gray-900 hover:text-black"
          >
            Login
          </router-link>
        </p>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router'
import { AuthApi } from "@/api/authApi.js"
// Import Navbar jika ada, jika tidak komen baris ini
import Navbar from '@/components/navbar.vue'

const router = useRouter()
const isLoading = ref(false)

// --- 1. DEFINISI DATA (Ini yang sebelumnya hilang!) ---
const catImage = "/images/Asset Signup/kucing-report-button.png" // Pastikan file ini ada di public/images/Asset Signup/

const socialButtons = [
  { name: 'google', label: 'Google', icon: '/images/Asset Signup/google-removebg-preview.png' },
  { name: 'facebook', label: 'Facebook', icon: '/images/Asset Signup/facebook-removebg-preview.png' }
]

const formFields = [
  { type: 'text', model: 'name', placeholder: 'Full Name' },
  { type: 'email', model: 'email', placeholder: 'Email Address' },
  { type: 'password', model: 'password', placeholder: 'Password' }
]

const formData = ref({
  name: '',
  email: '',
  password: ''
})

// --- 2. FUNGSI SIGNUP ---
const handleSignup = async () => {
  if (isLoading.value) return
  isLoading.value = true

  try {
    console.log("Sending data:", formData.value) // Debugging
    const res = await AuthApi.signup(formData.value)

    if (res.data.success) {
      alert("Signup Berhasil! Silakan Login.")
      router.push("/login")
    } else {
      alert("Signup Gagal: " + (res.data.error || "Unknown error"))
    }
  } catch (err) {
    console.error(err)
    const msg = err.response?.data?.error || "Terjadi kesalahan pada server"
    alert(msg)
  } finally {
    isLoading.value = false
  }
}
</script>