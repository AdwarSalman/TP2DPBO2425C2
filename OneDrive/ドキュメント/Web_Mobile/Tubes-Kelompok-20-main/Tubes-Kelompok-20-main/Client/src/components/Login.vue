<template>
  <div class="min-h-screen flex items-center justify-center bg-[#f7f1e8] relative py-10">
    <div
      class="relative bg-[#FCD34D] rounded-2xl shadow-lg w-[340px] sm:w-[400px] p-8 flex flex-col items-center mt-10"
    >
      <img
        src="/images/Asset Login/kucing-oren.png"
        alt="Cat"
        class="absolute right-0 left-0 mx-auto -top-24 w-40 h-auto object-contain z-10"
      />

      <h2 class="mt-8 text-2xl font-bold text-gray-900 text-center">WELCOME BACK</h2>
      <p class="text-gray-800 mt-2 text-sm">Log in your account</p>

      <form class="mt-6 w-full flex flex-col space-y-4" @submit.prevent="handleLogin">
        <input
          type="email"
          v-model="email"
          placeholder="Enter your email"
          required
          class="w-full px-4 py-2 rounded-lg bg-white border border-gray-300 text-gray-800 focus:outline-none focus:ring-2 focus:ring-orange-500"
        />
        <input
          type="password"
          v-model="password"
          placeholder="Enter your password"
          required
          class="w-full px-4 py-2 rounded-lg bg-white border border-gray-300 text-gray-800 focus:outline-none focus:ring-2 focus:ring-orange-500"
        />
        <button
          type="submit"
          :disabled="isLoading"
          class="w-full py-2 bg-white text-gray-900 font-bold rounded-lg hover:bg-gray-100 transition disabled:opacity-50"
        >
          {{ isLoading ? "Loading..." : "LOGIN" }}
        </button>
      </form>

      <p class="mt-4 text-sm text-gray-900">
        New User?
        <router-link to="/sign-up" class="font-semibold hover:underline">Sign up</router-link>
      </p>
    </div>
  </div>
</template>

<script setup>
import { ref } from "vue";
import { useRouter } from "vue-router";
import { AuthApi } from "@/api/authApi";
import { useAuth } from "@/composables/useAuth";

const router = useRouter();
const { setAuth } = useAuth();

const email = ref("");
const password = ref("");
const isLoading = ref(false);

const handleLogin = async () => {
  isLoading.value = true;
  try {
    // Panggil API
    const res = await AuthApi.login({
      email: email.value,
      password: password.value,
    });

    const { token, user } = res.data;

    if (token && user) {
      // Simpan state login
      setAuth(user, token);
      alert("Login Berhasil!");
      router.push("/"); // Pindah ke halaman Home
    } else {
      throw new Error("Respon server tidak valid");
    }

  } catch (err) {
    console.error("Login error:", err);
    const msg = err.response?.data?.error || "Gagal Login, periksa email/password.";
    alert(msg);
  } finally {
    isLoading.value = false;
  }
};
</script>